#define PAIR pair<long long, int>
#define ll long long
#include <algorithm>
#include <iostream>
#include <map>
#include <vector>
using namespace std;

ll mod;
ll pow(ll a, ll b) {
  if (b == 1) return a % mod;
  ll val = pow(a, b / 2);
  val = val * val % mod;
  if (b % 2) return a * val % mod;
  return val;
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  ll a, b;
  cin >> a >> b >> mod;
  cout << pow(a, b);
}