#include <algorithm>
#include <array>
#include <bitset>
#include <climits>
#include <cstddef>
#include <cstdint>
#include <functional>
#include <ios>
#include <iostream>
#include <queue>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using i64 = long long;

// Given a Grid, three integers X, Y, K
// X, Y represent the size of the grid in the positive X-Y Plane.
// Find AB, CD such that
// - |AB|, |CD| >= K.
// - AB and CD are perpendicular.
// Output:
// Ax Ay Bx By
// Cx Cy Dx Dy
//
// How to determine perpendicular? cosine? lol.
// What about just picking the X axis and Y axis..?
// Not alway. 1 <= X, Y <= 1000, but 1 <= K <= 1414, indicating that
// a diagonal may be needed.
// Let AB and CD be the rightwards and leftwards diagonal respectively?
// AB = (0, 0), (std::min(X, Y), std::min(X, Y))
// CD = (0, std::min(X, Y)), (std::min(X, Y), 0)
void solve() {
  int X, Y, K;
  std::cin >> X >> Y >> K;

  int minXY = std::min(X, Y);
  std::cout << 0 << ' ' << 0 << ' ' << minXY << ' ' << minXY << '\n';
  std::cout << 0 << ' ' << minXY << ' ' << minXY << ' ' << 0 << '\n';
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
