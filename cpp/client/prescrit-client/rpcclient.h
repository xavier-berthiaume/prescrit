#ifndef RPCCLIENT_H
#define RPCCLIENT_H

#include <QString>

#include <capnp/ez-rpc.h>

#include "lib/src/prescrit_interface.capnp.h"

class Client final {
    static Client *instance;

    static const QString kHost_;
    static const quint32 kPort_;

    Client();
    ~Client();

    // Creates an instance of the capnp client connection
    void connect();

    // Destroys the instance of the capnp client connection
    void disconnect();


    capnp::EzRpcClient *client_;

public:
    static Client *getInstance();

    bool checkConnectionStatus();

    bool createUser(
        const QString&,
        const QString&,
        const QString&,
        const QString&
    );

};

#endif // RPCCLIENT_H
