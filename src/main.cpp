#include <iostream>
#include "map/Map.hpp"
#include "tour/Builder.hpp"
#include "tour/LeastCostInserter.hpp"
#include "util/Randomizer.hpp"

using namespace std;
using namespace tour;
using namespace map;

int main()
{
  auto map = Map::from_file("/home/ryan/git/tsp.cpp/data/distances.csv");

  auto tour = tour::Builder<tour::LeastCostInserter, util::Randomizer>::build(map);

  for(auto city : tour.cities) {
    cout << map.city_name(city) << endl;
  }
  cout << endl;

  cout << tour.cost(map) << endl;
}
