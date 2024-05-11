#include "rpcclient.h"

#include "lib/src/prescrit_interface.capnp.h"

Client *Client::instance = nullptr;

const QString Client::kHost_ = "localhost";
const quint32 Client::kPort_ = 6000;

Client::Client()
{
    client_ = nullptr;
}

Client::~Client()
{

    if(client_ != nullptr)
        delete client_;
}

void Client::connect()
{

    // If there isn't an instance already
    // created, then abandon the
    // connection attempt
    if(instance == nullptr)
        return;

    // If there's already a connected
    // client, then delete it before
    // creating a new connection
    if(client_ != nullptr)
    {

        qDebug() << "Deleting the current connection";
        disconnect();
    }

    qDebug() << "Creating a new client connection";
    client_ = new capnp::EzRpcClient(kHost_.toStdString(), kPort_);
}

void Client::disconnect()
{

    delete client_;
}

Client *Client::getInstance()
{

    if(instance == nullptr)
    {

        qDebug() << "Creating a new Client instance";
        instance = new Client();
        instance->connect();
    }

    return instance;
}

bool Client::checkConnectionStatus()
{

    try {

        auto promise = client_->getMain<PrescritCore>().echoRequest().send();
        promise.wait(client_->getWaitScope());
    } catch(kj::Exception& e) {

        return false;
    }

    return true;
}

bool Client::createUser(
        const QString &fNameParam,
        const QString &lNameParam,
        const QString &uNameParam,
        const QString &passParam
        )
{

    capnp::MallocMessageBuilder messageBuilder;
    Serializers::User::Builder userBuilder = messageBuilder.initRoot<Serializers::User>();

    userBuilder.setFirstName(fNameParam.toStdString());
    userBuilder.setLastName(lNameParam.toStdString());
    userBuilder.setUsername(uNameParam.toStdString());
    userBuilder.setPassword(passParam.toStdString());

    auto req = client_->getMain<PrescritCore>().createUserRequest();
    req.setUser(userBuilder);

    auto result = req.send().wait(client_->getWaitScope());

    return result.getStatus();
}

bool Client::checkUsernameAvailable(const QString &uName)
{

    auto promise = client_->getMain<PrescritCore>().checkUsernameAvailableRequest();
    promise.setName(uName.toStdString());
    auto result = promise.send().wait(client_->getWaitScope());

    return result.getStatus();
}
