#include "TestUtils/TestResources/TempDirectory.h"
#include "FileSystem/Directory.h"


namespace TestUtils
{
  std::string TempDirectory::m_parentDirectory = Celeste::Directory::getExecutingAppDirectory();

  //------------------------------------------------------------------------------------------------
  void TempDirectory::clean()
  {
    Celeste::Directory temp(getFullPath());
    temp.remove();
    temp.create();
  }
}