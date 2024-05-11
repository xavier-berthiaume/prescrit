// Generated by Cap'n Proto compiler, DO NOT EDIT
// source: prescrit_interface.capnp

#pragma once

#include <capnp/generated-header-support.h>
#include <kj/windows-sanity.h>
#if !CAPNP_LITE
#include <capnp/capability.h>
#endif  // !CAPNP_LITE

#ifndef CAPNP_VERSION
#error "CAPNP_VERSION is not defined, is capnp/generated-header-support.h missing?"
#elif CAPNP_VERSION != 1001000
#error "Version mismatch between generated code and library headers.  You must use the same version of the Cap'n Proto compiler and library."
#endif

#include "pharmacy_user.capnp.h"

CAPNP_BEGIN_HEADER

namespace capnp {
namespace schemas {

CAPNP_DECLARE_SCHEMA(b88ac5584f59652e);
CAPNP_DECLARE_SCHEMA(b2b9005c5d25dc42);
CAPNP_DECLARE_SCHEMA(ea98825e55d643a4);
CAPNP_DECLARE_SCHEMA(ec1cb1e8f3f4edad);
CAPNP_DECLARE_SCHEMA(9c3b4f2dcf2b18b8);
CAPNP_DECLARE_SCHEMA(98870d9cabe55f17);
CAPNP_DECLARE_SCHEMA(e0a358e6dc1e8774);

}  // namespace schemas
}  // namespace capnp


struct PrescritCore {
  PrescritCore() = delete;

#if !CAPNP_LITE
  class Client;
  class Server;
#endif  // !CAPNP_LITE

  struct EchoParams;
  struct EchoResults;
  struct CreateUserParams;
  struct CreateUserResults;
  struct CheckUsernameAvailableParams;
  struct CheckUsernameAvailableResults;

  #if !CAPNP_LITE
  struct _capnpPrivate {
    CAPNP_DECLARE_INTERFACE_HEADER(b88ac5584f59652e)
    static constexpr ::capnp::_::RawBrandedSchema const* brand() { return &schema->defaultBrand; }
  };
  #endif  // !CAPNP_LITE
};

struct PrescritCore::EchoParams {
  EchoParams() = delete;

  class Reader;
  class Builder;
  class Pipeline;

  struct _capnpPrivate {
    CAPNP_DECLARE_STRUCT_HEADER(b2b9005c5d25dc42, 0, 0)
    #if !CAPNP_LITE
    static constexpr ::capnp::_::RawBrandedSchema const* brand() { return &schema->defaultBrand; }
    #endif  // !CAPNP_LITE
  };
};

struct PrescritCore::EchoResults {
  EchoResults() = delete;

  class Reader;
  class Builder;
  class Pipeline;

  struct _capnpPrivate {
    CAPNP_DECLARE_STRUCT_HEADER(ea98825e55d643a4, 0, 0)
    #if !CAPNP_LITE
    static constexpr ::capnp::_::RawBrandedSchema const* brand() { return &schema->defaultBrand; }
    #endif  // !CAPNP_LITE
  };
};

struct PrescritCore::CreateUserParams {
  CreateUserParams() = delete;

  class Reader;
  class Builder;
  class Pipeline;

  struct _capnpPrivate {
    CAPNP_DECLARE_STRUCT_HEADER(ec1cb1e8f3f4edad, 0, 1)
    #if !CAPNP_LITE
    static constexpr ::capnp::_::RawBrandedSchema const* brand() { return &schema->defaultBrand; }
    #endif  // !CAPNP_LITE
  };
};

struct PrescritCore::CreateUserResults {
  CreateUserResults() = delete;

  class Reader;
  class Builder;
  class Pipeline;

  struct _capnpPrivate {
    CAPNP_DECLARE_STRUCT_HEADER(9c3b4f2dcf2b18b8, 1, 0)
    #if !CAPNP_LITE
    static constexpr ::capnp::_::RawBrandedSchema const* brand() { return &schema->defaultBrand; }
    #endif  // !CAPNP_LITE
  };
};

