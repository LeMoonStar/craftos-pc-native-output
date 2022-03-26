extern "C" {
#include "lua.h"
#include "lauxlib.h"
}

#include <CraftOS-PC/CraftOS-PC.hpp>
#include <iostream>

static int output(lua_State *L) {
    int n = lua_gettop(L);
    
    std::string out = "";

    for (int i = 1; i <= n; ++i) {
        out += lua_tostring(L, i);
    }

    std::cout << out << std::endl;

    return 0;
}

static luaL_Reg M[] = {
    {"output", output}
};

static PluginInfo info("native_output");

extern "C" {
DLLEXPORT int luaopen_native_output(lua_State *L) {
    luaL_register(L, "native_output", M);
    return 1;
}

DLLEXPORT PluginInfo * plugin_native_output(PluginFunctions * func, const path_t& path) {
    return &info;
}
}