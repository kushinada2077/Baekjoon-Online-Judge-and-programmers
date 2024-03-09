#include <iostream>

using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int a, b, c;
  cin >> a >> b >> c;
  int res = a * b * c;
  string resStr = to_string(res);
  int nums[10] = { 0 };

  for (auto c : resStr) {
    nums[c - '0']++;
  } 
  
  for (auto i : nums) {
    cout << i << " ";
  }
}