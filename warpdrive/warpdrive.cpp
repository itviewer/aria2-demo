#include "warpdrive.h"
#include "jsonrpcwebsocketclient.h"
#include <QDebug>

WarpDrive::WarpDrive(QObject *parent)
    :QObject(parent)
{
    rpcClient = new JsonRpcWebSocketClient(parent);

    connect(rpcClient,&JsonRpcWebSocketClient::aboutToClose,this,&WarpDrive::aboutToClose);
    connect(rpcClient,&JsonRpcWebSocketClient::connected,this,&WarpDrive::connected);
    connect(rpcClient,&JsonRpcWebSocketClient::disconnected,this,&WarpDrive::disconnected);
    connect(rpcClient,&JsonRpcWebSocketClient::error,this,&WarpDrive::error);
}

bool WarpDrive::isConnected()
{
    return rpcClient->isConnected();
}

void WarpDrive::connectToServer(const QUrl &url)
{
    rpcClient->connectToServer(url);
}

void WarpDrive::setToken(const QString &secret)
{
    rpcClient->setToken(secret);
}

void WarpDrive::addUri(const QVariantList &args, std::function<void (QVariant)> callback)
{
    rpcClient->callAsync("aria2","addUri",args,callback);
}

void WarpDrive::addTorrent(const QVariantList &args, std::function<void (QVariant)> callback)
{
    rpcClient->callAsync("aria2","addTorrent",args,callback);
}

void WarpDrive::addMetaLink(const QVariantList &args, std::function<void (QVariant)> callback)
{
    rpcClient->callAsync("aria2","addMetaLink",args,callback);
}

void WarpDrive::remove(const QVariantList &args, std::function<void (QVariant)> callback)
{
    rpcClient->callAsync("aria2","remove",args,callback);
}

void WarpDrive::forceRemove(const QVariantList &args, std::function<void (QVariant)> callback)
{
    rpcClient->callAsync("aria2","forceRemove",args,callback);
}

void WarpDrive::pause(const QVariantList &args, std::function<void (QVariant)> callback)
{
    rpcClient->callAsync("aria2","pause",args,callback);
}

void WarpDrive::pauseAll(std::function<void (QVariant)> callback)
{
    rpcClient->callAsync("aria2","pauseAll",callback);
}

void WarpDrive::forcePause(const QVariantList &args, std::function<void (QVariant)> callback)
{
    rpcClient->callAsync("aria2","forcePause",args,callback);
}

void WarpDrive::forcePauseAll(std::function<void (QVariant)> callback)
{
    rpcClient->callAsync("aria2","forcePauseAll",callback);
}

void WarpDrive::unpause(const QVariantList &args, std::function<void (QVariant)> callback)
{
    rpcClient->callAsync("aria2","unpause",args,callback);
}

void WarpDrive::unpauseAll(std::function<void (QVariant)> callback)
{
    rpcClient->callAsync("aria2","unpauseAll",callback);
}

void WarpDrive::tellStatus(const QVariantList &args, std::function<void (QVariant)> callback)
{
    rpcClient->callAsync("aria2","tellStatus",args,callback);
}

void WarpDrive::getUris(const QVariantList &args, std::function<void (QVariant)> callback)
{
    rpcClient->callAsync("aria2","getUris",args,callback);
}

void WarpDrive::getFiles(const QVariantList &args, std::function<void (QVariant)> callback)
{
    rpcClient->callAsync("aria2","getFiles",args,callback);
}

void WarpDrive::getPeers(const QVariantList &args, std::function<void (QVariant)> callback)
{
    rpcClient->callAsync("aria2","getPeers",args,callback);
}

void WarpDrive::getServers(const QVariantList &args, std::function<void (QVariant)> callback)
{
    rpcClient->callAsync("aria2","getServers",args,callback);
}

void WarpDrive::tellActive(const QVariantList &args, std::function<void (QVariant)> callback)
{
    rpcClient->callAsync("aria2","tellActive",args,callback);
}

void WarpDrive::tellActive(std::function<void (QVariant)> callback)
{
    rpcClient->callAsync("aria2","tellActive",callback);
}

void WarpDrive::tellWaiting(const QVariantList &args, std::function<void (QVariant)> callback)
{
    rpcClient->callAsync("aria2","tellWaiting",args,callback);
}

void WarpDrive::tellStopped(const QVariantList &args, std::function<void (QVariant)> callback)
{
    rpcClient->callAsync("aria2","tellStopped",args,callback);
}

void WarpDrive::changePosition(const QVariantList &args, std::function<void (QVariant)> callback)
{
    rpcClient->callAsync("aria2","changePosition",args,callback);
}

void WarpDrive::changeUri(const QVariantList &args, std::function<void (QVariant)> callback)
{
    rpcClient->callAsync("aria2","changeUri",args,callback);
}

void WarpDrive::getOption(const QVariantList &args, std::function<void (QVariant)> callback)
{
    rpcClient->callAsync("aria2","getOption",args,callback);
}

void WarpDrive::changeOption(const QVariantList &args, std::function<void (QVariant)> callback)
{
    rpcClient->callAsync("aria2","changeOption",args,callback);
}

void WarpDrive::getGlobalOption(std::function<void (QVariant)> callback)
{
    rpcClient->callAsync("aria2","getGlobalOption",callback);
}

void WarpDrive::changeGlobalOption(const QVariantList &args, std::function<void (QVariant)> callback)
{
    rpcClient->callAsync("aria2","changeGlobalOption",args,callback);
}

void WarpDrive::getGlobalStat(std::function<void (QVariant)> callback)
{
    rpcClient->callAsync("aria2","getGlobalStat",callback);
}

void WarpDrive::purgeDownloadResult(std::function<void (QVariant)> callback)
{
    rpcClient->callAsync("aria2","purgeDownloadResult",callback);
}

void WarpDrive::removeDownloadResult(const QVariantList &args, std::function<void (QVariant)> callback)
{
    rpcClient->callAsync("aria2","removeDownloadResult",args,callback);
}

void WarpDrive::getVersion(std::function<void (QVariant)> callback)
{
    rpcClient->callAsync("aria2","getVersion",callback);
}

void WarpDrive::getSessionInfo(std::function<void (QVariant)> callback)
{
    rpcClient->callAsync("aria2","getSessionInfo",callback);
}

void WarpDrive::shutdown(std::function<void (QVariant)> callback)
{
    rpcClient->callAsync("aria2","shutdown",callback);
}

void WarpDrive::forceShutdown(std::function<void (QVariant)> callback)
{
    rpcClient->callAsync("aria2","forceShutdown",callback);
}

void WarpDrive::saveSession(std::function<void (QVariant)> callback)
{
    rpcClient->callAsync("aria2","saveSession",callback);
}

void WarpDrive::multicall(const QVariantList &args, std::function<void (QVariant)> callback)
{
    rpcClient->callAsync("system","multicall",args,callback);
}

void WarpDrive::listMethods(std::function<void (QVariant)> callback)
{
    rpcClient->callAsync("system","listMethods",callback);
}

void WarpDrive::listNotifications(std::function<void (QVariant)> callback)
{
    rpcClient->callAsync("system","listNotifications",callback);
}
