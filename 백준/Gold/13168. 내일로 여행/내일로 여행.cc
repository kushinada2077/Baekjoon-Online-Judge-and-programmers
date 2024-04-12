#define TUPLE tuple<int, int, int>
#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

const int INF = 0x3f3f3f3f;
int N, R, M, K, c, U, V;
int d[101][101];
int d2[101][101];
string city, u, v, tp;
unordered_map<string, int> to_num;
vector<int> plan;

int get_discount(string type, int val) {
  if (type == "Mugunghwa")
    return 0;
  else if (type == "ITX-Saemaeul")
    return 0;
  else if (type == "ITX-Cheongchun")
    return 0;
  else if (type == "S-Train")
    return val / 2;
  else if (type == "V-Train")
    return val / 2;
  else
    return val;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> N >> R;

  for (int i = 0; i < N; i++) {
    fill(d[i], d[i] + N + 1, INF);
    fill(d2[i], d2[i] + N + 1, INF);
    d[i][i] = d2[i][i] = 0;
    cin >> city;
    if (to_num.find(city) != to_num.end()) continue;
    to_num[city] = to_num.size();
  }
  N = to_num.size();

  cin >> M;
  for (int i = 0; i < M; i++) {
    cin >> city;
    plan.push_back(to_num[city]);
  }
  cin >> K;
  for (int i = 0; i < K; i++) {
    cin >> tp >> u >> v >> c;
    c *= 2;
    U = to_num[u];
    V = to_num[v];
    d[U][V] = d[V][U] = min(c, d[U][V]);
    c = get_discount(tp, c);
    d2[U][V] = d2[V][U] = min(c, d2[U][V]);
  }

  for (int k = 0; k < N; k++) {
    for (int i = 0; i < N; i++) {
      for (int j = 0; j < N; j++) {
        if (d[i][j] > d[i][k] + d[k][j]) d[i][j] = d[i][k] + d[k][j];
        if (d2[i][j] > d2[i][k] + d2[k][j]) d2[i][j] = d2[i][k] + d2[k][j];
      }
    }
  }

  int no_railro = 0, railro = 2 * R;

  int sz = plan.size();
  for (int i = 1; i < sz; i++) {
    U = plan[i - 1];
    V = plan[i];
    no_railro += d[U][V];
    railro += d2[U][V];
  }

  if (railro < no_railro && N != 1)
    cout << "Yes";
  else
    cout << "No";
}