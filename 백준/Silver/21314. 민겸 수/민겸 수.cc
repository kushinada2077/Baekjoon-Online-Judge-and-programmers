#include <algorithm>
#include <climits>
#include <deque>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <tuple>
#include <vector>
#define fastio cin.tie(0)->sync_with_stdio(0);
#define for_in(n) for (int i = 0; i < n; ++i)
#define si(x) int(x.size())
#define all(x) (x).begin(), (x).end()
#define pb(...) push_back(__VA_ARGS__)
#define X first
#define Y second
#define ROOT 1
using ll = long long;
using namespace std;

int main() {
  fastio;
  string s;
  cin >> s;
  string mx = "", mn = "";
  int cnt = 0;
  for (auto& c : s) {
    if (c == 'K') {
      mx += '5';
      for (int i = 0; i < cnt; ++i) mx += '0';
      cnt = 0;
    } else cnt++;
  }
  for (int i = 0; i < cnt; ++i) mx += '1';
  cnt = 0;
  for (auto& c : s) {
    if (c == 'K') {
      if (cnt) mn += '1';
      for (int i = 0; i < cnt - 1; ++i) {
        mn += '0';
      }
      mn += '5';
      cnt = 0;
    } else cnt++;
  }
  if (cnt) mn += '1';
  for (int i = 0; i < cnt - 1; ++i) mn += '0';
  cout << mx << "\n" << mn << "\n";
}