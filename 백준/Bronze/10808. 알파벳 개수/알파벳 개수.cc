#include <iostream>

using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  string str;
  cin >> str;
  int alpha[26] = {0};
  
  for (char c : str) {
    alpha[c - 'a']++;
  }
  
  for (auto i : alpha) {
    cout << i << " ";
  }
}