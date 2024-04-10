#include "mainwindow.h"

#include <QApplication>
#include <capnp/ez-rpc.h>
#include <prescrit/network/rpc_interface.capnp.h>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    // Before starting any windows, connect to the server
    capnp::EzRpcClient client("127.0.0.1", 6000);
    auto& waitScope = client.getWaitScope();

    RpcService::Client cap = client.getMain<RpcService>();

    auto request = cap.helloRequest();
    request.getRequest().setName("This is a test message from the client!");
    auto promise = request.send();

    auto response = promise.wait(waitScope);

    MainWindow w;
    w.show();

    return a.exec();
}
