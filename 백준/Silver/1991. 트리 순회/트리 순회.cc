#include <algorithm>
#include <cmath>
#include <deque>
#include <iostream>
#include <queue>
#include <tuple>
#include <unordered_set>
#include <vector>
#define fastio cin.tie(0)->sync_with_stdio(0);
#define for_in(n) for (int i = 0; i < n; ++i)
#define si(x) int(x.size())
#define all(x) (x).begin(), (x).end()
#define pb(...) push_back(__VA_ARGS__)
#define X first
#define Y second
using ll = long long;
using namespace std;

vector<char> lc(30, -1), rc(30, -1);
void pre(char v) {
  cout << char(v + 'A');
  if (lc[v] != -1) pre(lc[v]);
  if (rc[v] != -1) pre(rc[v]);
}
void in(int v) {
  if (lc[v] != -1) in(lc[v]);
  cout << char(v + 'A');
  if (rc[v] != -1) in(rc[v]);
}
void post(int v) {
  if (lc[v] != -1) post(lc[v]);
  if (rc[v] != -1) post(rc[v]);
  cout << char(v + 'A');
}
int main() {
  fastio;
  int n;
  cin >> n;
  char a, b, c;
  for (int i = 0; i < n; ++i) {
    cin >> a >> b >> c;
    if (b != '.') lc[a - 'A'] = b - 'A';
    if (c != '.') rc[a - 'A'] = c - 'A';
  }
  pre(0);
  cout << "\n";
  in(0);
  cout << "\n";
  post(0);
  cout << "\n";
}