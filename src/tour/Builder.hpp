#ifndef Builder_hpp
#define Builder_hpp

#include <numeric>
#include "tour/Tour.hpp"

namespace tour {
  template <typename Inserter, typename Randomizer>
  class Builder {
   public:
    static tour::Tour build(const map::Map& map)
    {
      tour::Tour tour{};

      std::vector<city::City> cities(map.city_count());
      std::iota(cities.begin(), cities.end(), 0);

      Randomizer::randomize(cities);

      for(auto city : cities) {
        Inserter::insert(tour, city, map);
      }

      return tour;
    }
  };
}

#endif
