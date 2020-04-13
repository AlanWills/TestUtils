#pragma once

#include "TempDirectory.h"
#include "AssertSpecialization/FileSystem.h"


namespace TestUtils
{
  class BaseUnitTest
  {
    public:
      BaseUnitTest() { }
      virtual ~BaseUnitTest() noexcept(false) { }

      void testInitializeCaller() 
      { 
        TempDirectory::clean();
        testInitialize(); 
      }

      void testCleanupCaller()
      {
        TempDirectory::clean();
        testCleanup();
      }

    protected:
      static void testClassInitialize() { }
      static void testClassCleanup() { }

      virtual void testInitialize() { }
      virtual void testCleanup() { }
  };
}

#define TEST_UTILS_TEST_CLASS(ClassName) \
  TEST_CLASS(ClassName), public TestUtils::BaseUnitTest \
  { \
    public:\
    \
    TEST_CLASS_INITIALIZE(ClassName##_TestClassInitialize) \
    { \
      testClassInitialize(); \
      ClassName::testClassInitialize(); \
    } \
    TEST_CLASS_CLEANUP(ClassName##_TestClassCleanup) \
    { \
      testClassCleanup(); \
      ClassName::testClassCleanup(); \
    } \
    TEST_METHOD_INITIALIZE(ClassName##_TestMethodInitialize) \
    { \
      testInitializeCaller(); \
    } \
    TEST_METHOD_CLEANUP(ClassName##_TestMethodCleanup) \
    { \
      testCleanupCaller(); \
    }