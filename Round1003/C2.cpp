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
  // Two arrays a and b containing n and m elements.
  // For each integer i in [1..n], perform operation at most once:
  // - choose j such that 1 <= j <= m.
  // - Set a[i] = b[j] - a[i].
  // Determine if a can be sorted in non-decreasing order (equal or >)
  // Greedily set to smallest possible, by sorting B.
  // a = {9, 5, 8}
  // b = {1, 2, 2}
  // c = {-8, -3, -7}
  // false.
  // WARNING: Since A is not monotonic, two pointer would not work. Need to
  // binary search the minimal value b[j] such that b[j] - a[i] >= a[i-1]
  // i.e., search a[i-1] + a[i]
  // val - a[i] >= a[i-1]
  int n, m;
  std::cin >> n >> m;
  std::vector<i64> a(n), b(m);
  for (i64& x : a) {
    std::cin >> x;
  }
  for (i64& x : b) {
    std::cin >> x;
  }

  std::sort(b.begin(), b.end());
  a[0] = std::min(a[0], b[0] - a[0]);
  for (int i = 1; i < n; ++i) {
    i64 firstMin = a[i];
    const auto it = std::lower_bound(b.begin(), b.end(), a[i - 1] + a[i]);
    i64 secondMin = it == b.end() ? LLONG_MAX : *it - a[i];
    if (secondMin < firstMin) {
      std::swap(firstMin, secondMin);
    }

    if (firstMin >= a[i - 1]) {
      a[i] = firstMin;
    } else if (secondMin != LLONG_MAX && secondMin >= a[i - 1]) {
      a[i] = secondMin;
    } else {
      std::cout << "NO\n";
      return;
    }
  }
  std::cout << "YES\n";
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
