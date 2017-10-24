#ifndef WARPDRIVE_H
#define WARPDRIVE_H

#if defined(WARPDRIVE_LIBRARY)
#  define WARPDRIVESHARED_EXPORT Q_DECL_EXPORT
#else
#  define WARPDRIVESHARED_EXPORT Q_DECL_IMPORT
#endif

#include <functional>
#include <QObject>
#include <QUrl>

class JsonRpcWebSocketClient;

class WARPDRIVESHARED_EXPORT WarpDrive : public QObject
{
    Q_OBJECT
public:
    WarpDrive(QObject *parent = nullptr);

    bool isConnected();
    void connectToServer(const QUrl &url);
    void setToken(const QString &secret);

    void addUri(const QVariantList &args,std::function<void(QVariant)> callback = nullptr);
    void addTorrent(const QVariantList &args,std::function<void(QVariant)> callback = nullptr);
    void addMetaLink(const QVariantList &args,std::function<void(QVariant)> callback = nullptr);
    void remove(const QVariantList &args,std::function<void(QVariant)> callback = nullptr);
    void forceRemove(const QVariantList &args,std::function<void(QVariant)> callback = nullptr);
    void pause(const QVariantList &args,std::function<void(QVariant)> callback = nullptr);

    void pauseAll(std::function<void(QVariant)> callback = nullptr);

    void forcePause(const QVariantList &args,std::function<void(QVariant)> callback = nullptr);

    void forcePauseAll(std::function<void(QVariant)> callback = nullptr);

    void unpause(const QVariantList &args,std::function<void(QVariant)> callback = nullptr);

    void unpauseAll(std::function<void(QVariant)> callback = nullptr);

    void tellStatus(const QVariantList &args,std::function<void(QVariant)> callback = nullptr);
    void getUris(const QVariantList &args,std::function<void(QVariant)> callback = nullptr);
    void getFiles(const QVariantList &args,std::function<void(QVariant)> callback = nullptr);
    void getPeers(const QVariantList &args,std::function<void(QVariant)> callback = nullptr);
    void getServers(const QVariantList &args,std::function<void(QVariant)> callback = nullptr);

    void tellActive(const QVariantList &args,std::function<void(QVariant)> callback = nullptr);
    void tellActive(std::function<void(QVariant)> callback = nullptr);

    void tellWaiting(const QVariantList &args,std::function<void(QVariant)> callback = nullptr);
    void tellStopped(const QVariantList &args,std::function<void(QVariant)> callback = nullptr);
    void changePosition(const QVariantList &args,std::function<void(QVariant)> callback = nullptr);
    void changeUri(const QVariantList &args,std::function<void(QVariant)> callback = nullptr);
    void getOption(const QVariantList &args,std::function<void(QVariant)> callback = nullptr);
    void changeOption(const QVariantList &args,std::function<void(QVariant)> callback = nullptr);

    void getGlobalOption(std::function<void(QVariant)> callback = nullptr);
    void changeGlobalOption(const QVariantList &args,std::function<void(QVariant)> callback = nullptr);

    void getGlobalStat(std::function<void(QVariant)> callback = nullptr);
    void purgeDownloadResult(std::function<void(QVariant)> callback = nullptr);

    void removeDownloadResult(const QVariantList &args,std::function<void(QVariant)> callback = nullptr);

    void getVersion(std::function<void(QVariant)> callback = nullptr);
    void getSessionInfo(std::function<void(QVariant)> callback = nullptr);
    void shutdown(std::function<void(QVariant)> callback = nullptr);
    void forceShutdown(std::function<void(QVariant)> callback = nullptr);
    void saveSession(std::function<void(QVariant)> callback = nullptr);

    void multicall(const QVariantList &args,std::function<void(QVariant)> callback = nullptr);
    void listMethods(std::function<void(QVariant)> callback = nullptr);
    void listNotifications(std::function<void(QVariant)> callback = nullptr);

signals:
    void aboutToClose();
    void connected();
    void disconnected();

    void error(const QString &error) const;
private:
    JsonRpcWebSocketClient *rpcClient;
};

#endif // WARPDRIVE_H
