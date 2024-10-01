#include <algorithm>
#include <iostream>
#include <queue>
#include <stack>
#include <unordered_map>
#include <vector>
#define PATH "/Users/leedongha/Downloads/PS/input.txt"
#define fastio cin.tie(0)->sync_with_stdio(0);
#define for_in(n) for (int i = 0; i < n; ++i)
#define si(x) int(x.size())
#define all(x) (x).begin(), (x).end()
#define pb(...) push_back(__VA_ARGS__)
#define X first
#define Y second
#define ROOT 1
#define INF 0x3f3f3f3f
using ll = long long;
using namespace std;

int main() {
  fastio;
  int n, x;
  cin >> n;
  vector<int> seq, a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
    seq.pb(i + 1);
  }

  do {
    bool chk = 1;
    vector<int> tmp(n);
    for (int i = 0; i < n; ++i) {
      int cnt = 0;
      for (int j = 0; j < i; ++j) {
        if (seq[j] > seq[i]) cnt++;
      }
      tmp[seq[i] - 1] = cnt;
    }

    for (int i = 0; i < n; ++i) {
      if (a[i] != tmp[i]) {
        chk = 0;
        break;
      }
    }

    if (chk) {
      for (auto& i : seq) cout << i << " ";
      break;
    }

  } while (next_permutation(all(seq)));
}