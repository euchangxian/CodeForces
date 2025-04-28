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
  // array a with n  positive integers.
  // positive integer k
  // Create B from A:
  // - B contain NxK integers
  // - first N numbers of B is same as A
  // - for i > N, b[i] = b[i-N] (repeat k  times, cyclic array-like)
  //
  // Given x, count positions 1 <= l <= N*K such that there exists r >= l,
  // sum(B[l..r]) is at least x.
  //
  // Sliding window?
  // For each L, expand right. Not viable tho. N*K.
  // Wait, only need to do O(N) window, before pattern repeats.
  // Abit difficult to handle edge cases though
  // BSTA?
  i64 N, K, X;
  std::cin >> N >> K >> X;

  std::vector<i64> A(N);
  i64 total = 0;
  for (int i = 0; i < N; ++i) {
    std::cin >> A[i];
    total += A[i];
  }

  if (K * total < X) {
    std::cout << 0 << '\n';
    return;
  }

  auto feasible = [N, K, X, total, &A](i64 target) {
    i64 diff = N * K - target;
    i64 sum = (diff / N) * total;

    for (int i = 0; i < diff % N; ++i) {
      sum += A[N - i - 1];
    }

    return sum >= X;
  };

  i64 l = 0, r = N * K, result = 0;

  while (l < r) {
    i64 mid = l + (r - l + 1) / 2;

    if (feasible(mid)) {
      l = mid;
    } else {
      r = mid - 1;
    }
  }

  std::cout << l + 1 << '\n';
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
