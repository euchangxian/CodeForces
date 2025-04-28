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
  // score of ARBITRARY array b to be the length of b minus the number of
  // distinct elements in b.
  // Given a, remove some NON-EMPTY contiguous subarray from a at most once.
  // Output maximum score of a. Choose the one that MINIMISES the final length.
  //
  // Trade-off between length and unique. i.e., expanding the window removes
  // length, dropping by 1.
  //
  // HMMM? How to even increase the score? Isnt this monotonically decreasing?
  // AH, length constraint.
  // We need to remove one distinct element in each operation.
  // i.e., window such that number of unique elements is equal to the size of
  // the window.
  // 1, 2, 2, 4
  // Ah, we can only remove elements that only occur once in the array.
  // Hm. does the constraint give a hint?
  // 1 <= ai <= n
  constexpr int MAX_N = 2 * 100000;
  int n;
  std::cin >> n;
  std::vector<int> a(n);
  std::array<int, MAX_N + 1> frequency{};
  for (int& x : a) {
    std::cin >> x;
    ++frequency[x];
  }

  auto unique = [&frequency](int x) -> bool { return frequency[x] == 1; };

  bool hasUnique = false;
  for (int x : a) {
    if (unique(x)) {
      hasUnique = true;
      break;
    }
  }
  if (!hasUnique) {
    std::cout << 0 << '\n';
    return;
  }

  int bestLength = -1;
  int bestL = -1, bestR = -1;

  int currUnique = 0;
  int l = 0;
  for (int r = 0; r < n; ++r) {
    if (unique(a[r])) {
      ++currUnique;
    }

    while (l <= r && (!unique(a[r]) || currUnique < (r - l + 1))) {
      if (unique(a[l])) {
        --currUnique;
      }
      ++l;
    }

    if (currUnique == (r - l + 1) && currUnique > bestLength) {
      bestLength = currUnique;
      bestL = l;
      bestR = r;
    }
  }

  if (bestLength == -1) {
    std::cout << 0 << '\n';
    return;
  }

  // 1-indexed
  std::cout << bestL + 1 << ' ' << bestR + 1 << '\n';
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
