#include <algorithm>
#include <iostream>

using namespace std;

bool comp(int a, int b) {
  return abs(a) < abs(b);  
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int ans = 0, d[26] = {};
  string str1, str2;
  cin >> str1 >> str2;
  for (auto c : str1) {
    d[c - 'a']++;
  } 
  for (auto c : str2) {
    d[c - 'a']--;
  }
  for (auto i : d) {
    ans += abs(i);
  } 
  
  cout << ans;
}