#include "scopemap.hpp"

void enviornment::insert(symbol* sym, decl* dec)
{
    scope.insert({sym,dec});
}

decl* enviornment::find(symbol* sym)
{
    auto iter = scope.find(sym);
    if (iter != scope.end())
    {
        return iter->second;
    }
    else
    {
        return nullptr;
    }
}
