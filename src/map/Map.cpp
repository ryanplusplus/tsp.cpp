#include "map/Map.hpp"
#include <csv.hpp>
#include <algorithm>

map::Map::Map(const std::string& raw)
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
