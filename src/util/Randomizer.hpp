#ifndef Randomizer_hpp
#define Randomizer_hpp

#include <algorithm>
#include <random>

namespace util {
  class Randomizer {
   public:
    template <typename T>
    static void randomize(T& t)
    {
      static Randomizer instance;
      std::shuffle(t.begin(), t.end(), instance.rng);
    }

   private:
    Randomizer()
    {
    }

    std::random_device rd{};
    std::default_random_engine rng{rd()};
  };
}

#endif
