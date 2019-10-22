#include <array>
#include <cstdint>
#include <utility>

#include "json.hpp"

#include "types.h"

using json = nlohmann::json;

class Random {
public:
  Random() = default;

  void reset(u32 seed) {
    *this = {};
    do {
      x = 0x4F6CDD1D * (x ^ seed ^ ((x ^ seed) >> 0x15) ^ ((x ^ seed ^ ((x ^ seed) >> 0x15)) >> 4));
      y = 0x4F6CDD1D * (y ^ seed ^ ((y ^ seed) >> 0x15) ^ ((y ^ seed ^ ((y ^ seed) >> 0x15)) >> 4));
      z = 0x4F6CDD1D * (z ^ seed ^ ((z ^ seed) >> 0x15) ^ ((z ^ seed ^ ((z ^ seed) >> 0x15)) >> 4));
      w = 0x4F6CDD1D * (w ^ seed ^ ((w ^ seed) >> 0x15) ^ ((w ^ seed ^ ((w ^ seed) >> 0x15)) >> 4));
    } while (!(x | y | z | w));
  }

  u32 getU32() {
    const u32 t = x ^ (x << 11);
    x = y;
    y = z;
    z = w;
    w = (w ^ (w >> 19)) ^ (t ^ (t >> 8));
    return w;
  }

  static Random sInstance;

  u32 x = 0x75BCD15;
  u32 y = 0x159A55E5;
  u32 z = 0x1F123BB5;
  u32 w = 0x5491333;
};

Random Random::sInstance;

enum class Direction : u8 {
  D = 0,
  L = 1,
  U = 2,
  R = 3,
};

using MazeRoute = std::array<Direction, 8>;
using D4Solution = std::array<int, 5>;

static constexpr Direction eggMazeRouteData[4][6] = {
    {Direction::D, Direction::D, Direction::D, Direction::D, Direction::D, Direction::D},
    {Direction::L, Direction::U, Direction::L, Direction::U, Direction::L, Direction::U},
    {Direction::L, Direction::U, Direction::R, Direction::L, Direction::U, Direction::R},
    {Direction::U, Direction::R, Direction::U, Direction::R, Direction::U, Direction::R}};

static constexpr D4Solution d4Solutions[] = {
    {3, 0, 1, 2, 4}, {3, 0, 1, 4, 2}, {3, 0, 2, 1, 4}, {3, 0, 2, 4, 1},
    {3, 0, 4, 1, 2}, {3, 0, 4, 2, 1}, {3, 4, 0, 1, 2}, {3, 4, 0, 2, 1},
    {4, 0, 1, 2, 3}, {4, 0, 1, 3, 2}, {4, 0, 2, 1, 3}, {4, 0, 2, 3, 1},
    {4, 0, 3, 1, 2}, {4, 0, 3, 2, 1}, {4, 3, 0, 1, 2}, {4, 3, 0, 2, 1},
};

std::pair<MazeRoute, D4Solution> generatePuzzles() {
  MazeRoute route;

  const bool startWithLeft = Random::sInstance.getU32() % 2 == 1;
  const u32 b = Random::sInstance.getU32() % 5;

  route[0] = startWithLeft ? Direction::L : Direction::R;
  for (int i = 1; i <= b; ++i) {
    route[i] = eggMazeRouteData[u8(route[i - 1])][Random::sInstance.getU32() % 6];
  }
  route[b + 1] = Direction::U;
  route[b + 2] = startWithLeft ? Direction::R : Direction::L;
  for (int i = b + 3; i < 7; ++i) {
    route[i] = eggMazeRouteData[u8(route[i - 1])][Random::sInstance.getU32() % 6];
  }
  route[7] = Direction::U;

  const auto& d4Solution = d4Solutions[Random::sInstance.getU32() % 16];
  return {route, d4Solution};
}

void generateJson() {
  json j;
  for (u32 seed = 0; seed <= 100; ++seed) {
    Random::sInstance.reset(seed);
    for (int i = 0; i < 7; ++i) {
      Random::sInstance.getU32();
    }

    const auto& [route, d4Puzzle] = generatePuzzles();

    char routeStr[9]{};
    for (int i = 0; i < 8; ++i) {
      static constexpr char directionStr[] = {'D', 'L', 'U', 'R'};
      routeStr[i] = directionStr[u8(route[i])];
    }
    std::string d4str;
    for (int x : d4Puzzle)
      d4str += std::to_string(x);

    j.push_back({seed, routeStr, d4str});
  }
  printf("%s", j.dump().c_str());
}

int main(int argc, char* argv[]) {
  generateJson();
}
