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
#include <string_view>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>

using i64 = long long;

void solve() {
  // carpet of size n by m cells.
  // n and m are even integers. Each cell contains digits from [0..9]
  // Layers are the "borders" of the grid.
  // Count number of times 1543 appear in all layers when traversed
  // clockwise, like a spiral matrix.
  int n, m;
  std::cin >> n >> m;

  std::vector<std::string> carpet(n);
  for (int i = 0; i < n; ++i) {
    std::cin >> carpet[i];
  }

  int count = 0;

  // boundaries
  int top = 0, bottom = n - 1, left = 0, right = m - 1;

  // traverse in clockwise manner.
  while (top <= bottom && left <= right) {
    // Size of current layer = 2*(width + height - 2)
    int layerSize = 2 * ((right - left + 1) + (bottom - top + 1) - 2) + 3;
    std::vector<char> currentLayer;
    currentLayer.reserve(layerSize);

    // traverse top row, left to right
    for (int col = left; col <= right; ++col) {
      currentLayer.push_back(carpet[top][col]);
    }
    ++top;

    // right col, top to down
    for (int row = top; row <= bottom; ++row) {
      currentLayer.push_back(carpet[row][right]);
    }
    --right;

    // bottom row, right to left
    if (top <= bottom) {
      for (int col = right; col >= left; --col) {
        currentLayer.push_back(carpet[bottom][col]);
      }
      --bottom;
    }

    // left col, bottom to up
    if (left <= right) {
      for (int row = bottom; row >= top; --row) {
        currentLayer.push_back(carpet[row][left]);
      }
    }
    ++left;

    if (currentLayer.size() < 4) {
      break;
    }

    // Add the first 3 characters, like a wrap-around. simplifies checks.
    for (int i = 0; i < 3; ++i) {
      currentLayer.push_back(currentLayer[i]);
    }
    // for (char c : currentLayer) {
    //   std::cout << c << ' ';
    // }
    // std::cout << '\n';

    // Count occurences of 1543 in the current layer.
    std::string_view pattern{"1543"};
    std::string_view layer(currentLayer.data(), currentLayer.size());

    for (int i = 0; i + 4 <= layer.size(); ++i) {
      count += layer.substr(i, 4) == pattern;
    }
  }
  std::cout << count << '\n';
}

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  int tc;  // Number of test cases
  std::cin >> tc;

  while (tc--) {
    solve();
  }

  return 0;
}
