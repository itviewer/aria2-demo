#include "jsonrpcwebsocketclient.h"
#include <QWebSocket>
#include <QJsonDocument>
#include <QJsonObject>
#include <QDebug>
#include <QtConcurrent>

JsonRpcWebSocketClient::JsonRpcWebSocketClient(QObject *parent)
    : QObject(parent)
{
    webSocket = new QWebSocket("",QWebSocketProtocol::VersionLatest,parent);

    connect(webSocket,&QWebSocket::aboutToClose,this,&JsonRpcWebSocketClient::aboutToClose);
    connect(webSocket,&QWebSocket::connected,this,[this](){
        m_connected = true;
        emit connected();
    });
    connect(webSocket,&QWebSocket::disconnected,this,[this](){
        m_connected = false;
        emit disconnected();
    });
    connect(webSocket, static_cast<void(QWebSocket::*)(QAbstractSocket::SocketError)>(&QWebSocket::error),
            [this](){
        emit error(webSocket->errorString());
    });
    connect(webSocket,&QWebSocket::textMessageReceived,this,&JsonRpcWebSocketClient::onTextMessageReceived);

}

void JsonRpcWebSocketClient::connectToServer(const QUrl &url)
{
    webSocket->open(url);
}

bool JsonRpcWebSocketClient::isConnected()
{
    return m_connected;
}

void JsonRpcWebSocketClient::setToken(const QString &secret)
{
    m_token = secret;
}

void JsonRpcWebSocketClient::callAsync(const QString &interface, const QString &method,const QVariantList &args,
                                  std::function<void (QVariant)> callback)
{
    QVariantMap map;
    map["method"] = interface + "." + method;
    map["jsonrpc"] = "2.0";
    map["params"] = m_token.isEmpty() ? args : QVariantList({QString("token:%1").arg(m_token)}) + args;
    map["id"] = m_id > 4294967294 ? 1 : ++m_id;

    QByteArray data = QJsonDocument::fromVariant(map).toJson(QJsonDocument::Compact);

    if (m_connected) {
        webSocket->sendBinaryMessage(data);
        if(callback){
            m_callbacks.insert(m_id,callback);
        }
    } else {
        qWarning("WebSocket not connected");
    }
}

void JsonRpcWebSocketClient::callAsync(const QString &interface, const QString &method, std::function<void (QVariant)> callback)
{
    callAsync(interface,method,QVariantList(),callback);
}

void JsonRpcWebSocketClient::onTextMessageReceived(const QString &message)
{
    QJsonParseError parseError;
    QJsonDocument doc = QJsonDocument::fromJson(message.toUtf8(), &parseError);

    if (parseError.error != QJsonParseError::NoError) {
        qWarning("Error parsing json document");
        return;
    }

    if (!doc.object().contains("jsonrpc")) {
        qWarning("Invalid json-rpc document");
        return;
    }

    if (doc.object().contains("method")) {
        qDebug() << "111111111111111111111 \n" ;
    }else{
        if (!doc.object().contains("id")) {
            qWarning("Invalid result");
            return;
        }

        int id = doc.object().value("id").toInt();

        if (m_callbacks.contains(id)) {
            QtConcurrent::run(m_callbacks.value(id), doc.object().value("result").toVariant());
            m_callbacks.remove(id);//防止无限增大
        }
    }
}