struct PrescritCore::CheckUsernameAvailableParams {
  CheckUsernameAvailableParams() = delete;

  class Reader;
  class Builder;
  class Pipeline;

  struct _capnpPrivate {
    CAPNP_DECLARE_STRUCT_HEADER(98870d9cabe55f17, 0, 1)
    #if !CAPNP_LITE
    static constexpr ::capnp::_::RawBrandedSchema const* brand() { return &schema->defaultBrand; }
    #endif  // !CAPNP_LITE
  };
};

struct PrescritCore::CheckUsernameAvailableResults {
  CheckUsernameAvailableResults() = delete;

  class Reader;
  class Builder;
  class Pipeline;

  struct _capnpPrivate {
    CAPNP_DECLARE_STRUCT_HEADER(e0a358e6dc1e8774, 1, 0)
    #if !CAPNP_LITE
    static constexpr ::capnp::_::RawBrandedSchema const* brand() { return &schema->defaultBrand; }
    #endif  // !CAPNP_LITE
  };
};

// =======================================================================================

#if !CAPNP_LITE
class PrescritCore::Client
    : public virtual ::capnp::Capability::Client {
public:
  typedef PrescritCore Calls;
  typedef PrescritCore Reads;

  Client(decltype(nullptr));
  explicit Client(::kj::Own< ::capnp::ClientHook>&& hook);
  template <typename _t, typename = ::kj::EnableIf< ::kj::canConvert<_t*, Server*>()>>
  Client(::kj::Own<_t>&& server);
  template <typename _t, typename = ::kj::EnableIf< ::kj::canConvert<_t*, Client*>()>>
  Client(::kj::Promise<_t>&& promise);
  Client(::kj::Exception&& exception);
  Client(Client&) = default;
  Client(Client&&) = default;
  Client& operator=(Client& other);
  Client& operator=(Client&& other);

  ::capnp::Request< ::PrescritCore::EchoParams,  ::PrescritCore::EchoResults> echoRequest(
      ::kj::Maybe< ::capnp::MessageSize> sizeHint = nullptr);
  ::capnp::Request< ::PrescritCore::CreateUserParams,  ::PrescritCore::CreateUserResults> createUserRequest(
      ::kj::Maybe< ::capnp::MessageSize> sizeHint = nullptr);
  ::capnp::Request< ::PrescritCore::CheckUsernameAvailableParams,  ::PrescritCore::CheckUsernameAvailableResults> checkUsernameAvailableRequest(
      ::kj::Maybe< ::capnp::MessageSize> sizeHint = nullptr);

protected:
  Client() = default;
};

class PrescritCore::Server
    : public virtual ::capnp::Capability::Server {
public:
  typedef PrescritCore Serves;

  ::capnp::Capability::Server::DispatchCallResult dispatchCall(
      uint64_t interfaceId, uint16_t methodId,
      ::capnp::CallContext< ::capnp::AnyPointer, ::capnp::AnyPointer> context)
      override;

protected:
  typedef  ::PrescritCore::EchoParams EchoParams;
  typedef  ::PrescritCore::EchoResults EchoResults;
  typedef ::capnp::CallContext<EchoParams, EchoResults> EchoContext;
  virtual ::kj::Promise<void> echo(EchoContext context);
  typedef  ::PrescritCore::CreateUserParams CreateUserParams;
  typedef  ::PrescritCore::CreateUserResults CreateUserResults;
  typedef ::capnp::CallContext<CreateUserParams, CreateUserResults> CreateUserContext;
  virtual ::kj::Promise<void> createUser(CreateUserContext context);
  typedef  ::PrescritCore::CheckUsernameAvailableParams CheckUsernameAvailableParams;
  typedef  ::PrescritCore::CheckUsernameAvailableResults CheckUsernameAvailableResults;
  typedef ::capnp::CallContext<CheckUsernameAvailableParams, CheckUsernameAvailableResults> CheckUsernameAvailableContext;
  virtual ::kj::Promise<void> checkUsernameAvailable(CheckUsernameAvailableContext context);

  inline  ::PrescritCore::Client thisCap() {
    return ::capnp::Capability::Server::thisCap()
        .template castAs< ::PrescritCore>();
  }

  ::capnp::Capability::Server::DispatchCallResult dispatchCallInternal(
      uint16_t methodId,
      ::capnp::CallContext< ::capnp::AnyPointer, ::capnp::AnyPointer> context);
};
#endif  // !CAPNP_LITE

