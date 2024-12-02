#include <algorithm>
#include <array>
#include <bitset>
#include <climits>
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
  // set S of all integers from l to r inclusive.
  // Perform operation:
  // 1. Choose x in S, such that the number of multiples of x in S is at least
  //    k (including x itself).
  // 2. Remove x from S.
  // Find the maximum possible number of operations that can be performed.
  //
  // First note: a number may be a multiple of multiple numbers.
  // i.e., {2, 3, 6}, where 6 is a multiple of both 2 and 3.
  // Therefore, it seems that we want to remove smaller numbers first.
  //
  // ... Seems like question constraints require an O(1) solution though.
  // What is the insight????
  // NOTE:
  // Suppose I have a sequence S = {3, 4, 5, 6, 7, 8, 9}, k = 2
  // Then, we know that for a number x in S to have at least k multiples,
  // x must be small enough such that x, 2x, ... all fit in S.
  // Therefore, suppose the sequence starts from 1, then kx <= r means that
  // there are k multiples of x.
  // Therefore, by taking the largest number in the Set, r, divide by k,
  // i.e., r/k, will give us the largest number in the Set that has k multiples.
  // This is because any smaller number in the Set will have at least k
  // multiples, and therefore will all be valid choices for removals.
  // Therefore, if the sequence starts from 0, then r/k will be our answer!
  // However, we are given l, the start of the Set. We want to minus those
  // numbers from 0..l-1!
  int l, r, k;
  std::cin >> l >> r >> k;

  std::cout << std::max(0, r / k - (l - 1)) << '\n';
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
