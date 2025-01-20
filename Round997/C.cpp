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
  // integer sequence a = [a1, a2, ..., an]
  // f(a) = length of longest subequence of a that is also a palindrome.
  // g(a) = number of subsequences of length f(a) that are palindromes, i.e.,
  // counts number of maximum length palindromic subsequences.
  //
  // 1 <= ai <= n for all 1 <= i <= n
  // g(a) > n
  //
  // Construction? Put two equal at i and j.
  // Number of palindrome subsequences that can be created from the pair is
  // n - 2, if everything in between is distinct.
  // 1 1 2 3 2 1
  // 111
  // 121
  // 121
  // 131
  // Hm do we want length 3 palindromes? If so, each number can only occur
  // 3 times maximum. 4 will result in length 5 palindromes.
  // 1 1 2 3 2 1
  //
  // 1 1 2 3 4 4 3 2 1
  // 111,121,131,141,141,131,121
  // 1 1 2 3 4 5 6 7 7 6 5 4 3 2 1
  //
  // Nevermind...
  // Notice that with a pair of '1's at both ends, i.e.,
  // 1 x x x x x x 1   (n=8)
  // There are already n-2 palidrome subsequences.
  // If another '1' is add like in TC 1
  // 1 1 x x x x x 1
  // The outer pair contributes n-2.
  // The inner pair contributes n-3
  // n-2 + n-3 > n...
  // If everything is distinct in between, no >3-length palindromes will be
  // created...
  int n;
  std::cin >> n;

  std::vector<int> v(n, 1);
  for (int x = 2; x < n - 1; ++x) {
    v[x] = x;
  }

  for (int x : v) {
    std::cout << x << ' ';
  }
  std::cout << '\n';
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
