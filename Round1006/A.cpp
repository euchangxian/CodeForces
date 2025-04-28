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

void solve() {
  // a of n zeros, k, p
  // choose index i, integer -p <= x <= p,
  // ai = x
  // min operations to make sum equal to k, or impossible.
  // k can be negative.
  // greedily assign works.
  // Take the max possible sum to determine if not possible.
  int n, k, p;
  std::cin >> n >> k >> p;

  int ops = 0;
  k = std::abs(k);
  while (n-- && k > 0) {
    k = std::max(0, k - p);
    ++ops;
  }

  if (k > 0) {
    std::cout << -1 << '\n';
    return;
  }
  std::cout << ops << '\n';
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
