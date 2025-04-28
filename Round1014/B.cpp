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
  // two binary string a and b, both length n.
  // 1. swap(a[i], b[i-1]) or
  // 2. swap(b[i], a[i-1])
  // any number of times.
  // output YES if a can be made all 0s.
  //
  // Within a string, '1's can be moved two spots front/back.
  // Thus, construct B such that for each '1' in A, we have a zig-zag pattern.
  // Count odd and even index '0's in B.
  int n;
  std::string a, b;
  std::cin >> n >> a >> b;

  std::vector<int> ones;

  int odds = 0;
  int evens = 0;
  for (int i = 0; i < n; ++i) {
    if (a[i] == '1') {
      if (i % 2 == 0) {
        --evens;
      } else {
        --odds;
      }
    }
  }

  for (int i = 0; i < n; ++i) {
    if (b[i] == '0') {
      if (i % 2 == 0) {
        ++odds;
      } else {
        ++evens;
      }
    }
  }

  bool yes = odds >= 0 && evens >= 0;
  std::cout << (yes ? "YES" : "NO") << '\n';
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
