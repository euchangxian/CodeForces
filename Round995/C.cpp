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
#include <map>
#include <numeric>
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
  // n different questions from 1 to n.
  // m different lists of questions, each list contains n-1 different questions
  // Each of the m lists is characterized by ai, the index of the question NOT
  // present in the list.
  //
  // Monocarp knows the answer for k questions. Given a list, he will only pass
  // if he answers all the questions.
  // Doesnt this mean k have to be at least n-1 to even consider passing?
  // The difficulty is only if k = n-1, for k < n-1, all fail. For k > n-1 = n,
  // all pass.
  i64 n, m, k;
  std::cin >> n >> m >> k;

  std::vector<i64> a(m);
  for (i64& i : a) {
    std::cin >> i;
  }

  std::vector<i64> q(k);
  for (i64& i : q) {
    std::cin >> i;
  }

  if (k < n - 1) {
    std::cout << std::string(m, '0') << '\n';
    return;
  }

  if (k == n) {
    std::cout << std::string(m, '1') << '\n';
    return;
  }

  // otherwise, find the missing element in the list of questions Monocarp knows
  // the answer to.
  i64 missing =
      (n * (n + 1) / 2) - std::reduce(q.begin(), q.end(), 0LL, std::plus<>{});
  for (int idx : a) {
    if (idx == missing) {
      std::cout << '1';
    } else {
      std::cout << '0';
    }
  }
  std::cout << '\n';
}

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  int tc;
  std::cin >> tc;

  while (tc--) {
    solve();
  }

  return 0;
}
