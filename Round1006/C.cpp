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
  // key for a storage with the code (n, x) is array a of length n such that
  // - a1 | a2 | ... | an = x, i.e., bitwise OR sum
  // - MEX({a1, a2, ..., an}) is maximised among all such a.
  // Does hint that multiple arrays with OR sum = x exists.
  // Construction, again.
  //
  // We only want the bits in x to be set.
  // Technically, without the second constraint, simply doing a1 = x, the rest
  // 0s will work.
  // But we want the MEX to be maximised. i.e., consecutive numbers up to x.
  //
  // bitwise subsets?
  int n, x;
  std::cin >> n >> x;

  int orSum = 0;
  int subset = 0;
  for (int i = 0; i < n - 1; ++i) {
    std::cout << subset << ' ';
    orSum |= subset;
    subset = (subset - x) & x;
  }

  if ((orSum ^ x) != 0) {
    std::cout << (orSum ^ x);
  } else {
    std::cout << subset;
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
