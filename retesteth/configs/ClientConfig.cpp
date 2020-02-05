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
    ],
    "exceptions" : {
        "ExtraDataTooBig" : "extra-data too long",
        "InvalidDifficulty" : "invalid difficulty",
        "InvalidGasLimit" : "invalid gasLimit:",
        "TooMuchGasUsed" : "invalid gasUsed:",
        "InvalidNumber" : "invalid block number",
        "InvalidTimestampEqualParent" : "timestamp equals parent's",
        "InvalidTimestampOlderParent" : "timestamp older than parent",
        "InvalidLogBloom" : "invalid bloom (remote:",
        "InvalidStateRoot" : "invalid merkle root (remote:",
        "InvalidGasLimit2" : "invalid gas limit:",
        "InvalidGasUsed" : "invalid gas used (remote:",
        "InvalidBlockMixHash" : "invalid mix digest",
        "InvalidBlockNonce" : "",
        "UnknownParent" : "unknown ancestor",
        "UnknownParent2" : "unknown ancestor",
        "InvalidReceiptsStateRoot" : "invalid receipt root hash (remote:",
        "InvalidTransactionsRoot" : "transaction root hash mismatch: have",
        "InvalidUnclesHash" : "uncle root hash mismatch: have",
        "InvalidUncleParentHash" : "uncle's parent is not ancestor",
        "UncleInChain" : "duplicate uncle",
        "UncleIsAncestor" : "uncle is ancestor",
        "UncleParentIsNotAncestor" : "uncle's parent is not ancestor",
        "TooManyUncles" : "too many uncles",
        "OutOfGas" : "out of gas",
        "ExtraDataIncorrectDAO" : "bad DAO pro-fork extra-data"
    }
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
    ],
    "exceptions" : {
        "ExtraDataTooBig" : "extra-data too long",
        "InvalidDifficulty" : "invalid difficulty"
    }
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
    ],
    "exceptions" : {
        "ExtraDataTooBig" : "ExtraData too big",
        "InvalidDifficulty" : "Invalid Difficulty",
        "InvalidGasLimit" : "Invalid Block GasLimit",
        "TooMuchGasUsed" : "Too much gas used",
        "InvalidNumber" : "Invalid number",
        "InvalidTimestamp" : "Invalid timestamp",
        "InvalidLogBloom" : "Invalid log bloom",
        "InvalidStateRoot" : "Invalid state root",
        "InvalidGasLimit2" : "Invalid Block GasLimit",
        "InvalidGasUsed" : "Invalid gas used",
        "InvalidBlockMixHash" : "Invalid block nonce",
        "InvalidBlockNonce" : "Invalid block nonce"
        "UnknownParent" : "UnknownParent",
        "UnknownParent2" : "Invalid parent hash",
        "InvalidReceiptsStateRoot" : "Invalid receipts state root",
        "InvalidTransactionsRoot" : "Invalid transactions root",
        "InvalidUnclesHash" : "Invalid uncles hash"
    }
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
    ],
    "exceptions" : {
        "ExtraDataTooBig" : "ExtraData too big",
        "InvalidDifficulty" : "Invalid Difficulty",
        "InvalidGasLimit" : "Invalid Block GasLimit",
        "TooMuchGasUsed" : "Too much gas used",
        "InvalidNumber" : "Invalid number",
        "InvalidTimestamp" : "Invalid timestamp",
        "InvalidLogBloom" : "Invalid log bloom",
        "InvalidStateRoot" : "Invalid state root",
        "InvalidGasLimit2" : "Invalid Block GasLimit",
        "InvalidGasUsed" : "Invalid gas used",
        "InvalidBlockMixHash" : "Invalid block nonce",
        "InvalidBlockNonce" : "Invalid block nonce"
        "UnknownParent" : "UnknownParent",
        "UnknownParent2" : "Invalid parent hash",
        "InvalidReceiptsStateRoot" : "Invalid receipts state root",
        "InvalidTransactionsRoot" : "Invalid transactions root",
        "InvalidUnclesHash" : "Invalid uncles hash"
    }
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
    ],
    "exceptions" : {
        "ExtraDataTooBig" : "ExtraData too big",
        "InvalidDifficulty" : "Invalid Difficulty",
        "InvalidGasLimit" : "Invalid Block GasLimit",
        "TooMuchGasUsed" : "Too much gas used",
        "InvalidNumber" : "Invalid number",
        "InvalidTimestamp" : "Invalid timestamp",
        "InvalidLogBloom" : "Invalid log bloom",
        "InvalidStateRoot" : "Invalid state root",
        "InvalidGasLimit2" : "Invalid Block GasLimit",
        "InvalidGasUsed" : "Invalid gas used",
        "InvalidBlockMixHash" : "Invalid block nonce",
        "InvalidBlockNonce" : "Invalid block nonce"
        "UnknownParent" : "UnknownParent",
        "UnknownParent2" : "Invalid parent hash",
        "InvalidReceiptsStateRoot" : "Invalid receipts state root",
        "InvalidTransactionsRoot" : "Invalid transactions root",
        "InvalidUnclesHash" : "Invalid uncles hash"
    }
})";

string aleth_config_sh = R"(
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