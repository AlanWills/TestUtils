#include "LuaAssert.h"
#include "CppUnitTest.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;


namespace TestUtils
{
  //------------------------------------------------------------------------------------------------
  void LuaAssert::IsValid(sol::protected_function_result result)
  {
    if (!result.valid())
    {
      sol::error e = result;

      wchar_t buffer[2056];
      size_t numConverted = 0;
      mbstowcs_s(&numConverted, buffer, 2056, e.what(), 2056);
      std::wstring msg(buffer, numConverted);

      Assert::Fail(msg.c_str());
    }
  }

  //------------------------------------------------------------------------------------------------
  void LuaAssert::IsValid(sol::object object)
  {
    Assert::IsTrue(object.valid());
  }

  //------------------------------------------------------------------------------------------------
  void LuaAssert::IsTable(sol::object table)
  {
    LuaAssert::IsValid(table);
    Assert::IsTrue(table.is<sol::table>());
    LuaAssert::IsValid(table.as<sol::table>());
  }
}