class PrescritCore::EchoParams::Reader {
public:
  typedef EchoParams Reads;

  Reader() = default;
  inline explicit Reader(::capnp::_::StructReader base): _reader(base) {}

  inline ::capnp::MessageSize totalSize() const {
    return _reader.totalSize().asPublic();
  }

#if !CAPNP_LITE
  inline ::kj::StringTree toString() const {
    return ::capnp::_::structString(_reader, *_capnpPrivate::brand());
  }
#endif  // !CAPNP_LITE

private:
  ::capnp::_::StructReader _reader;
  template <typename, ::capnp::Kind>
  friend struct ::capnp::ToDynamic_;
  template <typename, ::capnp::Kind>
  friend struct ::capnp::_::PointerHelpers;
  template <typename, ::capnp::Kind>
  friend struct ::capnp::List;
  friend class ::capnp::MessageBuilder;
  friend class ::capnp::Orphanage;
};

class PrescritCore::EchoParams::Builder {
public:
  typedef EchoParams Builds;

  Builder() = delete;  // Deleted to discourage incorrect usage.
                       // You can explicitly initialize to nullptr instead.
  inline Builder(decltype(nullptr)) {}
  inline explicit Builder(::capnp::_::StructBuilder base): _builder(base) {}
  inline operator Reader() const { return Reader(_builder.asReader()); }
  inline Reader asReader() const { return *this; }

  inline ::capnp::MessageSize totalSize() const { return asReader().totalSize(); }
#if !CAPNP_LITE
  inline ::kj::StringTree toString() const { return asReader().toString(); }
#endif  // !CAPNP_LITE

private:
  ::capnp::_::StructBuilder _builder;
  template <typename, ::capnp::Kind>
  friend struct ::capnp::ToDynamic_;
  friend class ::capnp::Orphanage;
  template <typename, ::capnp::Kind>
  friend struct ::capnp::_::PointerHelpers;
};

#if !CAPNP_LITE
class PrescritCore::EchoParams::Pipeline {
public:
  typedef EchoParams Pipelines;

  inline Pipeline(decltype(nullptr)): _typeless(nullptr) {}
  inline explicit Pipeline(::capnp::AnyPointer::Pipeline&& typeless)
      : _typeless(kj::mv(typeless)) {}

private:
  ::capnp::AnyPointer::Pipeline _typeless;
  friend class ::capnp::PipelineHook;
  template <typename, ::capnp::Kind>
  friend struct ::capnp::ToDynamic_;
};
#endif  // !CAPNP_LITE

class PrescritCore::EchoResults::Reader {
public:
  typedef EchoResults Reads;

  Reader() = default;
  inline explicit Reader(::capnp::_::StructReader base): _reader(base) {}

  inline ::capnp::MessageSize totalSize() const {
    return _reader.totalSize().asPublic();
  }

#if !CAPNP_LITE
  inline ::kj::StringTree toString() const {
    return ::capnp::_::structString(_reader, *_capnpPrivate::brand());
  }
#endif  // !CAPNP_LITE

private:
  ::capnp::_::StructReader _reader;
  template <typename, ::capnp::Kind>
  friend struct ::capnp::ToDynamic_;
  template <typename, ::capnp::Kind>
  friend struct ::capnp::_::PointerHelpers;
  template <typename, ::capnp::Kind>
  friend struct ::capnp::List;
  friend class ::capnp::MessageBuilder;
  friend class ::capnp::Orphanage;
};

class PrescritCore::EchoResults::Builder {
public:
  typedef EchoResults Builds;

