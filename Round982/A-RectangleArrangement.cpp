#include <algorithm>
#include <array>
#include <bitset>
#include <climits>
#include <cstddef>
#include <cstdint>
#include <functional>
#include <ios>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>

using namespace std;

// Infinite square grid, cells are initially white.
// n stamps, each is a rectangle of width wi and heigh hi.
// Use each stamp once to color a rectangle on the grid black.
// Stamps cannot be rotated.
// Minimum sum of the perimeters of the connected region?
// 1 <= tc <= 500
// 1 <= n <= 100
// Hm. Looks like Line Sweep-ish. Minimum perimeter means overlapping stamps
// as much as possible? It is allowed to contain stamps within other stamps.
// Seems like LC218- The Skyline Problem
// Visualise a grid starting from the origin.
// Pack all the rectangles to the left i.e. at (0, 0).
// At each x-coordinate, maintain the maximum height.
int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  int tc;  // Number of test cases
  std::cin >> tc;

  while (tc--) {
    int n;
    std::cin >> n;

    int maxWidth = INT_MIN;
    int maxHeight = INT_MIN;

    int width;
    int height;
    while (n--) {
      std::cin >> width >> height;
      maxWidth = std::max(maxWidth, width);
      maxHeight = std::max(maxHeight, height);
    }
    std::cout << (maxWidth + maxHeight) * 2 << '\n';
  }

  return 0;
}
