#include <algorithm>
#include <iostream>
#include <queue>
#include <unordered_map>
#include <vector>
using namespace std;

int N, M;
int deg[1001];
vector<int> adj[1001];
vector<string> ancestors;
vector<string> names;
unordered_map<string, int> to_num;
unordered_map<int, string> to_name;
unordered_map<int, vector<string>> children;
string name, name2;

void phase(int ancestor) {
  queue<int> q;

  q.push(ancestor);
  while (!q.empty()) {
    auto cur = q.front();
    q.pop();
    for (auto nxt : adj[cur]) {
      deg[nxt]--;
      if (deg[nxt] == 0) {
        q.push(nxt);
        children[cur].push_back(to_name[nxt]);
      }
    }
  }
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> N;
  for (int i = 0; i < N; i++) {
    cin >> name;
    names.push_back(name);
    to_num[name] = i;
    to_name[i] = name;
  }
  cin >> M;

  for (int i = 0; i < M; i++) {
    cin >> name >> name2;
    int num1 = to_num[name];
    int num2 = to_num[name2];
    adj[num2].push_back(num1);
    deg[num1]++;
  }

  for (auto name : names) {
    if (deg[to_num[name]] == 0) ancestors.push_back(name);
  }

  sort(ancestors.begin(), ancestors.end());

  cout << ancestors.size() << "\n";
  for (auto ancestor : ancestors) {
    cout << ancestor << " ";
    phase(to_num[ancestor]);
  }
  cout << "\n";

  sort(names.begin(), names.end());
  for (auto name : names) {
    auto this_children = children[to_num[name]];
    cout << name << " " << this_children.size() << " ";
    sort(this_children.begin(), this_children.end());
    for (auto child : this_children) {
      cout << child << " ";
    }
    cout << "\n";
  }
}