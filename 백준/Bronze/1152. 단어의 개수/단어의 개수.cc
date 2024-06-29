#define ll long long
#include <iostream>
using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  string s;
  getline(cin, s);
  int cnt = 0;
  for (int i = 0; i < s.size(); ++i) {
    if (s[i] == ' ' && i != 0 && i != s.size() - 1) cnt++;
  }
  if (s == " ")
    cout << "0";
  else
    cout << cnt + 1;
}