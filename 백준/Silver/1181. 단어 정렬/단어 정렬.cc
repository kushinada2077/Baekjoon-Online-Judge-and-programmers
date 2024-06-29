#define ll long long
#include <algorithm>
#include <iostream>
#include <unordered_set>
#include <vector>
using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n;
  cin >> n;
  unordered_set<string> word;
  string s;
  while (n--) {
    cin >> s;
    word.insert(s);
  }
  vector<string> ans(word.begin(), word.end());
  sort(ans.begin(), ans.end(), [](string a, string b) {
    if (a.size() == b.size()) {
      return a < b;
    } else
      return a.size() < b.size();
  });
  for (auto s : ans) cout << s << "\n";
}