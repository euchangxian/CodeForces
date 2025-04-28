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
#include <stack>
#include <string>
#include <string_view>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>

using i64 = long long;

constexpr int MOD = 1'000'000'007;

constexpr std::array<std::array<int, 2>, 4> directions{{
    {0, 1},
    {1, 0},
    {0, -1},
    {-1, 0},
}};

void solve() {
  // n slimes on a line, ith slime has weight w.
  // Slime i can eat another slime j if wi >= wj.
  // Obviously, slime j disappears,
  // weight of slime i becomes wi XOR wj.
  // Parameter x
  // - Add slime with weight x to the right end of the line
  // - This slime eats to the left if possible, and moves leftwards until
  //   it cannot eat.
  // - The score of this experiment with parameter x is the number of slimes
  //   eaten.
  // Given q queries, queries[i] = xi, determien the score of the experiment.
  // Each query is independent.
  // HM XOR. We want to XOR such that wi >= wj.
  // While x <= 2^30 ~= 10e9 seems large, note that XOR means we only need to
  // consider 30 bits.
  //
  // Obviously naively simulating would fail. Can we do better?
  // What properties of XOR can we exploit? Hm.
  // Wait, how do we process the queries faster than O(n)?
  // Sort?
  // The thing is, XOR may increase/decrease the number.
  // dp[i] represents the minimum weight to eat the first i slimes?
  // DP doesnt work since we need the bits to be in the right places.
  int n, q;
  std::cin >> n >> q;
  std::vector<int> nums(n);
  for (int i = n - 1; i >= 0; --i) {
    std::cin >> nums[i];  // insert in reverse, left-to-right is easier.
  }
  std::vector<int> queries(q);
  for (auto& x : queries) {
    std::cin >> x;
  }

  std::vector<int> prefixXOR(n + 1, 0);
  for (int i = 0; i < n; ++i) {
    prefixXOR[i + 1] = prefixXOR[i] ^ nums[i];
  }

  std::vector<int> prefixMSB(n + 1, 0);
  for (int i = 0; i < n; ++i) {
    prefixMSB[i + 1] = std::max(prefixMSB[i], 31 - __builtin_clz(nums[i]));
    // std::cout << prefixMSB[i + 1] << ' ';
  }
  // std::cout << "\n";

  std::vector<int> answer;
  answer.reserve(q);
  for (int x : queries) {
    int MSB = 31 - __builtin_clz(x);
    if (MSB > prefixMSB.back()) {
      answer.push_back(n);
      continue;
    }

    // ahhh. Flawed, some previous XOR may increase the sum
    // Ahhh, could have been fixed easily with prefix XOR
    auto prevIt = prefixMSB.begin();
    auto it = std::lower_bound(prevIt, prefixMSB.end(), MSB);
    int canEat = 0;
    while (it != prefixMSB.end()) {
      int pos = it - prefixMSB.begin() - 1;
      if (pos < 0) {
        break;
      }

      int prevPos = prevIt - prefixMSB.begin() - 1;
      x ^= prefixXOR[pos];  // prefixXOR is 1-indexed.
      if (prevPos >= 0) {
        x ^= prefixXOR[prevPos];
      }

      if (x < nums[pos]) {
        break;
      }

      canEat += it - prevIt;
      if (x == 0) {
        break;
      }

      MSB = 31 - __builtin_clz(x);
      prevIt = it;
      it = std::lower_bound(it + 1, prefixMSB.end(), MSB);
    }

    answer.push_back(canEat);
  }

  for (int ans : answer) {
    std::cout << ans << ' ';
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
