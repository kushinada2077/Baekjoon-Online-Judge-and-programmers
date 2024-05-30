#define PAIR pair<long long, int>
#define ll long long
#include <algorithm>
#include <iostream>
#include <map>
#include <vector>
using namespace std;

ll mod;
ll pow(ll a, ll b) {
  ll ret = 1;
  while (b) {
    if (b % 2) ret = ret * a % mod;
    a = a * a % mod;
    b /= 2;
  }

  return ret;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  ll a, b;
  cin >> a >> b >> mod;
  cout << pow(a, b);
}