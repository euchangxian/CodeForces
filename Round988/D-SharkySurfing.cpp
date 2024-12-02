#include <algorithm>
#include <array>
#include <bitset>
#include <climits>
#include <cmath>
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
  // Line.
  // start at position 1, end at L
  // at position x, with jump power of k, can jump to ANY position in the
  // interval [x, x + k].
  // Initial jump power is 1.
  //
  // n hurdles on the line, represented by interval [l, r]. Cannot jump in any
  // position in the range.
  // m power ups, located at position xi, with a power value of vi.
  // Increases jump power by vi.
  //
  // Minimum number of power ups to collect?
  // Can we do BFS? Maintain {X, currentPower, powerupsTaken}
  // Possible m splits. Too expensive? Pruned by hurdles. But what if I have
  // absurd amount of powerups with small hurdle.
  //
  // What about DP[l][m]? represents the minimum power ups required to reach
  // position l with m powerups taken
  // Greedily jump? Cant really be filling up each dp[l][m] in the range.
  // what about prefixes?
  //
  // Each hurdle tells us the minimum power necessary to cross it, i.e.,
  // {7, 14} => 6 --jump--> 15 needed => power 9 needed.
  //
  // Therefore, at l=6, find the smallest combination of powerups >= 9
  // reduces to something like sliding window.
  // What about doing a prefixMax of powers? Nope not trivial.
  // Sliding window does not work too? Maybe a subsequence of powerups is
  // taken?
  // Something like the maximum power with m number of fruits at position l
  int n, m, L;
  std::cin >> n >> m >> L;

  // store the required power to cross this hurdle instead of the interval.
  std::vector<std::array<int, 2>> hurdles;
  hurdles.reserve(n);
  for (int i = 0; i < n; ++i) {
    int l, r;
    std::cin >> l >> r;
    hurdles.push_back({l, r - l + 2});
  }

  std::vector<std::array<int, 2>> powerups;
  powerups.reserve(m);
  for (int i = 0; i < m; ++i) {
    int x, v;
    std::cin >> x >> v;
    powerups.push_back({x, v});
  }

  std::priority_queue<int> availablePowerUps;

  // exploit sorted order of both hurdles and powerups.
  size_t pIdx = 0;
  int currentPower = 1;
  int consumed = 0;
  for (auto& hurdle : hurdles) {
    // collect all powerups up till the hurdle.
    while (pIdx < m && powerups[pIdx][0] < hurdle[0]) {
      availablePowerUps.push(powerups[pIdx++][1]);
    }

    int requiredPower = hurdle[1];
    while (currentPower < requiredPower && !availablePowerUps.empty()) {
      currentPower += availablePowerUps.top();
      availablePowerUps.pop();
      ++consumed;
    }

    // if after the queue is emptied, power is still not sufficient, return -1
    if (currentPower < requiredPower) {
      std::cout << "-1" << '\n';
      return;
    }
  }

  std::cout << consumed << '\n';
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
