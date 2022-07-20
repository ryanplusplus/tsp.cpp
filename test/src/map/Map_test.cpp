#include "map/Map.hpp"
#include "CppUTest/TestHarness.h"

using namespace map;

TEST_GROUP(Map){};

TEST(Map, should_parse_raw_data_string)
{
  auto raw_data = R"(,"Birmingham, Ala.","Boston, Mass.","Buffalo, N.Y."
"Birmingham, Ala.",0,1194,947
"Boston, Mass.",1194,0,457
"Buffalo, N.Y.",947,457,0)";

  Map map{raw_data};

  CHECK(map.city_name(0) == "Birmingham, Ala.");
  CHECK(map.city_name(1) == "Boston, Mass.");
  CHECK(map.city_name(2) == "Buffalo, N.Y.");

  CHECK(map.distance(0, 1) == 1194);
  CHECK(map.distance(1, 0) == 1194);
  CHECK(map.distance(1, 2) == 457);
  CHECK(map.distance(2, 2) == 0);

  CHECK(map.city_count() == 3);
}
