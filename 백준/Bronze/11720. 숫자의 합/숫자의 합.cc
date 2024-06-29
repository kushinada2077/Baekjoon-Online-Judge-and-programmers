#define ll long long
#include <iostream>
#include <set>
#include <vector>
using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  string s;
  int a, sum = 0;
  cin >> a >> s;
  for (auto c : s) {
    sum += c - '0';
  }
  cout << sum;
}