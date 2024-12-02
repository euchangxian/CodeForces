#include <algorithm>
#include <array>
#include <bitset>
#include <climits>
#include <cmath>
#include <cstddef>
#include <cstdint>
#include <functional>
#include <ios>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <string_view>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>

using i64 = long long;

void solve() {
  // Given k values, choose two numbers such that a * b = (k - 2)
  // In otherwords, choose a = k/b. Only consider if k is divisible by b.
  int k;
  std::cin >> k;

  std::vector<int> stream(k);
  for (int& x : stream) {
    std::cin >> x;
  }

  std::unordered_set<int> seen;
  int n = k - 2;
  for (int x : stream) {
    if (n % x == 0) {
      int other = n / x;
      auto it = seen.find(other);
      if (it != seen.end()) {
        std::cout << other << ' ' << x << '\n';
        return;
      }

      // otherwise, insert
      seen.insert(x);
    }
  }

  // should not reach here.
}

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  int tc;  // Number of test cases
  std::cin >> tc;

  while (tc--) {
    solve();
  }

  return 0;
}
