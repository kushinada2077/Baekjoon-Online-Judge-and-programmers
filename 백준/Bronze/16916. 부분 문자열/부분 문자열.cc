#include <algorithm>
#include <climits>
#include <deque>
#include <iostream>
#include <numeric>
#include <queue>
#include <tuple>
#include <unordered_map>
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

// 실패함수 f(x) = [0:x+1] 문자열에서 일치하는 접두사, 접미사의 최대 길이

vector<int> failure(const string& s) {
  vector<int> f(si(s));
  int j = 0;
  for (int i = 1; i < si(s); ++i) {
    while (j && s[i] != s[j]) j = f[j - 1];
    if (s[i] == s[j]) f[i] = ++j;
  }
  return f;
}
bool kmp(const string& s, const string& p) {
  vector<int> f = failure(p);
  int j = 0;
  for (int i = 0; i < si(s); ++i) {
    while (j && s[i] != p[j]) j = f[j - 1];
    if (s[i] == p[j]) j++;
    if (j == si(p)) return true;
  }
  return false;
}
int main() {
  fastio;
  string s, p;
  cin >> s >> p;
  cout << kmp(s, p) << "\n";
}