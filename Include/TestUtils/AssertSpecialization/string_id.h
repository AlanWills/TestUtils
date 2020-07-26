#pragma once

#include "CppUnitTest.h"
#include "StringId/string_id.h"


//----------------------------------------------------------------------------------------------------------
namespace Microsoft::VisualStudio::CppUnitTestFramework
{
  template<>
  inline std::wstring ToString<string_id>(const string_id& stringId)
  {
    return std::to_wstring(stringId.id());
  }
}