@0xf261570004261ab3;

struct HiMsg {
  name @0 :Text;
}

struct HelloResults {
  greeting @0 :Text;
}

interface RpcService {
  hello @0 (request: HiMsg) -> (response: HelloResults);
}
