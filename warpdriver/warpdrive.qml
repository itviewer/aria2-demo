import QtQuick 2.7
import QtWebSockets 1.1

WebSocket {
    id: socket
    property int id: 0
    property string token: ""
    property var callbacks: ({})

    onTextMessageReceived: {
        var response  = JSON.parse(message)

        if(response["jsonrpc"]){
            if(response["method"]){
                console.log(JSON.stringify(response))
            }else{
                var id = response["id"]
                if(callbacks[id]){
                    callbacks[id](response["result"])
                }
            }
        }else{
            console.error("Invalid json-rpc document")
        }
    }

    function callAsync(method,args,callback){
        args = args || []
        if(typeof args == 'function'){
            callback = args
            args = []
        }

        var request = {
            "jsonrpc":"2.0",
            "id": ++id,
            "method":method,
            "params": token == "" ?  args : ["token:" + token].concat(args)
        }
        if(socket.status == WebSocket.Open){
            console.debug(JSON.stringify(request))
            socket.sendTextMessage(JSON.stringify(request))
            callbacks[id] = callback
        }
    }

    function addUri(args,callback){
        callAsync("aria2.addUri",args,callback)
    }
    function addTorrent(args,callback){
        callAsync("aria2.addTorrent",args,callback)
    }
    function addMetaLink(args,callback){
        callAsync("aria2.addMetaLink",args,callback)
    }
    function remove(args,callback){
        callAsync("aria2.remove",args,callback)
    }
    function forceRemove(args,callback){
        callAsync("aria2.forceRemove",args,callback)
    }
    function pause(args,callback){
        callAsync("aria2.pause",args,callback)
    }
    function pauseAll(args,callback){
        callAsync("aria2.pauseAll",args,callback)
    }
    function forcePause(args,callback){
        callAsync("aria2.forcePause",args,callback)
    }
    function forcePauseAll(args,callback){
        callAsync("aria2.forcePauseAll",args,callback)
    }
    function unpause(args,callback){
        callAsync("aria2.unpause",args,callback)
    }
    function unpauseAll(args,callback){
        callAsync("aria2.unpauseAll",args,callback)
    }
    function tellStatus(args,callback){
        callAsync("aria2.tellStatus",args,callback)
    }
    function getUris(args,callback){
        callAsync("aria2.getUris",args,callback)
    }
    function getFiles(args,callback){
        callAsync("aria2.getFiles",args,callback)
    }
    function getPeers(args,callback){
        callAsync("aria2.getPeers",args,callback)
    }
    function getServers(args,callback){
        callAsync("aria2.getServers",args,callback)
    }
    function tellActive(args,callback){
        callAsync("aria2.tellActive",args,callback)
    }
    function tellWaiting(args,callback){
        callAsync("aria2.tellWaiting",args,callback)
    }
    function tellStopped(args,callback){
        callAsync("aria2.tellStopped",args,callback)
    }
    function changePosition(args,callback){
        callAsync("aria2.changePosition",args,callback)
    }
    function changeUri(args,callback){
        callAsync("aria2.changeUri",args,callback)
    }
    function getOption(args,callback){
        callAsync("aria2.getOption",args,callback)
    }
    function changeOption(args,callback){
        callAsync("aria2.changeOption",args,callback)
    }
    function getGlobalOption(args,callback){
        callAsync("aria2.getGlobalOption",args,callback)
    }
    function changeGlobalOption(args,callback){
        callAsync("aria2.changeGlobalOption",args,callback)
    }
    function getGlobalStat(args,callback){
        callAsync("aria2.getGlobalStat",args,callback)
    }
    function purgeDownloadResult(args,callback){
        callAsync("aria2.purgeDownloadResult",args,callback)
    }
    function removeDownloadResult(args,callback){
        callAsync("aria2.removeDownloadResult",args,callback)
    }
    function getVersion(args,callback){
        callAsync("aria2.getVersion",args,callback)
    }
    function getSessionInfo(args,callback){
        callAsync("aria2.getSessionInfo",args,callback)
    }
    function shutdown(args,callback){
        callAsync("aria2.shutdown",args,callback)
    }
    function forceShutdown(args,callback){
        callAsync("aria2.forceShutdown",args,callback)
    }
    function saveSession(args,callback){
        callAsync("aria2.saveSession",args,callback)
    }

    function multicall(args,callback){}
    function listMethods(args,callback){
        callAsync("system.listMethods",args,callback)
    }
    function listNotifications(args,callback){
        callAsync("system.listNotifications",args,callback)
    }
}