  Builder() = delete;  // Deleted to discourage incorrect usage.
                       // You can explicitly initialize to nullptr instead.
  inline Builder(decltype(nullptr)) {}
  inline explicit Builder(::capnp::_::StructBuilder base): _builder(base) {}
  inline operator Reader() const { return Reader(_builder.asReader()); }
  inline Reader asReader() const { return *this; }

  inline ::capnp::MessageSize totalSize() const { return asReader().totalSize(); }
#if !CAPNP_LITE
  inline ::kj::StringTree toString() const { return asReader().toString(); }
#endif  // !CAPNP_LITE

private:
  ::capnp::_::StructBuilder _builder;
  template <typename, ::capnp::Kind>
  friend struct ::capnp::ToDynamic_;
  friend class ::capnp::Orphanage;
  template <typename, ::capnp::Kind>
  friend struct ::capnp::_::PointerHelpers;
};

#if !CAPNP_LITE
class PrescritCore::EchoResults::Pipeline {
public:
  typedef EchoResults Pipelines;

  inline Pipeline(decltype(nullptr)): _typeless(nullptr) {}
  inline explicit Pipeline(::capnp::AnyPointer::Pipeline&& typeless)
      : _typeless(kj::mv(typeless)) {}

private:
  ::capnp::AnyPointer::Pipeline _typeless;
  friend class ::capnp::PipelineHook;
  template <typename, ::capnp::Kind>
  friend struct ::capnp::ToDynamic_;
};
#endif  // !CAPNP_LITE

class PrescritCore::CreateUserParams::Reader {
public:
  typedef CreateUserParams Reads;

  Reader() = default;
  inline explicit Reader(::capnp::_::StructReader base): _reader(base) {}

  inline ::capnp::MessageSize totalSize() const {
    return _reader.totalSize().asPublic();
  }

#if !CAPNP_LITE
  inline ::kj::StringTree toString() const {
    return ::capnp::_::structString(_reader, *_capnpPrivate::brand());
  }
#endif  // !CAPNP_LITE

  inline bool hasUser() const;
  inline  ::Serializers::User::Reader getUser() const;

private:
  ::capnp::_::StructReader _reader;
  template <typename, ::capnp::Kind>
  friend struct ::capnp::ToDynamic_;
  template <typename, ::capnp::Kind>
  friend struct ::capnp::_::PointerHelpers;
  template <typename, ::capnp::Kind>
  friend struct ::capnp::List;
  friend class ::capnp::MessageBuilder;
  friend class ::capnp::Orphanage;
};

class PrescritCore::CreateUserParams::Builder {
public:
  typedef CreateUserParams Builds;

  Builder() = delete;  // Deleted to discourage incorrect usage.
                       // You can explicitly initialize to nullptr instead.
  inline Builder(decltype(nullptr)) {}
  inline explicit Builder(::capnp::_::StructBuilder base): _builder(base) {}
  inline operator Reader() const { return Reader(_builder.asReader()); }
  inline Reader asReader() const { return *this; }

  inline ::capnp::MessageSize totalSize() const { return asReader().totalSize(); }
#if !CAPNP_LITE
  inline ::kj::StringTree toString() const { return asReader().toString(); }
#endif  // !CAPNP_LITE

  inline bool hasUser();
  inline  ::Serializers::User::Builder getUser();
  inline void setUser( ::Serializers::User::Reader value);
  inline  ::Serializers::User::Builder initUser();
  inline void adoptUser(::capnp::Orphan< ::Serializers::User>&& value);
  inline ::capnp::Orphan< ::Serializers::User> disownUser();

private:
  ::capnp::_::StructBuilder _builder;
  template <typename, ::capnp::Kind>
  friend struct ::capnp::ToDynamic_;
  friend class ::capnp::Orphanage;
  template <typename, ::capnp::Kind>
  friend struct ::capnp::_::PointerHelpers;
};

#if !CAPNP_LITE
class PrescritCore::CreateUserParams::Pipeline {
public:
  typedef CreateUserParams Pipelines;

