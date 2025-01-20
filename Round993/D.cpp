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
  // given array a of length n, construct array b such that
  // a[i] is the mode of the sequence [b1, b2, ..., bi], i.e., the mode of the
  // prefix of b.
  // given that if all the frequencies are equal, any elements can be considered
  // the mode, we can reduce to some sort of parity problem.
  // Hm.
  // Prefix frequencies? Not exactly, since knowledge of suffix elements is
  // required.
  // Oh lol, think there isnt a need to use only the elements in a to construct
  // b.
  // Therefore, length n => b = [1..n].
  // Some form of cuckoo sorting?
  // Iterate through a, if a[i] is not yet seen, then output a[i], else, output
  // a number x in [1..n] such that x is not yet seen.
  // How to implement lol. Naively, a Set and a Queue or something?
  // What about using the input array in the spirit of cuckoo!
  int n;
  std::cin >> n;

  std::vector<int> a(n);
  std::unordered_set<int> available;
  int x = 1;
  for (int& i : a) {
    std::cin >> i;
    available.insert(x++);
  }

  for (int x : a) {
    if (available.count(x)) {
      std::cout << x << ' ';
      available.erase(x);
    } else {
      std::cout << *available.begin() << ' ';
      available.erase(available.begin());
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
