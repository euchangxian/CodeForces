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

long long _sieve_size;
std::bitset<10000010> bs;  // 10^7 is the rough limit
std::vector<long long> p;  // compact list of primes

void sieve(long long upperbound) {  // range = [0..upperbound]
  _sieve_size = upperbound + 1;     // to include upperbound
  bs.set();                         // all 1s
  bs[0] = bs[1] = 0;                // except index 0+1
  for (long long i = 2; i < _sieve_size; ++i) {
    if (bs[i]) {
      // cross out multiples of i starting from i*i
      for (long long j = i * i; j < _sieve_size; j += i) {
        bs[j] = 0;
      }
      p.push_back(i);  // add prime i to the list
    }
  }
}

void solve() {
  int n;
  std::cin >> n;

  int result = 0;
  for (int i = 1; i <= n / 2; ++i) {  // only want ordered pairs a < b
    int nm = n / i;
    result += std::upper_bound(p.begin(), p.end(), nm) - p.begin();
  }
  std::cout << result << '\n';
}

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);
  sieve(1e7);

  int tc{1};
  std::cin >> tc;
  while (tc--) {
    solve();
  }

  return 0;
}
