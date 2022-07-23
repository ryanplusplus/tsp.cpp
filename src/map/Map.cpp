#include "map/Map.hpp"
#include <csv.hpp>
#include <algorithm>
#include <fstream>
#include <sstream>

using namespace map;
using namespace std;

Map::Map(const string& raw)
{
  auto rows = csv::parse(raw);
  headers = rows.get_col_names();

  for(auto& row : rows) {
    vector<unsigned> row_distances;

    for_each(++row.begin(), row.end(), [&](auto& field) {
      row_distances.push_back(stoul(field.get()));
    });

    distances.push_back(row_distances);
  }
}

Map Map::from_file(const string& filename)
{
  ifstream t(filename);
  stringstream buffer;
  buffer << t.rdbuf();
  return map::Map{buffer.str()};
}
