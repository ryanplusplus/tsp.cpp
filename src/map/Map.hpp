#ifndef Map_hpp
#define Map_hpp

#include <vector>
#include <string>
#include <csv.hpp>
#include <algorithm>

class Map {
 public:
  Map(const std::string& raw)
  {
    auto rows = csv::parse(raw);
    headers = rows.get_col_names();

    for(auto& row : rows) {
      std::vector<unsigned> row_distances;

      std::for_each(++row.begin(), row.end(), [&](auto& field) {
        row_distances.push_back(std::stoul(field.get()));
      });

      distances.push_back(row_distances);
    }
  }

  unsigned distance(unsigned from, unsigned to)
  {
    return distances.at(from).at(to);
  }

  std::string city_name(unsigned which)
  {
    return headers.at(which + 1);
  }

 private:
  std::vector<std::string> headers{};
  std::vector<std::vector<unsigned>> distances{};
};

#endif
