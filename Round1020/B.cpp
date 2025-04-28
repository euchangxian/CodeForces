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
  // permutation p from 0 to n-1 (0-indexed)
  // n cells
  // paint the ith cell in the color MEX(p1, p2, ... ,pi) (MEX of prefix)
  // construct p such that strips painted color x is maximised
  // at least x slots are necessary, then the rest can be constructed.
  int n, x;
  std::cin >> n >> x;

  std::vector<int> nums(n, -1);
  for (int i = 0; i < x; ++i) {
    nums[i] = i;
  }
  for (int i = x; i < n; ++i) {
    nums[i] = (n - 1) - (i - x);
  }

  for (int a : nums) {
    std::cout << a << ' ';
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
