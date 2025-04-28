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
// constexpr int MOD = 1'000'000'007;
constexpr int MOD = 998244353;

i64 modBinomial(i64 n, i64 r, i64 mod = MOD) {
  if (r > n - r) {
    r = n - r;  // Use symmetry: C(n,r) = C(n,n-r)
  }

  i64 result = 1;
  for (i64 i = 1; i <= r; ++i) {
    result = (result * (n - i + 1)) % mod;

    // Calculate modular multiplicative inverse of i
    // For prime modulo, we can use Fermat's little theorem: i^(mod-1) ≡ 1 (mod
    // p) So i^(mod-2) is the modular multiplicative inverse of i
    i64 inv = 1;
    i64 base = i;
    i64 exp = mod - 2;
    while (exp > 0) {
      if (exp & 1) {
        inv = (inv * base) % mod;
      }
      base = (base * base) % mod;
      exp >>= 1;
    }

    result = (result * inv) % mod;
  }

  return result;
}

i64 modexp(i64 a, i64 b, i64 m = MOD) {
  i64 res = 1 % m;
  a %= m;
  while (b > 0) {
    if (b & 1) {
      res = (res * a) % m;
    }
    a = (a * a) % m;
    b >>= 1;
  }
  return res;
}

void solve(std::vector<i64>& fact, std::vector<i64>& invfact) {
  // Construct s such that for each (i, j)
  // IF s[i] == s[j], THEN |i - j| % 2 == 0,
  // and must adhere to the specified number of occurences per character.
  //
  // COUNT number of distinct strings.
  //
  // How to count?
  // Each duplicate occurences need to be placed in EVEN/ODD indices only.
  //

  // length of final string
  i64 N = 0;
  std::array<int, 26> occurences{};
  for (int i = 0; i < 26; ++i) {
    std::cin >> occurences[i];
    N += occurences[i];
  }

  i64 oddPos = (N + 1) / 2;
  i64 evenPos = N / 2;

  i64 arrangement = (fact[oddPos] * fact[evenPos]) % MOD;
  for (int i = 0; i < 26; i++) {
    arrangement = (arrangement * invfact[occurences[i]]) % MOD;
  }

  // DP to count valid assignments of letters to odd positions.
  std::vector<int> dp(oddPos + 1, 0);
  dp[0] = 1;
  for (int i = 0; i < 26; i++) {
    if (occurences[i] == 0) {
      continue;  // Letter not present (0! = 1) -- no effect.
    }

    int w = occurences[i];
    std::vector<int> curr(oddPos + 1, 0);
    for (int j = 0; j <= oddPos; j++) {
      if (dp[j] == 0) {
        continue;
      }

      // assign letter i to even group (adds 0 to odd sum)
      curr[j] = (curr[j] + dp[j]) % MOD;
      // assign letter i to odd group (adds w)
      if (j + w <= oddPos) {
        curr[j + w] = (curr[j + w] + dp[j]) % MOD;
      }
    }
    dp = std::move(curr);
  }

  // dp[oddPos] is the number of valid assignments.
  i64 validAssignments = dp[oddPos];
  i64 ans = (arrangement * validAssignments) % MOD;
  std::cout << ans % MOD << "\n";
}

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  // Precompute factorials and inverse factorials up to 500000.
  int MAX = 500000;
  std::vector<i64> fact(MAX + 1), invfact(MAX + 1);
  fact[0] = 1;
  for (int i = 1; i <= MAX; i++) {
    fact[i] = fact[i - 1] * i % MOD;
  }
  invfact[MAX] = modexp(fact[MAX], MOD - 2, MOD);
  for (int i = MAX; i >= 1; i--) {
    invfact[i - 1] = invfact[i] * i % MOD;
  }

  int tc{1};
  std::cin >> tc;

  while (tc--) {
    solve(fact, invfact);
  }

  return 0;
}
