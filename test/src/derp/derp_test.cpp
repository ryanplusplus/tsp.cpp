#include "derp.hpp"
#include "CppUTest/TestHarness.h"

TEST_GROUP(derp)
{
};

TEST(derp, should_derp)
{
  CHECK_EQUAL(42, derp::derp());
}
