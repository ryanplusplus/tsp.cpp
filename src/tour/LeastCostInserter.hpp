#ifndef LeastCostInserter_hpp
#define LeastCostInserter_hpp

#include "tour/Tour.hpp"
#include "map/Map.hpp"

namespace tour {
  class LeastCostInserter {
   public:
    static void insert(Tour& tour, city::City city, const map::Map& map);
  };
}

#endif
