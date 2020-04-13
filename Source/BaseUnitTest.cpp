#include "BaseUnitTest.h"


namespace TestUtils
{
  //------------------------------------------------------------------------------------------------
  void BaseUnitTest::testInitializeCaller()
  {
    resetState();
    testInitialize();
  }

  //------------------------------------------------------------------------------------------------
  void BaseUnitTest::testCleanupCaller()
  {
    resetState();
    testCleanup();
  }

  //------------------------------------------------------------------------------------------------
  void BaseUnitTest::resetState()
  {
    resetTempDirectory();
  }

  //------------------------------------------------------------------------------------------------
  void BaseUnitTest::resetTempDirectory()
  {
    TempDirectory::clean();
  }
}