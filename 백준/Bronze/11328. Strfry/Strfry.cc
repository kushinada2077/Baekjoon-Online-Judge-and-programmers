#include <algorithm>
#include <iostream>

using namespace std;

bool comp(int a, int b) {
  return abs(a) < abs(b);  
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  
  int n; cin >> n;
  for (int i = 0; i < n; i++) {
    int alpha[26] = {};
    string str1, str2;
    cin >> str1 >> str2;
    for (auto c : str1) {
      alpha[c - 'a']++;
    }
    for (auto c : str2) {
      alpha[c - 'a']--;
    }
    
    if (*max_element(begin(alpha), end(alpha), comp)) {
      cout << "Impossible";
    }
    else {
      cout << "Possible";
    }
    cout << "\n";
  }
}