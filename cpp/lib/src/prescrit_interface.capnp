@0xb2af59d8e0bc7728;

using Patient = (import "patient.capnp").Patient;
using User = (import "pharmacy_user.capnp").User;

interface PrescritCore {

    echo @0 () -> ();

    # Base user functions
    createUser @1 (user : User) -> (status : Bool);
}
