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
  // two bags.
  // first bag: n numbers a1, a2, ...
  // second bag: empty
  //
  // any number of times, choose:
  // - choose any number from first bag, move to second bag.
  // - choose a number from the first bag that is also in the second bag,
  //   increase it by 1. (only the first bag)
  //
  // return true if possible to make contents identical.
  // N is EVEN.
  // ai <= n. Is this a hint?
  // First, we want to sort, so we can group numbers.
  // Then,
  // if a number occurs only once, then impossible
  // twice, then no operation should be done on it.
  // thrice, can try incrementing it, once.
  // four, then no operation.
  //
  // hm, parity. Get rid of odd parity.
  int n;
  std::cin >> n;

  std::vector<int> A(n);
  std::array<int, 1001> frequency{};
  for (int i = 0; i < n; ++i) {
    std::cin >> A[i];
    ++frequency[A[i]];
  }

  for (int x = 1; x <= n; ++x) {
    if (frequency[x] == 1) {
      std::cout << "NO\n";
      return;
    }

    if (frequency[x] == 2) {
      continue;
    }

    int carry = std::max(0, frequency[x] - 2);
    frequency[x] -= carry;
    frequency[x + 1] += carry;
  }

  for (int x = 1; x <= n; ++x) {
    if (frequency[x] % 2 == 1) {
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
