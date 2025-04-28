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

class FenwickTree {
 public:
  FenwickTree(int n, std::vector<i64>& nums) : n(n), tree(n + 1, 0) {
    for (int i = 1; i <= n; ++i) {
      tree[i] = std::abs(nums[i - 1]);

      int parent = i + (i & -i);
      if (parent <= n) {
        tree[parent] += tree[i];
      }
    }
  }

  i64 query(int l, int r) const { return prefix(r) - prefix(l - 1); }

  void update(int i, i64 diff) {
    for (; i <= n; i += i & -i) {
      tree[i] += diff;
    }
  }

  i64 prefix(int i) const {
    i64 sum = 0;
    for (; i > 0; i -= i & -i) {
      sum += tree[i];
    }
    return sum;
  }

  i64 suffix(int i) const { return query(i, n + 1); }

 private:
  int n;
  std::vector<i64> tree;
};

void solve() {
  // array a of length n consisting of NON-ZERO integers (can be negative).
  // Initially, 0 coins.
  // Until a is empty: Let m be the current size of a. Select i in [1..m], gain
  // |ai| coins, then:
  // - if ai < 0, replace a with [a1, a2, ..., ai-1], i.e., delete the suffix
  //   beginning with ai
  // - otherwise, ai > 0, replace a with [ai+1, ..., am], i.e., delete the
  //   prefix ending with ai.
  // Find maximum coins at the end.
  // Feels like DP, considering we need to make choices.
  // What about prefix/suffix sums, then difference array to determine which
  // index gives us the maximum gain?
  // If nums[i] is <0, then take the difference with the suffix sum.
  // otherwise, take the difference with prefix sum.
  // Seems right. Run through an example?
  // Hm, the thing is, do we take the value as-is when determining the prefix
  // sum? or the abs? Seems to be the abs since we want the score.
  // nums  =     3, 1, 4, -1, -5, -9
  // prefix=     0  3  4  8    9   14  23
  // suffix= 23 20 19 15  14   9   0
  // diff  =     3 -2  0           9  // ah may have to update prefix of 1,4 if
  //                                     3 is removed. Fenwick tree lol?
  // Okay, what about two pointer? Difference array is definitely close.
  //
  // But note that we can remove all positive prefix, and all negative suffix
  // We only have to make a decision when encountering a negative at the prefix,
  // and vice versa.
  // WLOG: is the benefit of removing the entire suffix worth the gain in score.
  // And if not, then skip it.
  // In this way, can we avoid re-computation of prefix/suffix?
  int n;
  std::cin >> n;

  std::vector<i64> nums(n);
  for (i64& x : nums) {
    std::cin >> x;
  }

  std::vector<i64> prefix(n + 1), suffix(n + 1);
  for (int i = 0; i < n; ++i) {
    prefix[i + 1] = prefix[i];
    if (nums[i] > 0) {
      prefix[i + 1] += nums[i];
    }
  }

  for (int i = n - 1; i >= 0; --i) {
    suffix[i] = suffix[i + 1];
    if (nums[i] < 0) {
      suffix[i] += -nums[i];
    }
  }

  i64 score = 0;

  // For each split point
  for (int i = 0; i <= n; ++i) {
    score = std::max(score, prefix[i] + suffix[i]);
  }

  std::cout << score << '\n';
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
