#pragma once

#include "TestUtils/TestResources/TempDirectory.h"
#include "TestUtils/AssertSpecialization/FileSystem.h"


namespace TestUtils
{
  class BaseUnitTest
  {
    public:
      BaseUnitTest() = default;
      virtual ~BaseUnitTest() noexcept(false) {}

      void testInitializeCaller();
      void testCleanupCaller();

    protected:
      static void testClassInitialize() { }
      static void testClassCleanup() { }

      virtual void testInitialize() { }
      virtual void testCleanup() { }

      void resetState();
      void resetTempDirectory();
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