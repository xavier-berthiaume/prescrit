@0x9f350f6edc09e33c;

using Cxx = import "/capnp/c++.capnp";
$Cxx.namespace("Serializers");

struct Patient {

    id @0 : UInt32 = 0;
    storableId @1 : Text;

    firstName @2 : Text;
    lastName @3 : Text;

    birthday @4 : Int64;
    gender @5 : Gender;

    phonenumber @6 : Text;
}

enum Gender {

    male @0;
    female @1;
    other @2;
    none @3;
}

