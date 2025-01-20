#include <algorithm>
#include <array>
#include <bitset>
#include <climits>
#include <cmath>
#include <cstddef>
#include <cstdint>
#include <cstdlib>
#include <deque>
#include <functional>
#include <ios>
#include <iostream>
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
  // interactive.
  //
  // hidden BINARY array a of length n, n is a power of 2.
  // hidden integer k, 2 <= k <= n-1
  // a contains exactly one '1'.
  //
  // Define range sum s(l, r) = al + al+1 + ... ar, i.e., inclusive.
  //
  // Interactive Query: given (l, r), 1 <= l <= r <= n, return 0 or 1:
  // - if r-l+1 < k, return s(l, r)
  // - if (r-l+1) >= k, return 1 - s(l, r)
  // i.e., if the queried range is greater than k, the opposite answer is
  // returned.
  //
  // At most 33 queries, where n<=2^30.
  // OUTPUT k, 2 <= k <= n-1.
  // Seems to hint at an O(logn) solution. Binary Search? Simplifying further,
  // the range sum doesnt seem useful. Its just to inform us whether the '1' is
  // in the queried range.
  //
  // Given that we want to find k, binary search on k?
  // Guess k = n/2
  // query both halves of the array. At this point, queries will give opposite
  // answers, and we do not know which halve contains the '1'.
  //
  // What about dividing the array into 4 segments, instead of 2.
  // First query, k = n/2 still, but have the queries overlap in the middle.
  // i.e., q1 = [0, n/2], q2 = [n/4, 3n/4].
  // Suppose 1 is in the range [0, 3n/4], i.e., in one of the 3 segments
  // covered.
  // If queries are unequal => k is small enough. Therefore, recurse on the
  // halve that returned '1', to find the correct value of k.
  // More interestingly, if both queries are equal:
  // - both return 1:
  //   - correct (k is small/equal): '1' lies in the overlapping 2nd segment
  //   - incorrect (k is big): '1' lies in the 4th segment that is not queried.
  // - both return 0:
  //   - correct: '1' lies in the 4th segment
  //   - incorrect: '1' lies in the 2nd segment
  //
  // How to query this then? Since we know that '1' is either in the 2nd or 4th
  // segment, depending on the combination of the correctness of k and the
  // previous answer (truth table).
  //
  // HMM. Observe that once we determine the segment containing the '1', we do
  // not need to make multiple queries to make a decision.
  // We can do query->decision->query, making k bigger until it returns the
  // wrong answer '0'.
  // Thus, we can refine our initial queries to 4 non-overlapping queries.
  // We will either get
  // 0 0 0 1, which indicates that k = n/4 is small enough. Thus, subsequent
  // queries must contain the 4th segment, and binary search on the value of k.
  //
  // 1 1 1 0, which indicates that k = n/4 is too big, and recurse on the 4th
  // segment.
  auto query = [](int l, int r) -> int {
    std::cout << '?' << l + 1 << r << std::endl;

    int x;
    std::cin >> x;
    return x;
  };

  int n;
  std::cin >> n;

  // determine where the '1' is.
  int l = 0;
  int r = n - 1;
  int k = 0;  // to be mutated by the loop, and used later. [1..n/4]
  for (int sz = r - l + 1; sz >= 4;) {
    k = sz / 4;
    std::array<std::pair<int, int>, 4> segments{{
        {l, l + k},
        {l + k + 1, l + (2 * k)},
        {l + (2 * k) + 1, l + (3 * k)},
        {l + (3 * k) + 1, sz},
    }};

    std::array<int, 4> answers;
    int numOnes = 0;
    for (int i = 0; i < segments.size(); ++i) {
      auto [qleft, qright] = segments[i];
      answers[i] = query(qleft, qright);
      numOnes += answers[i];
    }

    if (numOnes == 3) {
      // k is too big, recurse on the correct segment.
      auto correct = std::find(answers.begin(), answers.end(), 0);
      l = segments[correct - answers.begin()].first;
      r = segments[correct - answers.begin()].second;
    } else {
      // k is too small. Subsequent queries should involve the range that has
      // '1'
      auto correct = std::find(answers.begin(), answers.end(), 1);
      l = segments[correct - answers.begin()].first;
      r = segments[correct - answers.begin()].second;
      break;
    }
  }

  // segment that has the '1'
  // k may be equal to 1
  const int cleft = l;
  const int cright = r;
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
