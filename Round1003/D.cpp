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
#include <ios>
#include <iostream>
#include <istream>
#include <iterator>
#include <map>
#include <numeric>
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

void solve() {
  // Score of an array is defined as the sum of all its prefix sums.
  // n arrays of m length each.
  // Concatenate them to obtain the maximum score.
  // We want to concatenate such that the largest prefix sums are found earlier
  // in the sequence, as they will be repeated the most number of times.
  int n, m;
  std::cin >> n >> m;
  std::vector<std::vector<i64>> arrs(n, std::vector<i64>(m));
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      std::cin >> arrs[i][j];
      if (j > 0) {
        arrs[i][j] += arrs[i][j - 1];
      }
    }
  }

  std::vector<int> prefixSums(n, 0);

  std::sort(arrs.begin(), arrs.end(), std::greater<>{});
  i64 sum = std::transform_reduce(arrs.begin(), arrs.end(), 0LL, std::plus<>{},
                                  [](const std::vector<i64>& a) -> i64 {
                                    return std::reduce(a.begin(), a.end(), 0LL,
                                                       std::plus<>{});
                                  });

  std::cout << sum << '\n';
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
