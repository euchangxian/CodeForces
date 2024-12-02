#include <algorithm>
#include <array>
#include <bitset>
#include <climits>
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
  // binary string s, length n.
  // binary string r, length n-1.
  // Perform n-1 operations on s. In the ith operation (1 <= i <= n-1) (1-index)
  // - Choose k such that 1 <= k <= s.length - 1, s[k] != s[k+1].
  //   if no such k exists, lose.
  // - Replace s[k:k+1] (inclusive) with r[i], which decreases the length of s
  //   by 1.
  // If all n-1 operations are performed, win.
  //
  // Hmmmmmmm. First, seems like O(nlogn) is necessary. 2 <= n <= 10^5
  // Secondly, binary string, s[k]!=s[k+1] mean that s[k]^s[k+1] = 1.
  // Second, in the ideal case, we replace s using 0/1s from r, starting from
  // the first index. JK leave this train.
  // How to exploit the fact that s.length = n, r.length = n-1?
  // Seems that we can make quite lots of decisions => choose any valid pair,
  // replace with r[i].
  // Can we try to simplify? Choose a single valid pair. Replace it.
  // How to determine a valid pair exists? Just COUNT... ITS A BINARY STRING
  // FFS. As long as there is at least 1 of each, then a valid pair MUST exist.
  // Then when replacing, just COUNT COUNT COUNT.
  // An operation reduces the count of either a '0' or a '1', depending on r[i]

  int n;
  std::string s;
  std::string r;
  std::cin >> n >> s >> r;

  int zeroes = 0;
  for (char c : s) {
    zeroes += 1 - (c - '0');
  }
  int ones = n - zeroes;

  for (int i = 0; i < n - 1; ++i) {
    if (zeroes == 0 || ones == 0) {
      std::cout << "NO" << '\n';
      return;
    }

    // Otherwise, a valid pair MUST exist.
    if (r[i] - '0' == 0) {
      // replacing the pair with a zero bit means that ones count reduces
      --ones;
    } else {
      --zeroes;
    }
  }
  std::cout << "YES" << '\n';
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
