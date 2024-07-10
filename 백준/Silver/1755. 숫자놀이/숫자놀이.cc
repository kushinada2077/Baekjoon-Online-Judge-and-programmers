#include <algorithm>
#include <iostream>
#include <numeric>
#include <queue>
#include <vector>
#define ll long long
#define fastio cin.tie(0)->sync_with_stdio(0);
#define for_in(n) for (int i = 0; i < n; ++i)
#define si(x) int(x.size())
#define all(x) (x).begin(), (x).end()
#define pb(...) push_back(__VA_ARGS__)
using namespace std;

string conv(int n) {
  string ret;
  if (n == 0) ret = "zero";
  if (n == 1) ret = "one";
  if (n == 2) ret = "two";
  if (n == 3) ret = "three";
  if (n == 4) ret = "four";
  if (n == 5) ret = "five";
  if (n == 6) ret = "six";
  if (n == 7) ret = "seven";
  if (n == 8) ret = "eight";
  if (n == 9) ret = "nine";
  return ret;
}
string i2s(int n) {
  vector<string> word;
  while (n > 0) {
    word.pb(conv(n % 10));
    n /= 10;
  }
  reverse(all(word));
  string ret = "";
  for (auto& c : word) ret += c;
  return ret;
}
int main() {
  fastio;
  int m, n;
  cin >> m >> n;
  vector<int> num;
  for (int i = m; i < n + 1; ++i) num.pb(i);
  sort(all(num), [](int& a, int& b) { return i2s(a) < i2s(b); });
  for (int i = 0; i < si(num); ++i) {
    if (i > 0 && i % 10 == 0) cout << "\n";
    cout << num[i] << " ";
  }
}