#include "TempDirectory.h"


namespace TestUtils
{
  std::string TempDirectory::m_parentDirectory = Celeste::Directory::getExecutingAppDirectory();
}