#ifndef Map_hpp
#define Map_hpp

#include <vector>
#include <string>
#include "city/City.hpp"

namespace map {
  class Map {
   public:
    Map(const std::string& raw);

    unsigned distance(city::City from, city::City to) const
    {
      return distances.at(from).at(to);
    }

    std::string city_name(city::City which) const
    {
      return headers.at(which + 1);
    }

    size_t city_count() const
    {
      return headers.size() - 1;
    }

    static Map from_file(const std::string& filename);

   private:
    std::vector<std::string> headers{};
    std::vector<std::vector<city::City>> distances{};
  };
}

#endif
