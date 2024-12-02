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
  // Construct a permutation p of length n such that pi + pi+1 is composite over
  // all 1 <= i <= n-1. (note nth element is not included, cos we want adjacent
  // sums)
  // Output -1 otherwise.
  // Permutation => Distinct n integers from 1 to n.
  // x is composite if it has at least one other divisor other than 1 and x.
  //
  // Seems relatively simple. '1' can not be paired with any other prime
  // numbers. The first non-prime is 4.
  // Ooops. Was thinking about multiplication instead of sum.
  // Hm. Can we utilize multiplication to help though?
  // EXPLOIT parity. ODD + ODD = EVEN. EVEN + EVEN = EVEN.
  // EVEN numbers are COMPOSITE.
  // Therefore, we can pair all the evens together, all the odds together.
  // This leaves us the middle, where there is an ODD + EVEN = ODD.
  // 3, 5, 7 are all primes.
  // 1+2, 3+2 | 1+4, 3+2, 5+2, 5+4 works
  // for n <= 4, no answer.
  // for n >= 5, the middle element must be ..., 5, 4,...
  //
  // Therefore, Even n is trivial.
  // how to handle odd n?
  int n;
  std::cin >> n;

  if (n <= 4) {
    std::cout << "-1\n";
    return;
  }

  std::vector<int> evens;
  evens.reserve((n + 1) / 2);
  std::vector<int> odds;
  odds.reserve((n + 1) / 2);

  for (int i = 1; i <= n; ++i) {
    if (i == 5 || i == 4) {
      continue;
    }

    if (i % 2 == 0) {
      evens.push_back(i);
    } else {
      odds.push_back(i);
    }
  }

  for (int x : evens) {
    std::cout << x << ' ';
  }
  std::cout << 4 << ' ' << 5 << ' ';

  for (int x : odds) {
    std::cout << x << ' ';
  }
  std::cout << '\n';
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
