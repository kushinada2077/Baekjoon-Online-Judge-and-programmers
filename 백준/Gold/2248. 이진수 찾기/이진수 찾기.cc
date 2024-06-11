#define ll long long
#include <algorithm>
#include <iostream>
#include <unordered_set>
#include <vector>
using namespace std;

ll N, L, I, d[35][35];

ll f(int n, int l) {
  if (d[n][l]) return d[n][l];
  if (n == 0 || l == 0) return 1;

  ll result = f(n - 1, l) + f(n - 1, l - 1);
  d[n][l] = result;
  return result;
}
void track(ll n, ll m, ll i, string& num) {
  if (n == 0) return;
  if (m == 0) {
    while (num.size() < N) num += '0';
    return;
  }
  ll pivot = f(n - 1, m);
  if (i >= pivot) {
    num += '1';
    track(n - 1, m - 1, i - pivot, num);
  } else {
    num += '0';
    track(n - 1, m, i, num);
  }
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> N >> L >> I;
  string num;
  track(N, L, I - 1, num);
  cout << num;
}