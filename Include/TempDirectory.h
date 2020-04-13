#pragma once

#include "FileSystem/Path.h"
#include "FileSystem/Directory.h"

#include <string>


namespace TestUtils
{
  class TempDirectory
  {
    public:
      static std::string getRelativePath() { return "Temp"; }
      static Celeste::Path getFullPath() { return Celeste::Path(m_parentDirectory, "Temp"); }

      static void setParentDirectory(const std::string& parentDirectory) { m_parentDirectory = parentDirectory; }

      static void clean()
      {
        Celeste::Directory temp(getFullPath());
        temp.remove();
        temp.create();
      }

    private:
      static std::string m_parentDirectory;
  };
}