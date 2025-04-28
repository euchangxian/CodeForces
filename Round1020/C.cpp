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
#include <limits>
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
  // two arrays A B size n are complementary IF
  // there exists x such that A[i] + B[i] = x for all 1 <= i <= N
  //
  // Given two nonnegative A and B where A[i], B[i] <= K, and B has missing
  // elements i.e., B[i] = -1
  // Count number of possible arrays B such that A B are complementary
  int n, k;
  std::cin >> n >> k;
  std::vector<i64> A(n), B(n);
  for (int i = 0; i < n; ++i) {
    std::cin >> A[i];
  }

  bool valid = true;
  int target = -1;
  int missing = 0;
  for (int i = 0; i < n; ++i) {
    std::cin >> B[i];
    if (B[i] == -1) {
      ++missing;
    } else {
      if (target == -1) {
        target = A[i] + B[i];
      } else {
        if (A[i] + B[i] != target) {
          valid = false;
        }
      }
    }
  }

  // not complementary at all.
  if (!valid) {
    std::cout << 0 << '\n';
    return;
  }

  if (missing == n) {
    // function of max, min and K
    int max = *std::max_element(A.begin(), A.end());
    int min = *std::min_element(A.begin(), A.end());
    int ways = k - (max - min) + 1;
    std::cout << ways << '\n';
    return;
  }

  for (int i = 0; i < n; ++i) {
    if (B[i] == -1) {
      if (target - A[i] <= k && target - A[i] >= 0) {
        continue;
      } else {
        valid = false;
      }
    }
  }

  if (!valid) {
    std::cout << 0 << '\n';
    return;
  }
  std::cout << 1 << '\n';
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
