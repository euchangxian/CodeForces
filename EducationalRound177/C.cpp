#include <algorithm>
#include <array>
#include <bitset>
#include <climits>
#include <cmath>
#include <cstddef>
#include <cstdint>
#include <cstdio>
#include <cstdlib>
#include <deque>
#include <functional>
#include <iomanip>
#include <ios>
#include <iostream>
#include <istream>
#include <iterator>
#include <map>
#include <numeric>
#include <ostream>
#include <queue>
#include <ranges>
#include <set>
#include <span>
#include <sstream>
#include <stack>
#include <string>
#include <string_view>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>

using i64 = long long;
constexpr int MOD = 1'000'000'007;

void solve() {
  // given permutation p of [1..n]
  // N queries.
  // query[i]: replace P_di with 0.
  // Each element is replaced exactly once => all zero at the end.
  //
  // After each query, find the minimum number of operations to fix the array.
  // Each operation: Pick the ith-element, replace with i.
  //
  // this is cyclic sorting/ cycle finding. Linkedlist.
  // Length of cycle.
  // If not in correct position, then it takes cycleLength operations to fix.

  int n;
  std::cin >> n;
  std::vector<int> nums(n + 1);
  for (int i = 1; i <= n; ++i) {
    std::cin >> nums[i];
  }

  std::vector<bool> visited(n + 1, false);
  std::vector<int> cycleLength(n + 1, 0);
  for (int i = 1; i <= n; ++i) {
    if (visited[i]) {
      continue;
    }

    int j = i;
    int length = 0;
    while (!visited[j]) {
      visited[j] = true;
      j = nums[j];
      ++length;

      if (j == i) {
        int k = i;

        // mark elements in this cycle.
        do {
          cycleLength[k] = length;
          k = nums[k];
        } while (k != i);

        break;
      }
    }
  }

  visited = std::vector<bool>(n + 1, false);
  int ops = 0;
  for (int i = 1; i <= n; ++i) {
    int d;
    std::cin >> d;

    // mark all elements in this cycle.
    ops += cycleLength[d];

    int j = d;
    while (!visited[j]) {
      visited[j] = true;
      cycleLength[j] = 0;

      j = nums[j];
    }
    std::cout << ops << ' ';
  }
  std::cout << '\n';
}

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  int tc{1};
  std::cin >> tc;

  while (tc--) {
    solve();
  }

  return 0;
}
