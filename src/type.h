#pragma once

#include <cstdint>
#include <unordered_map>
#include <string>

enum class Builtin : uint16_t {
    Echo,
    Exit,
    Type
};

const std::unordered_map<std::string, Builtin> builtin_map = {
    {"echo", Builtin::Echo},
    {"exit", Builtin::Exit},
    {"type", Builtin::Type},
};
