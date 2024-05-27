
#define PAIR pair<long long, int>
#define ll long long
#include <algorithm>
#include <iostream>
#include <map>
#include <vector>
using namespace std;

int n;
vector<int> failure(const string& s) {
  vector<int> f(s.size());
  int j = 0;
  for (int i = 1; i < s.size(); ++i) {
    while (j > 0 && s[i] != s[j]) j = f[j - 1];
    if (s[i] == s[j]) f[i] = ++j;
  }

  return f;
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n;
  while (n--) {
    string a, w, s;
    cin >> a >> w >> s;
    unordered_map<char, int> idx_map;
    vector<int> ans;
    vector<int> f = failure(w);
    int loop = a.size();
    for (int i = 0; i < a.size(); ++i) {
      idx_map[a[i]] = i;
    }
    for (int shift = 0; shift < loop; ++shift) {
      int cnt = 0;
      int j = 0;
      for (int i = 0; i < s.size(); ++i) {
        while (j > 0 && s[i] != a[(idx_map[w[j]] + shift) % loop]) j = f[j - 1];
        if (s[i] == a[(idx_map[w[j]] + shift) % loop]) j++;
        if (j == w.size()) {
          if (cnt) {
            ans.clear();
            break;
          }
          ans.push_back(shift);
          j = f[j - 1];
          cnt++;
        }
      }
    }

    if (ans.size() == 0)
      cout << "no solution\n";
    else if (ans.size() == 1)
      cout << "unique: " << ans[0] << "\n";
    else {
      sort(ans.begin(), ans.end());
      cout << "ambiguous:";
      for (auto n : ans) cout << " " << n;
      cout << "\n";
    }
  }
}