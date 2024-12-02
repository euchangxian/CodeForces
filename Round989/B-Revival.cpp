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
  // Binary string s of length n.
  // 0 means weak spot, 1 means strong.
  // No interval of m consecutive spot is entirely weak (all 0s).
  //
  // In one operation, select any segment of length k, change every char to 1.
  // Minimum number of operations required to ensure no interval ... exists.
  int n, m, k;
  std::cin >> n >> m >> k;

  std::string s;
  std::cin >> s;
  if (s.size() < m) {
    std::cout << 0 << '\n';
    return;
  }

  int ops = 0;
  int zeros = 0;
  int i = 0;
  while (i < n) {
    if (s[i] == '1') {
      zeros = 0;
    } else {
      ++zeros;
      if (zeros == m) {
        ++ops;
        zeros = 0;

        int skip = std::min(k, n - i + 1);
        i += skip - 1;  // -1 because i is incremented later.
      }
    }
    ++i;
  }
  std::cout << ops << '\n';
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
