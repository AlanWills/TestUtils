#pragma once

#include <sol/sol.hpp>


namespace TestUtils
{
  class LuaAssert
  {
    public:
      static void IsValid(sol::protected_function_result result);

    private:
      LuaAssert() = default;
      LuaAssert(const LuaAssert& testUtils) = delete;
      LuaAssert& operator=(const LuaAssert&) = delete;
  };
}