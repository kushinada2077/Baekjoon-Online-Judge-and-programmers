#define ll long long
#include <iostream>
#include <vector>
using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int h, m;
  cin >> h >> m;
  int sum = (60 * h + m + 1395) % 1440;
  h = sum / 60;
  m = sum % 60;
  cout << h << " " << m;
}