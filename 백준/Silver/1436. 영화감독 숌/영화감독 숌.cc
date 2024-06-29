#define ll long long
#include <algorithm>
#include <iostream>
#include <unordered_set>
#include <vector>
using namespace std;

bool end_num(int a) {
  int cnt = 0;
  while (a) {
    if (a % 10 == 6)
      cnt++;
    else
      cnt = 0;
    a /= 10;
    if (cnt > 2) return true;
  }
  return cnt > 2;
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n;
  cin >> n;
  int cnt = 0, num = 666;
  while (cnt != n) {
    if (end_num(num)) cnt++;
    if (cnt == n) {
      cout << num;
      break;
    }
    num++;
  }
}