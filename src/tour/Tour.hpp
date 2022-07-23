#ifndef Tour_hpp
#define Tour_hpp

#include <list>
#include "city/City.hpp"
#include "map/Map.hpp"

namespace tour {
  struct Tour {
    std::list<city::City> cities;

    unsigned cost(const map::Map& map)
    {
      unsigned _cost = 0;
      auto previous = cities.begin();

      for(auto current = ++cities.begin(); current != cities.end(); ++previous, ++current) {
        _cost += map.distance(*previous, *current);
      }

      return _cost;
    }
  };
}

#endif
