#pragma once

#include <sol/sol.hpp>


namespace TestUtils
{
  class LuaAssert
  {
    public:
      static void IsValid(sol::protected_function_result result);
      static void IsValid(sol::object object);

      static void IsTable(sol::object result);

    private:
      LuaAssert() = default;
      LuaAssert(const LuaAssert& testUtils) = delete;
      LuaAssert& operator=(const LuaAssert&) = delete;
  };
}