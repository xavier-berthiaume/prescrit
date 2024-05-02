@0x8bab73b17e589156;

using Cxx = import "/capnp/c++.capnp";
$Cxx.namespace("Serializers");

struct User {

    id @0 : UInt32 = 0;
    
    firstName @1 : Text;
    lastName @2 : Text;
    
    username @3 : Text;
    password @4 : Text;
}
