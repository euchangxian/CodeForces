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
  // array b of m integers.
  // Good if, when sorted, both of its medians are equal.
  // i.e., odd length is always good, since there is only one median.
  // even length, not always good...
  // Given a of n integers, determine number of good SUBARRAYS in a.
  // 1 <= ai <= 10
  // is this suspiciously low ai a hint...?
  //
  // NAIVELY:
  // iterate over all even length subarrays
  int n;
  std::cin >> n;
  std::vector<int> v(n);
  for (int& x : v) {
    std::cin >> x;
  }

  auto getMedians = [&v](int i, int len) -> std::pair<int, int> {
    // 1 <= a <= 10
    std::array<int, 11> frequency{};
    for (int j = 0; j < len; ++j) {
      ++frequency[v[i + j]];
    }

    int mid1 = len / 2;
    int mid2 = mid1 + 1;
    int count = 0;
    int first = 0, second = 0;

    // Find the first median
    for (int num = 1; num <= 10; ++num) {
      count += frequency[num];
      if (count >= mid1 && first == 0) {
        first = num;
      }
      if (count >= mid2) {
        second = num;
        break;
      }
    }

    return {first, second};
  };

  // for each start
  int count = 0;
  for (int i = 0; i < n; ++i) {
    for (int len = 1; i + len <= n; ++len) {
      if (len & 1) {
        ++count;
        continue;
      }

      auto [m1, m2] = getMedians(i, len);
      count += m1 == m2;
    }
  }
  std::cout << count << '\n';
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
