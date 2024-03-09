#include <algorithm>
#include <iostream>
#include <list>
using namespace std;

struct ListNode {
  int val;
  ListNode* next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode* next) : val(x), next(next) {}
};

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n, k;
  vector<string> arr;
  cin >> n >> k;
  ListNode* dummyHead = new ListNode();
  ListNode* cur = dummyHead;

  for (int i = 0; i < n; i++) {
    ListNode* newNode = new ListNode(i + 1);
    cur->next = newNode;
    cur = cur->next;
  }

  cur->next = dummyHead->next;
  cur = dummyHead->next;

  while (true) {
    for (int i = 0; i < k - 1; i++) {
      cur = cur->next;
    }

    arr.push_back(to_string(cur->val));
    if (cur->next == cur) break;
    arr.push_back(", ");
    cur->val = cur->next->val;
    cur->next = cur->next->next;
  }

  cout << "<";
  for (auto c : arr) cout << c;
  cout << ">";
}