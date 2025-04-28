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
  // Given a sequence a1,a2,...,an
  // and a segment [l, r]
  //
  // Perform exactly once:
  // - Choose any SUBSEQUENCE of the sequence a and reverse it.
  // Find the minimum value of al + ... + ar, i.e., the sum of the sequence
  // in the segment.
  // First observation is that subsequence, means that if we pick an element
  // inside the segment, and one outside the segment, we can bring that element
  // outside/inside.
  // Thus, the maximum subsequence length to be considered is k * 2, where
  // k = min(r-l+1, n - (r-l+1))
  // Is this useful?? Can this help us??
  // Find the k biggest elements in the segment, and k smallest elements
  // outside, and swap them?
  // x2 heaps.
  //
  // WARNING: This assumption is not accurate. The segment could be in the
  // middle of the sequence, resulting in [..., l, ..., r, ...]
  // Then, picking an element outside of the segment, on the left and on the
  // right, along with two in the segment, will effectively result in zero
  // change.
  // e.g., [1, 4, 4, 1], l=2, r=3 => initial_sum = 4 + 4 = 8.
  // Picking the biggest 2 in the segment and smallest 2 outside will still
  // result in [1, 4, 4, 1].
  int n, l, r;
  std::cin >> n >> l >> r;
  --l, --r;  // 1-indexed to 0-indexed.

  std::vector<i64> a(n);
  for (auto& x : a) {
    std::cin >> x;
  }

  std::priority_queue<int> inside, outside;
  i64 segment = 0LL;
  for (int i = 0; i < n; ++i) {
    if (i >= l && i <= r) {
      segment += a[i];
      inside.push(a[i]);
    } else {
      outside.push(-a[i]);  // negated for minHeap.
    }
  }

  int k = std::min(r - l + 1, n - (r - l + 1));
  while (k-- && inside.top() > -outside.top()) {
    segment = segment - inside.top() + (-outside.top());
    inside.pop();
    outside.pop();
  }

  std::cout << segment << '\n';
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
