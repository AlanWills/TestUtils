#pragma once

#include "CppUnitTest.h"
#include "FileSystem/Path.h"
#include "FileSystem/File.h"
#include "FileSystem/Directory.h"
#include "CelesteStl/Conversion/String.h"


//----------------------------------------------------------------------------------------------------------
namespace Microsoft::VisualStudio::CppUnitTestFramework
{
  template<>
  inline std::wstring ToString<Celeste::Path>(const Celeste::Path& path)
  {
    wchar_t buffer[1024];
    celstl::charToWchar(path.c_str(), buffer, 1024);

    return std::wstring(buffer);
  }

  template<>
  inline std::wstring ToString<Celeste::Directory>(const Celeste::Directory& directory)
  {
    const Celeste::Path& directoryPath = directory.getDirectoryPath();
    wchar_t buffer[1024];
    celstl::charToWchar(directoryPath.c_str(), buffer, 1024);

    return std::wstring(buffer);
  }

  template<>
  inline std::wstring ToString<Celeste::File>(const Celeste::File& file)
  {
    const Celeste::Path& filePath = file.getFilePath();
    wchar_t buffer[1024];
    celstl::charToWchar(filePath.as_string().c_str(), buffer, 1024);

    return std::wstring(buffer);
  }
}