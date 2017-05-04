
#include "symbolmap.hpp"

//put into a symbol map
symbol* symbol_map::insert(const std::string& str)
{
  auto result = symmap.insert({str, nullptr});
  return &result.first->first;
}

//find something from the symbol map
symbol* symbol_map::find(const std::string& str)
{
  auto iter = symmap.find(str);
  return &iter->first;
}
