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

bool isPrime(long long N) {  // good enough prime test
  if (N < _sieve_size) {
    return bs[N];  // O(1) for small primes
  }
  for (int i = 0; i < (int)p.size() && p[i] * p[i] <= N; ++i) {
    if (N % p[i] == 0) {
      return false;
    }
  }
  return true;  // slow if N = large prime
}  // note: only guaranteed to work for N <= (last prime in vll p)^2

bool prime(i64 N) {
  if (N <= 2) {
    return N == 2;
  }

  if (N % 2 == 0) {
    return false;
  }

  for (i64 i = 3; (i * i) <= N; i += 2) {
    if (N % i == 0) {
      return false;
    }
  }
  return true;
}

void solve() {
  // To obtain y, repeat k times the decimal representation of x(without leading
  // zeros)
  // Check if y is prime.
  // Wow. Mod Inverse? Wait. Not necessarily
  int x, k;
  std::cin >> x >> k;

  if (k > 1) {
    std::string num = std::to_string(x);
    if (std::all_of(num.begin(), num.end(), [](char c) { return c == '1'; })) {
      int n = num.size();  // number of 1s
      int repeats = n * k;

      if (repeats == 2 || repeats == 19 || repeats == 23) {
        std::cout << "YES\n";
        return;
      }
    }
    std::cout << "NO\n";
    return;
  }

  std::cout << (prime(x) ? "YES" : "NO") << '\n';
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
