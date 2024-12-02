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
  // Start at (0, 0), goal at (a, b). Directions are in cardinal north south
  // east west.
  // Movements are predetermined. string s represents sequence of moves, and
  // will be repeated forever.
  // Simply getting the delta between the first and last move will not let us
  // deterimne if Alice can meet the Red Queen.
  // input do allow simulation, so just do that? At most 10 repeats of the
  // sequence, since a, b <= 10
  int n, a, b;
  std::cin >> n >> a >> b;

  std::string s;
  std::cin >> s;

  int x = 0, y = 0;
  // repeat the sequence at most 20 times
  for (int i = 0; i < 20; ++i) {
    // for each direction specified by the sequence:
    for (char d : s) {
      if (d == 'N') {
        ++y;
      } else if (d == 'S') {
        --y;
      } else if (d == 'E') {
        ++x;
      } else {
        --x;
      }

      if (x == a && y == b) {
        std::cout << "YES" << '\n';
        return;
      }
    }
  }
  std::cout << "NO" << '\n';
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
