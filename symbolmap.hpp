#include <string>
#include <unordered_map>
#pragma once

//symbols to be built
using symbol = const std::string;

//symbol map struct builds the symbol map
struct symbol_map
{
  symbol* insert(const std::string&);
  symbol* find(const std::string&);

  std::unordered_map<std::string, void*> symmap;
};
