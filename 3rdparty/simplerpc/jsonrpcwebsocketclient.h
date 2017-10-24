#ifndef JSONRPCWEBSOCKETCLIENT_H
#define JSONRPCWEBSOCKETCLIENT_H

#include <QObject>
#include <QHash>
#include <functional>

class QWebSocket;

class JsonRpcWebSocketClient : public QObject
{
    Q_OBJECT
public:
    explicit JsonRpcWebSocketClient(QObject *parent = nullptr);

    void connectToServer(const QUrl &url);
    bool isConnected();

    void setToken(const QString &secret);

    void callAsync(const QString &interface,const QString &method,const QVariantList &args,
              std::function<void(QVariant)> callback = nullptr);
    void callAsync(const QString &interface,const QString &method,
              std::function<void(QVariant)> callback = nullptr);

signals:
    void aboutToClose();
    void connected();
    void disconnected();

    void error(const QString &error) const;

public slots:
private slots:
    void onTextMessageReceived(const QString &message);
private:
    QWebSocket *webSocket;
    quint32 m_id = 0;
    bool m_connected = false;
    QString m_token = "";
    QHash<int, std::function<void(QVariant)>> m_callbacks;
};

#endif // JSONRPCWEBSOCKETCLIENT_H
