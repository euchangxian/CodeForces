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
  int n;
  std::cin >> n;
  std::array<int, 10> freq{};

  auto valid = [](auto& freq) {
    return freq[0] >= 3 && freq[1] >= 1 && freq[2] >= 2 && freq[3] >= 1 &&
           freq[5] >= 1;
  };

  int ans = 0;
  for (int i = 0; i < n; ++i) {
    int x;
    std::cin >> x;

    ++freq[x];
    if (!ans && valid(freq)) {
      ans = i + 1;
    }
  }
  std::cout << ans << '\n';
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