  inline Pipeline(decltype(nullptr)): _typeless(nullptr) {}
  inline explicit Pipeline(::capnp::AnyPointer::Pipeline&& typeless)
      : _typeless(kj::mv(typeless)) {}

  inline  ::Serializers::User::Pipeline getUser();
private:
  ::capnp::AnyPointer::Pipeline _typeless;
  friend class ::capnp::PipelineHook;
  template <typename, ::capnp::Kind>
  friend struct ::capnp::ToDynamic_;
};
#endif  // !CAPNP_LITE

class PrescritCore::CreateUserResults::Reader {
public:
  typedef CreateUserResults Reads;

  Reader() = default;
  inline explicit Reader(::capnp::_::StructReader base): _reader(base) {}

  inline ::capnp::MessageSize totalSize() const {
    return _reader.totalSize().asPublic();
  }

#if !CAPNP_LITE
  inline ::kj::StringTree toString() const {
    return ::capnp::_::structString(_reader, *_capnpPrivate::brand());
  }
#endif  // !CAPNP_LITE

  inline bool getStatus() const;

private:
  ::capnp::_::StructReader _reader;
  template <typename, ::capnp::Kind>
  friend struct ::capnp::ToDynamic_;
  template <typename, ::capnp::Kind>
  friend struct ::capnp::_::PointerHelpers;
  template <typename, ::capnp::Kind>
  friend struct ::capnp::List;
  friend class ::capnp::MessageBuilder;
  friend class ::capnp::Orphanage;
};

class PrescritCore::CreateUserResults::Builder {
public:
  typedef CreateUserResults Builds;

  Builder() = delete;  // Deleted to discourage incorrect usage.
                       // You can explicitly initialize to nullptr instead.
  inline Builder(decltype(nullptr)) {}
  inline explicit Builder(::capnp::_::StructBuilder base): _builder(base) {}
  inline operator Reader() const { return Reader(_builder.asReader()); }
  inline Reader asReader() const { return *this; }

  inline ::capnp::MessageSize totalSize() const { return asReader().totalSize(); }
#if !CAPNP_LITE
  inline ::kj::StringTree toString() const { return asReader().toString(); }
#endif  // !CAPNP_LITE

  inline bool getStatus();
  inline void setStatus(bool value);

private:
  ::capnp::_::StructBuilder _builder;
  template <typename, ::capnp::Kind>
  friend struct ::capnp::ToDynamic_;
  friend class ::capnp::Orphanage;
  template <typename, ::capnp::Kind>
  friend struct ::capnp::_::PointerHelpers;
};

#if !CAPNP_LITE
class PrescritCore::CreateUserResults::Pipeline {
public:
  typedef CreateUserResults Pipelines;

  inline Pipeline(decltype(nullptr)): _typeless(nullptr) {}
  inline explicit Pipeline(::capnp::AnyPointer::Pipeline&& typeless)
      : _typeless(kj::mv(typeless)) {}

private:
  ::capnp::AnyPointer::Pipeline _typeless;
  friend class ::capnp::PipelineHook;
  template <typename, ::capnp::Kind>
  friend struct ::capnp::ToDynamic_;
};
#endif  // !CAPNP_LITE

class PrescritCore::CheckUsernameAvailableParams::Reader {
public:
  typedef CheckUsernameAvailableParams Reads;

  Reader() = default;
  inline explicit Reader(::capnp::_::StructReader base): _reader(base) {}

  inline ::capnp::MessageSize totalSize() const {
    return _reader.totalSize().asPublic();
  }

#if !CAPNP_LITE
  inline ::kj::StringTree toString() const {
    return ::capnp::_::structString(_reader, *_capnpPrivate::brand());
  }
#endif  // !CAPNP_LITE

  inline bool hasName() const;
  inline  ::capnp::Text::Reader getName() const;

private:
  ::capnp::_::StructReader _reader;
  template <typename, ::capnp::Kind>
  friend struct ::capnp::ToDynamic_;
  template <typename, ::capnp::Kind>
  friend struct ::capnp::_::PointerHelpers;
  template <typename, ::capnp::Kind>
  friend struct ::capnp::List;
  friend class ::capnp::MessageBuilder;
  friend class ::capnp::Orphanage;
};

