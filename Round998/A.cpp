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

constexpr std::array<std::array<int, 2>, 4> directions{{
    {0, 1},
    {1, 0},
    {0, -1},
    {-1, 0},
}};

void solve() {
  // array of 5, only know a1, a2, a4, a5 i.e., NOT a3.
  // Set a3 to any integer.
  // Fibonacciness of the array is the number of integers such that
  // ai+2 = ai + ai+1
  // Find maximum.
  // 3 choices:
  // a1 + a2 = a3
  // a2 + a3 = a4 => a4 - a2 = a3
  // a3 + a4 = a5 => a5 - a4 = a3
  // Count matches.
  std::array<int, 6> a;
  std::cin >> a[1] >> a[2] >> a[4] >> a[5];

  std::unordered_set<int> possible;
  possible.insert(a[1] + a[2]);
  possible.insert(a[4] - a[2]);
  possible.insert(a[5] - a[4]);

  int maxCount = 0;
  for (int a3 : possible) {
    int count = 0;

    a[3] = a3;

    if (a[1] + a[2] == a[3]) {
      count++;
    }
    if (a[2] + a[3] == a[4]) {
      count++;
    }
    if (a[3] + a[4] == a[5]) {
      count++;
    }

    maxCount = std::max(maxCount, count);
  }

  std::cout << maxCount << '\n';
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
