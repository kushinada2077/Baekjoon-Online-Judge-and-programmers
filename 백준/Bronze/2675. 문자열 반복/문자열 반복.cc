#define ll long long
#include <iostream>
#include <vector>
using namespace std;

string sol(string& s, int repeat) {
  string ret = "";
  for (auto c : s) {
    for (int i = 0; i < repeat; ++i) ret += c;
  }
  return ret;
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int t, repeat;
  cin >> t;
  string s;
  while (t--) {
    cin >> repeat >> s;
    cout << sol(s, repeat) << "\n";
  }
}