class PrescritCore::CheckUsernameAvailableParams::Builder {
public:
  typedef CheckUsernameAvailableParams Builds;

  Builder() = delete;  // Deleted to discourage incorrect usage.
                       // You can explicitly initialize to nullptr instead.
  inline Builder(decltype(nullptr)) {}
  inline explicit Builder(::capnp::_::StructBuilder base): _builder(base) {}
  inline operator Reader() const { return Reader(_builder.asReader()); }
  inline Reader asReader() const { return *this; }

  inline ::capnp::MessageSize totalSize() const { return asReader().totalSize(); }
#if !CAPNP_LITE
  inline ::kj::StringTree toString() const { return asReader().toString(); }
#endif  // !CAPNP_LITE

  inline bool hasName();
  inline  ::capnp::Text::Builder getName();
  inline void setName( ::capnp::Text::Reader value);
  inline  ::capnp::Text::Builder initName(unsigned int size);
  inline void adoptName(::capnp::Orphan< ::capnp::Text>&& value);
  inline ::capnp::Orphan< ::capnp::Text> disownName();

private:
  ::capnp::_::StructBuilder _builder;
  template <typename, ::capnp::Kind>
  friend struct ::capnp::ToDynamic_;
  friend class ::capnp::Orphanage;
  template <typename, ::capnp::Kind>
  friend struct ::capnp::_::PointerHelpers;
};

#if !CAPNP_LITE
class PrescritCore::CheckUsernameAvailableParams::Pipeline {
public:
  typedef CheckUsernameAvailableParams Pipelines;

  inline Pipeline(decltype(nullptr)): _typeless(nullptr) {}
  inline explicit Pipeline(::capnp::AnyPointer::Pipeline&& typeless)
      : _typeless(kj::mv(typeless)) {}

private:
  ::capnp::AnyPointer::Pipeline _typeless;
  friend class ::capnp::PipelineHook;
  template <typename, ::capnp::Kind>
  friend struct ::capnp::ToDynamic_;
};
#endif  // !CAPNP_LITE

class PrescritCore::CheckUsernameAvailableResults::Reader {
public:
  typedef CheckUsernameAvailableResults Reads;

  Reader() = default;
  inline explicit Reader(::capnp::_::StructReader base): _reader(base) {}

  inline ::capnp::MessageSize totalSize() const {
    return _reader.totalSize().asPublic();
  }

#if !CAPNP_LITE
  inline ::kj::StringTree toString() const {
    return ::capnp::_::structString(_reader, *_capnpPrivate::brand());
  }
#endif  // !CAPNP_LITE

  inline bool getStatus() const;

private:
  ::capnp::_::StructReader _reader;
  template <typename, ::capnp::Kind>
  friend struct ::capnp::ToDynamic_;
  template <typename, ::capnp::Kind>
  friend struct ::capnp::_::PointerHelpers;
  template <typename, ::capnp::Kind>
  friend struct ::capnp::List;
  friend class ::capnp::MessageBuilder;
  friend class ::capnp::Orphanage;
};

class PrescritCore::CheckUsernameAvailableResults::Builder {
public:
  typedef CheckUsernameAvailableResults Builds;

  Builder() = delete;  // Deleted to discourage incorrect usage.
                       // You can explicitly initialize to nullptr instead.
  inline Builder(decltype(nullptr)) {}
  inline explicit Builder(::capnp::_::StructBuilder base): _builder(base) {}
  inline operator Reader() const { return Reader(_builder.asReader()); }
  inline Reader asReader() const { return *this; }

  inline ::capnp::MessageSize totalSize() const { return asReader().totalSize(); }
#if !CAPNP_LITE
  inline ::kj::StringTree toString() const { return asReader().toString(); }
#endif  // !CAPNP_LITE

  inline bool getStatus();
  inline void setStatus(bool value);

private:
  ::capnp::_::StructBuilder _builder;
  template <typename, ::capnp::Kind>
  friend struct ::capnp::ToDynamic_;
  friend class ::capnp::Orphanage;
  template <typename, ::capnp::Kind>
  friend struct ::capnp::_::PointerHelpers;
};

