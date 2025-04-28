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
  // any number of times:
  // - (i, j), i != j
  // - AND ai + aj is odd,
  // - ai > 0,
  // Then, a[i] -= 1, a[j] += 1.
  // Beauty is defined as max(a).
  //
  // Odd + Even = Odd
  // The rest produces an Even sum.
  // If two numbers sum to Odd, then the other number can be added to the
  // bigger.
  //
  // Definitely cant combine all even+odd greedily.
  //
  // We want to increase the minimum of even numbers.
  // Ah. We want the sum of the top-k numbers.
  //
  // If there are an even number of such even-odd pairs, then leave one
  // unpaired.
  // For each of the unpaired odds.
  int n;

  std::cin >> n;
  std::vector<int> a(n);
  int e = 0;
  int o = 0;
  i64 sum = 0;
  for (int i = 0; i < n; ++i) {
    std::cin >> a[i];
    if (a[i] % 2 == 0) {
      ++e;
    } else {
      ++o;
    }
    sum += a[i];
  }

  if (e == 0 || o == 0) {
    std::cout << *std::max_element(a.begin(), a.end()) << '\n';
    return;
  }
  std::cout << sum - o + 1 << '\n';
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
