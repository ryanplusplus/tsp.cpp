#include <limits>
#include "LeastCostInserter.hpp"

using namespace tour;
using namespace map;
using namespace city;

void LeastCostInserter::insert(Tour& tour, City city, const map::Map& map)
{
  if(tour.cities.empty()) {
    tour.cities.push_front(city);
    tour.cities.push_front(city);
  }
  else {
    unsigned minimum_delta = std::numeric_limits<unsigned>::max();
    auto insert_at = ++tour.cities.begin();

    auto previous = tour.cities.begin();
    for(auto current = ++tour.cities.begin(); current != tour.cities.end(); ++current, ++previous) {
      unsigned delta = 0;
      delta += map.distance(*previous, city);
      delta += map.distance(city, *current);
      delta -= map.distance(*previous, *current);

      if(delta < minimum_delta) {
        minimum_delta = delta;
        insert_at = current;
      }
    }

    tour.cities.insert(insert_at, city);
  }
}