#if !CAPNP_LITE
class PrescritCore::CheckUsernameAvailableResults::Pipeline {
public:
  typedef CheckUsernameAvailableResults Pipelines;

  inline Pipeline(decltype(nullptr)): _typeless(nullptr) {}
  inline explicit Pipeline(::capnp::AnyPointer::Pipeline&& typeless)
      : _typeless(kj::mv(typeless)) {}

private:
  ::capnp::AnyPointer::Pipeline _typeless;
  friend class ::capnp::PipelineHook;
  template <typename, ::capnp::Kind>
  friend struct ::capnp::ToDynamic_;
};
#endif  // !CAPNP_LITE

// =======================================================================================

#if !CAPNP_LITE
inline PrescritCore::Client::Client(decltype(nullptr))
    : ::capnp::Capability::Client(nullptr) {}
inline PrescritCore::Client::Client(
    ::kj::Own< ::capnp::ClientHook>&& hook)
    : ::capnp::Capability::Client(::kj::mv(hook)) {}
template <typename _t, typename>
inline PrescritCore::Client::Client(::kj::Own<_t>&& server)
    : ::capnp::Capability::Client(::kj::mv(server)) {}
template <typename _t, typename>
inline PrescritCore::Client::Client(::kj::Promise<_t>&& promise)
    : ::capnp::Capability::Client(::kj::mv(promise)) {}
inline PrescritCore::Client::Client(::kj::Exception&& exception)
    : ::capnp::Capability::Client(::kj::mv(exception)) {}
inline  ::PrescritCore::Client& PrescritCore::Client::operator=(Client& other) {
  ::capnp::Capability::Client::operator=(other);
  return *this;
}
inline  ::PrescritCore::Client& PrescritCore::Client::operator=(Client&& other) {
  ::capnp::Capability::Client::operator=(kj::mv(other));
  return *this;
}

#endif  // !CAPNP_LITE
inline bool PrescritCore::CreateUserParams::Reader::hasUser() const {
  return !_reader.getPointerField(
      ::capnp::bounded<0>() * ::capnp::POINTERS).isNull();
}
inline bool PrescritCore::CreateUserParams::Builder::hasUser() {
  return !_builder.getPointerField(
      ::capnp::bounded<0>() * ::capnp::POINTERS).isNull();
}
inline  ::Serializers::User::Reader PrescritCore::CreateUserParams::Reader::getUser() const {
  return ::capnp::_::PointerHelpers< ::Serializers::User>::get(_reader.getPointerField(
      ::capnp::bounded<0>() * ::capnp::POINTERS));
}
inline  ::Serializers::User::Builder PrescritCore::CreateUserParams::Builder::getUser() {
  return ::capnp::_::PointerHelpers< ::Serializers::User>::get(_builder.getPointerField(
      ::capnp::bounded<0>() * ::capnp::POINTERS));
}
#if !CAPNP_LITE
inline  ::Serializers::User::Pipeline PrescritCore::CreateUserParams::Pipeline::getUser() {
  return  ::Serializers::User::Pipeline(_typeless.getPointerField(0));
}
#endif  // !CAPNP_LITE
inline void PrescritCore::CreateUserParams::Builder::setUser( ::Serializers::User::Reader value) {
  ::capnp::_::PointerHelpers< ::Serializers::User>::set(_builder.getPointerField(
      ::capnp::bounded<0>() * ::capnp::POINTERS), value);
}
inline  ::Serializers::User::Builder PrescritCore::CreateUserParams::Builder::initUser() {
  return ::capnp::_::PointerHelpers< ::Serializers::User>::init(_builder.getPointerField(
      ::capnp::bounded<0>() * ::capnp::POINTERS));
}
inline void PrescritCore::CreateUserParams::Builder::adoptUser(
    ::capnp::Orphan< ::Serializers::User>&& value) {
  ::capnp::_::PointerHelpers< ::Serializers::User>::adopt(_builder.getPointerField(
      ::capnp::bounded<0>() * ::capnp::POINTERS), kj::mv(value));
}
inline ::capnp::Orphan< ::Serializers::User> PrescritCore::CreateUserParams::Builder::disownUser() {
  return ::capnp::_::PointerHelpers< ::Serializers::User>::disown(_builder.getPointerField(
      ::capnp::bounded<0>() * ::capnp::POINTERS));
}

