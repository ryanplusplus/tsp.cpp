#ifndef Map_hpp
#define Map_hpp

#include <vector>
#include <string>

class Map {
 public:
  Map(const std::string& raw);

  unsigned distance(unsigned from, unsigned to) const
  {
    return distances.at(from).at(to);
  }

  std::string city_name(unsigned which) const
  {
    return headers.at(which + 1);
  }

 private:
  std::vector<std::string> headers{};
  std::vector<std::vector<unsigned>> distances{};
};

#endif
