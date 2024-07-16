#include <algorithm>
#include <deque>
#include <iostream>
#include <unordered_set>
#include <vector>
#define ll long long
#define fastio cin.tie(0)->sync_with_stdio(0);
#define for_in(n) for (int i = 0; i < n; ++i)
#define si(x) int(x.size())
#define all(x) (x).begin(), (x).end()
#define pb(...) push_back(__VA_ARGS__)
#define X first
#define Y second
using namespace std;

bool is_cycle(int a) {
  unordered_set<int> s;
  int cur = a;
  s.insert(cur);
  while (true) {
    int nxt = 0;
    while (cur > 0) {
      int l = cur % 10;
      nxt += l * l;
      cur /= 10;
    }
    if (nxt == 1) return false;
    if (s.find(nxt) != s.end()) return true;
    s.insert(nxt);
    cur = nxt;
  }
}
int main() {
  fastio;
  int n;
  cin >> n;
  vector<bool> is_prime(n + 1, true);
  is_prime[1] = false;
  for (int i = 2; i * i <= n; ++i) {
    for (int j = i * i; j <= n; j += i) {
      is_prime[j] = false;
    }
  }
  for (int i = 1; i <= n; ++i) {
    if (!is_prime[i]) continue;
    if (!is_cycle(i)) cout << i << "\n";
  }
}