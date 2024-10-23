#include <algorithm>
#include <cmath>
#include <iostream>
#include <stack>
#include <vector>
#define PATH "/Users/leedongha/Downloads/PS/input.txt"
#define L_PATH "input.txt"
#define fastio cin.tie(0)->sync_with_stdio(0);
#define rep(n) for (int i = 0; i < n; ++i)
#define si(x) int(x.size())
#define all(x) (x).begin(), (x).end()
#define pb(...) push_back(__VA_ARGS__)
#define X first
#define Y second
#define ROOT 1
#define INF 0x3f3f3f3f
using namespace std;
using ll = long long;
using T = tuple<int, int, int>;
using P = pair<int, int>;

const int MX = 100000;

int n, m, sqrtN;
int arr[MX], mxNode[317], mnNode[317];

int main() {
  fastio;
  fill(mnNode, mnNode + 317, INF);
  cin >> n >> m;
  sqrtN = sqrt(n);
  for (int i = 0; i < n; ++i) cin >> arr[i];
  for (int i = 0; i <= (n / sqrtN); ++i) {
    for (int j = sqrtN * i; j < min(n, sqrtN * (i + 1)); ++j) {
      mxNode[i] = max(mxNode[i], arr[j]);
      mnNode[i] = min(mnNode[i], arr[j]);
    }
  }

  for (int a, b; m--;) {
    cin >> a >> b;
    a--;
    int mx = -1, mn = INF;

    for (int i = (a / sqrtN); i <= (b - 1) / sqrtN; ++i) {
      int st = i * sqrtN, en = (i + 1) * sqrtN;
      if (i == n / sqrtN) en = n;
      if (a <= st && en <= b) {
        mx = max(mx, mxNode[i]);
        mn = min(mn, mnNode[i]);
      } else if (en <= b) {
        for (int j = a; j < en; ++j) {
          mx = max(mx, arr[j]);
          mn = min(mn, arr[j]);
        }
      } else if (a <= st) {
        for (int j = st; j < b; ++j) {
          mx = max(mx, arr[j]);
          mn = min(mn, arr[j]);
        }
      } else {
        for (int j = a; j < b; ++j) {
          mx = max(mx, arr[j]);
          mn = min(mn, arr[j]);
        }
      }
    }
    cout << mn << " " << mx << "\n";
  }
}