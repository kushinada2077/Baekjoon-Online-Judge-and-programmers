#include <algorithm>
#include <iostream>

using namespace std;

const int MX = 1000005;
char dat[MX];
int pre[MX], nxt[MX];
int unused = 1;

void traverse() {
  int cur = nxt[0];
  while (cur != -1) {
    cout << dat[cur];
    cur = nxt[cur];
  }
}

void insert(int addr, char val) {
  dat[unused] = val;
  pre[unused] = addr;
  nxt[unused] = nxt[addr];
  if (nxt[addr] != -1) pre[nxt[addr]] = unused;
  nxt[addr] = unused;
  unused++;
}

void erase(int addr) {
  nxt[pre[addr]] = nxt[addr];
  if (nxt[addr] != 1) pre[nxt[addr]] = pre[addr];
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  fill(pre, pre + MX, -1);
  fill(nxt, nxt + MX, -1);

  string str;
  int n;
  cin >> str;
  cin >> n;
  for (auto c : str) {
    insert(unused - 1, c);
  }
  int cur = unused - 1;
  for (int i = 0; i < n; i++) {
    string op;
    cin >> op;
    if (op == "P") {
      char c;
      cin >> c;
      insert(cur, c);
      cur = nxt[cur];
    }
    else if (op == "L") {
      if (pre[cur] != -1) cur = pre[cur];      
    }
    else if (op == "D") {
      if (nxt[cur] != -1) cur = nxt[cur]; 
    }
    else if (op == "B") {
      if (pre[cur] != -1) {
        erase(cur);
        cur = pre[cur];
      }
    }
  }

  traverse();
}