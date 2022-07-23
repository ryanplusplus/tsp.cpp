#include <iostream>
#include <limits>
#include "map/Map.hpp"
#include "tour/Builder.hpp"
#include "tour/LeastCostInserter.hpp"
#include "util/Randomizer.hpp"

using namespace std;
using namespace tour;
using namespace map;
using namespace util;

int main()
{
  auto map = Map::from_file("/home/ryan/git/tsp.cpp/data/distances.csv");

  Tour shortest_tour{};
  unsigned minimum_cost = std::numeric_limits<unsigned>::max();

  for(auto i = 0; i < 1000; ++i) {
    auto tour = Builder<LeastCostInserter, Randomizer>::build(map);
    auto cost = tour.cost(map);

    if(cost < minimum_cost) {
      shortest_tour = tour;
      minimum_cost = cost;
    }
  }

  for(auto city : shortest_tour.cities) {
    cout << map.city_name(city) << endl;
  }
  cout << endl;

  cout << minimum_cost << endl;
}
