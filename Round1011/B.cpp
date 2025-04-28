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
  // perform until length 1:
  // - select l < r, replace a[l..r] with MEX(a[l..r])
  // Length reduces by r-l.
  //
  // Want: Final to be 0.
  //
  // Final operation's MEX need to be 0.
  // Therefore, need 1, ...,
  //
  // Construction?
  // If the array does not have 0, then trivially l=0, r=n-1
  int n;
  std::cin >> n;
  std::vector<int> nums(n);
  for (int i = 0; i < n; ++i) {
    std::cin >> nums[i];
  }

  int l = -1;
  int r = -1;

  std::vector<int> zeroes;
  for (int i = 0; i < n; ++i) {
    if (nums[i] == 0) {
      zeroes.push_back(i);
    }
  }

  if (zeroes.empty()) {
    std::cout << 1 << '\n';
    std::cout << 1 << ' ' << n << '\n';
    return;
  }

  // n >= 4
  if (zeroes[0] == 0 && zeroes.back() == n - 1) {
    std::cout << 3 << '\n';
    std::cout << 1 << ' ' << 2 << '\n';
    std::cout << 2 << ' ' << n - 1 << '\n';  // 2nd to nth element, which is n-1
    std::cout << 1 << ' ' << 2 << '\n';
    return;
  }

  if (zeroes[0] == 0) {
    std::cout << 2 << '\n';
    std::cout << 1 << ' ' << n - 1 << '\n';
    std::cout << 1 << ' ' << 2 << '\n';
    return;
  }

  // all other cases.
  std::cout << 2 << '\n';
  std::cout << 2 << ' ' << n << '\n';
  std::cout << 1 << ' ' << 2 << '\n';
  return;
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