inline bool PrescritCore::CreateUserResults::Reader::getStatus() const {
  return _reader.getDataField<bool>(
      ::capnp::bounded<0>() * ::capnp::ELEMENTS);
}

inline bool PrescritCore::CreateUserResults::Builder::getStatus() {
  return _builder.getDataField<bool>(
      ::capnp::bounded<0>() * ::capnp::ELEMENTS);
}
inline void PrescritCore::CreateUserResults::Builder::setStatus(bool value) {
  _builder.setDataField<bool>(
      ::capnp::bounded<0>() * ::capnp::ELEMENTS, value);
}

inline bool PrescritCore::CheckUsernameAvailableParams::Reader::hasName() const {
  return !_reader.getPointerField(
      ::capnp::bounded<0>() * ::capnp::POINTERS).isNull();
}
inline bool PrescritCore::CheckUsernameAvailableParams::Builder::hasName() {
  return !_builder.getPointerField(
      ::capnp::bounded<0>() * ::capnp::POINTERS).isNull();
}
inline  ::capnp::Text::Reader PrescritCore::CheckUsernameAvailableParams::Reader::getName() const {
  return ::capnp::_::PointerHelpers< ::capnp::Text>::get(_reader.getPointerField(
      ::capnp::bounded<0>() * ::capnp::POINTERS));
}
inline  ::capnp::Text::Builder PrescritCore::CheckUsernameAvailableParams::Builder::getName() {
  return ::capnp::_::PointerHelpers< ::capnp::Text>::get(_builder.getPointerField(
      ::capnp::bounded<0>() * ::capnp::POINTERS));
}
inline void PrescritCore::CheckUsernameAvailableParams::Builder::setName( ::capnp::Text::Reader value) {
  ::capnp::_::PointerHelpers< ::capnp::Text>::set(_builder.getPointerField(
      ::capnp::bounded<0>() * ::capnp::POINTERS), value);
}
inline  ::capnp::Text::Builder PrescritCore::CheckUsernameAvailableParams::Builder::initName(unsigned int size) {
  return ::capnp::_::PointerHelpers< ::capnp::Text>::init(_builder.getPointerField(
      ::capnp::bounded<0>() * ::capnp::POINTERS), size);
}
inline void PrescritCore::CheckUsernameAvailableParams::Builder::adoptName(
    ::capnp::Orphan< ::capnp::Text>&& value) {
  ::capnp::_::PointerHelpers< ::capnp::Text>::adopt(_builder.getPointerField(
      ::capnp::bounded<0>() * ::capnp::POINTERS), kj::mv(value));
}
inline ::capnp::Orphan< ::capnp::Text> PrescritCore::CheckUsernameAvailableParams::Builder::disownName() {
  return ::capnp::_::PointerHelpers< ::capnp::Text>::disown(_builder.getPointerField(
      ::capnp::bounded<0>() * ::capnp::POINTERS));
}

inline bool PrescritCore::CheckUsernameAvailableResults::Reader::getStatus() const {
  return _reader.getDataField<bool>(
      ::capnp::bounded<0>() * ::capnp::ELEMENTS);
}

inline bool PrescritCore::CheckUsernameAvailableResults::Builder::getStatus() {
  return _builder.getDataField<bool>(
      ::capnp::bounded<0>() * ::capnp::ELEMENTS);
}
inline void PrescritCore::CheckUsernameAvailableResults::Builder::setStatus(bool value) {
  _builder.setDataField<bool>(
      ::capnp::bounded<0>() * ::capnp::ELEMENTS, value);
}


CAPNP_END_HEADER

