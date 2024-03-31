#include <algorithm>
#include <iostream>

using namespace std;

int heap[100005];
int sz = 0;  // heap에 들어있는 원소의 수

void push(int x) {
  int idx = ++sz;
  while (idx != 1) {
    if (x >= heap[idx / 2]) break;
    heap[idx] = heap[idx / 2];
    idx /= 2;
  }
  heap[idx] = x;
}

int top() {
  if (!sz) return 0;
  return heap[1];
}

void pop() {
  if (!sz) return;
  int elem = heap[sz--];
  int idx = 1;
  while (idx * 2 <= sz) {
    int lIdx = idx * 2, rIdx = idx * 2 + 1;
    int minIdx = lIdx;
    if (rIdx <= sz && heap[rIdx] < heap[lIdx]) minIdx = rIdx;
    if (heap[minIdx] >= elem) break;
    heap[idx] = heap[minIdx];
    idx = minIdx;
  }

  heap[idx] = elem;
};

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int N, x;
  cin >> N;
  while (N--) {
    cin >> x;
    if (x) {
      push(x);
    } else {
      cout << top() << "\n";
      pop();
    }
  }
}