#ifndef Tour_hpp
#define Tour_hpp

#include <list>
#include "city/City.hpp"

namespace tour {
  struct Tour {
    std::list<city::City> cities;
  };
}

#endif
