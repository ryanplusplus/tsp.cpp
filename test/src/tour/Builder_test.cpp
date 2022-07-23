#include <algorithm>
#include "tour/Builder.hpp"
#include "CppUTest/TestHarness.h"
#include "CppUTestExt/MockSupport.h"

using namespace tour;
using namespace city;
using namespace map;

#define and_then

TEST_GROUP(Builder)
{
  class Inserter {
   public:
    static void insert(Tour& tour, City city, const Map& map)
    {
      mock()
        .actualCall("insert")
        .withParameter("city", city)
        .withParameter("map", &map);

      tour.cities.push_back(city);
    }
  };

  class Randomizer {
   public:
    template <typename T>
    static void randomize(T& t)
    {
      mock().actualCall("randomize");
      std::reverse(t.begin(), t.end());
    }
  };

  using TestBuilder = Builder<Inserter, Randomizer>;

  static constexpr auto raw_data = R"(,"Birmingham, Ala.","Boston, Mass.","Buffalo, N.Y.","Chicago, Ill."
"Birmingham, Ala.",0,1194,947,657
"Boston, Mass.",1194,0,457,983
"Buffalo, N.Y.",947,457,0,536
"Chicago, Ill.",657,983,536,0)";

  Map map{raw_data};

  Tour tour{};

  void setup()
  {
    mock().strictOrder();
  }

  void the_city_list_should_be_randomized()
  {
    mock().expectOneCall("randomize");
  }

  void city_should_be_inserted(City city)
  {
    mock()
      .expectOneCall("insert")
      .withParameter("city", city)
      .withParameter("map", (const void*)&map);
  }

  void when_a_tour_is_built()
  {
    tour = TestBuilder::build(map);
  }

  template <typename... Cities>
  void the_tour_should_contain(Cities... cities)
  {
    auto expected = std::list<City>{(City)cities...};
    CHECK(tour.cities == expected);
  }
};

TEST(Builder, should_build_a_tour)
{
  the_city_list_should_be_randomized();
  city_should_be_inserted(3);
  city_should_be_inserted(2);
  city_should_be_inserted(1);
  city_should_be_inserted(0);
  when_a_tour_is_built();
  and_then the_tour_should_contain(3, 2, 1, 0);
}
