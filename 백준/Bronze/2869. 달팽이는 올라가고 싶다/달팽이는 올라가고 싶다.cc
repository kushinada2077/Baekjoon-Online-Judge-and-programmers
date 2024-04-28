#define TUPLE tuple<int, int, int>
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
int a, b, v, ans;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> a >> b >> v;

  cout << (v - b - 1) / (a - b) + 1;
}