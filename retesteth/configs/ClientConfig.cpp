#include <retesteth/configs/ClientConfig.h>
#include <mutex>
std::mutex g_staticDeclaration_clientConfigID;
namespace test
{
ClientConfigID::ClientConfigID()
{
    std::lock_guard<std::mutex> lock(g_staticDeclaration_clientConfigID);
    static unsigned uniqueID = 0;
    uniqueID++;
    m_id = uniqueID;
}

}  // namespace test

using namespace std;
string default_config = R"({
    "name" : "Ethereum GO on TCP",
    "socketType" : "tcp",
    "socketAddress" : [
        "127.0.0.1:8545",
        "127.0.0.1:8546",
        "127.0.0.1:8547",
        "127.0.0.1:8548",
        "127.0.0.1:8549",
        "127.0.0.1:8550",
        "127.0.0.1:8551",
        "127.0.0.1:8552"
    ],
    "forks" : [
        "Frontier",
        "Homestead",
        "EIP150",
        "EIP158",
        "Byzantium",
        "Constantinople",
        "ConstantinopleFix",
        "Istanbul"
    ],
    "additionalForks" : [
        "FrontierToHomesteadAt5",
        "HomesteadToEIP150At5",
        "EIP158ToByzantiumAt5",
        "HomesteadToDaoAt5",
        "ByzantiumToConstantinopleFixAt5"
    ]
})";

string besu_config = R"({
    "name" : "Hyperledger Besu on TCP",
    "socketType" : "tcp",
    "socketAddress" : [
        "127.0.0.1:47710"
    ],
    "forks" : [
        "Frontier",
        "Homestead",
        "EIP150",
        "EIP158",
        "Byzantium",
        "Constantinople",
        "ConstantinopleFix",
        "Istanbul"
    ],
    "additionalForks" : [
        "FrontierToHomesteadAt5",
        "HomesteadToEIP150At5",
        "EIP158ToByzantiumAt5",
        "HomesteadToDaoAt5",
        "ByzantiumToConstantinopleFixAt5"
    ]
})";

string alethTCP_config = R"({
    "name" : "Ethereum aleth on TCP",
    "socketType" : "tcp",
    "socketAddress" : [
        "127.0.0.1:8545",
        "127.0.0.1:8546"
    ],
    "forks" : [
        "Frontier",
        "Homestead",
        "EIP150",
        "EIP158",
        "Byzantium",
        "Constantinople",
        "ConstantinopleFix",
        "Istanbul"
    ],
    "additionalForks" : [
        "FrontierToHomesteadAt5",
        "HomesteadToEIP150At5",
        "EIP158ToByzantiumAt5",
        "HomesteadToDaoAt5",
        "ByzantiumToConstantinopleFixAt5"
    ]
})";

string alethIPCDebug_config = R"({
    "name" : "Ethereum aleth on IPC Debug",
    "socketType" : "ipc-debug",
    "socketAddress" : "/home/username/.ethereum/geth.ipc",
    "forks" : [
        "Frontier",
        "Homestead",
        "EIP150",
        "EIP158",
        "Byzantium",
        "Constantinople",
        "ConstantinopleFix",
        "Istanbul"
    ],
    "additionalForks" : [
        "FrontierToHomesteadAt5",
        "HomesteadToEIP150At5",
        "EIP158ToByzantiumAt5",
        "HomesteadToDaoAt5",
        "ByzantiumToConstantinopleFixAt5"
    ]
})";


string aleth_config = R"({
    "name" : "Ethereum cpp-client",
    "socketType" : "ipc",
    "socketAddress" : "local",
    "forks" : [
        "Frontier",
        "Homestead",
        "EIP150",
        "EIP158",
        "Byzantium",
        "Constantinople",
        "ConstantinopleFix",
        "Istanbul"
    ],
    "additionalForks" : [
        "FrontierToHomesteadAt5",
        "HomesteadToEIP150At5",
        "EIP158ToByzantiumAt5",
        "HomesteadToDaoAt5",
        "ByzantiumToConstantinopleFixAt5"
    ]
})";

string aleth_config_sh = R"({
#!/bin/bash
onexit()
{
    kill $child
}
trap onexit SIGTERM
trap onexit SIGABRT

##ARGUMENTS PASSED BY RETESTETH
##
## $1  <db-path> 		A path to database directory that a client should use
## $2  <ipcpath>		A path to the ipc socket file (has /geth.ipc at the end)
#####

aleth --test --db-path $1 --ipcpath $2 --log-verbosity 5 &
child=$!
wait "$child"
)";
