#include "tour/LeastCostInserter.hpp"
#include "CppUTest/TestHarness.h"

using namespace tour;
using namespace map;
using namespace city;

TEST_GROUP(LeastCostInserter)
{
  static constexpr auto raw_data = R"(,"Birmingham, Ala.","Boston, Mass.","Buffalo, N.Y.","Chicago, Ill."
"Birmingham, Ala.",0,1194,947,657
"Boston, Mass.",1194,0,457,983
"Buffalo, N.Y.",947,457,0,536
"Chicago, Ill.",657,983,536,0)";

  Map map{raw_data};

  Tour tour{};

  template <typename... Cities>
  void given_that_the_tour_contains(Cities... cities)
  {
    tour.cities = {(City)cities...};
  }

  void after_inserting(City city)
  {
    LeastCostInserter::insert(tour, city, map);
  }

  template <typename... Cities>
  void the_tour_should_contain(Cities... cities)
  {
    auto expected = std::list<City>{(City)cities...};
    CHECK(tour.cities == expected);
  }
};

TEST(LeastCostInserter, should_insert_the_first_city_as_the_starting_and_ending_point)
{
  given_that_the_tour_contains();
  after_inserting(1);
  the_tour_should_contain(1, 1);
}

TEST(LeastCostInserter, should_insert_the_city_where_the_total_cost_is_minimized)
{
  given_that_the_tour_contains(1, 1);

  after_inserting(2);
  the_tour_should_contain(1, 2, 1);

  after_inserting(0);
  the_tour_should_contain(1, 0, 2, 1);

  after_inserting(3);
  the_tour_should_contain(1, 0, 3, 2, 1);
}
