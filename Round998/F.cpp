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

constexpr int MOD = 998'244'353;

constexpr int MAX = 100'000;

constexpr auto genPrimes() {
  std::array<bool, MAX + 1> isPrime{};

  for (std::size_t i = 0; i < isPrime.size(); ++i) {
    isPrime[i] = true;
  }

  isPrime[0] = false;
  isPrime[1] = false;

  // Sieve
  for (std::size_t i = 2; i * i <= MAX; ++i) {
    if (isPrime[i]) {
      for (std::size_t j = i * i; j <= MAX; j += i) {
        isPrime[j] = false;
      }
    }
  }

  std::array<int, 9592> primes{};
  std::size_t idx = 0;
  for (std::size_t i = 2; i <= MAX; ++i) {
    if (isPrime[i]) {
      primes[idx++] = static_cast<int>(i);
    }
  }

  return primes;
}

constexpr std::array<int, 9592> primes = genPrimes();

void solve() {
  // count the number of integer arrays a such that for each x in [1..k]:
  // - 1 <= a.length <= n, and
  // - 1 <= a[i] <= k, and
  // - a1 * a2 * ... == x (product of all elements is x)
  //
  // Constraints are tight:
  // k <= 10^5,
  // n <= 9 * 10^8
  //
  // Feels like a counting problem.
  // k == 1 => n different arrays of 1
  // k == 2 => single 2, all 1s. Harder to count.
  //           For each L in [1..n], choose a position for that '2'.
  // k == 3 => single 3, same as 2s
  // k == 4 => single 4, two 2s.
  // ...
  //
  // Is there repeated work? Counting seems TOUGH, considering any growth
  // factor that involves n would likely be too slow.
  //
  // I.e., prime-factorize k. Then do some counting..
  i64 k, n;
  std::cin >> k >> n;
  std::cout << primes.back() << '\n';
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
