#include <iostream>
#include <fstream>
#include <sstream>
#include "map/Map.hpp"

using namespace std;

int main()
{
  ifstream t("/home/ryan/git/tsp.cpp/data/distances.csv");
  stringstream buffer;
  buffer << t.rdbuf();
  map::Map map{buffer.str()};

  cout << map.distance(3, 4) << endl;
  cout << map.city_name(0) << endl;
}
