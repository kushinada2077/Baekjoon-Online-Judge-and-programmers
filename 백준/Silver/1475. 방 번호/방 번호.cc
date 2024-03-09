#include <iostream>
#include <algorithm>

using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n;
  int d[10] = {};
  cin >> n;

  while (n > 0) { 
    d[n % 10]++;
    n /= 10;
  }

  int aver = (d[6] + d[9] + 1) / 2;
  d[6] = aver;
  d[9] = 0;
  int sum = *max_element(begin(d), end(d));
  cout << sum;
}