#pragma once

#include "CppUnitTest.h"
#include "FileSystem/Path.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;


namespace TestUtils
{
  class FileAssert
  {
    public:

      //------------------------------------------------------------------------------------------------
      // FileExists
      static void FileExists(const Celeste::Path& path) { FileExists(path.as_string()); }
      static void FileExists(const std::string& fullFilePath) { FileExists(fullFilePath.c_str()); }
      static void FileExists(const char* fullFilePath);

      //------------------------------------------------------------------------------------------------
      // FileDoesNotExist
      static void FileDoesNotExist(const Celeste::Path& path) { FileDoesNotExist(path.as_string()); }
      static void FileDoesNotExist(const std::string& fullFilePath) { FileDoesNotExist(fullFilePath.c_str()); }
      static void FileDoesNotExist(const char* fullFilePath);

      /// Checks that the contents of the file with the inputted filepath matches the inputted expected string
      static void FileContentsEqual(const std::string& fullFilePath, const std::string& expectedFileContents);

      /// Checks that the contents of the file with the inputted filepath does not match the inputted expected string
      static void FileContentsNotEqual(const std::string& fullFilePath, const std::string& notExpectedFileContents);

    private:
      // Set up the appropriate constructors and assignment operators so that an instance of this class is impossible to create
      FileAssert() = default;
      FileAssert(const FileAssert& testUtils) = delete;
      FileAssert& operator=(const FileAssert&) = delete;

      static std::string getFileContents(const std::string& fullFilePath);
  };
}