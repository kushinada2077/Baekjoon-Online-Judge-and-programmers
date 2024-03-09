#include <algorithm>
#include <iostream>

using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  
  int n, v, d[201] = {};

  cin >> n;
  for (int i = 0; i < n; i++) {
    int tmp; cin >> tmp;
    d[tmp + 100]++; 
  }
  cin >> v;
  
  cout << d[v + 100];
}