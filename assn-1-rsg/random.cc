#include "random.h"
#include <cassert> // for assert macro
#include <limits.h>
#include <stdlib.h>
#include <time.h>

RandomGenerator::RandomGenerator() { srand(time(NULL)); }

int RandomGenerator::getRandomInteger(int low, int high) {
  assert(low <= high);
  double percent = (rand() / (static_cast<double>(RAND_MAX) + 1));
  assert(percent >= 0.0 && percent < 1.0);
  int offset = static_cast<int>(percent * (high - low + 1));
  return low + offset;
}
