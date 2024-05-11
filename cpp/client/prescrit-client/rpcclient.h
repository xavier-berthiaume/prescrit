#ifndef RPCCLIENT_H
#define RPCCLIENT_H

#include <QString>
#include <QDebug>

#include <capnp/ez-rpc.h>


class Client final {
    static Client *instance;

    static const QString kHost_;
    static const quint32 kPort_;

    Client();
    ~Client();

    capnp::EzRpcClient *client_;

public:
    static Client *getInstance();

    bool checkConnectionStatus();

    // Creates an instance of the capnp client connection
    void connect();

    // Destroys the instance of the capnp client connection
    void disconnect();

    bool createUser(
        const QString&,
        const QString&,
        const QString&,
        const QString&
    );

};

#endif // RPCCLIENT_H
