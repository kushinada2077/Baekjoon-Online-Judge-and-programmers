class Stack:
    def __init__(self, capacity):
        self.capacity = capacity
        self.items = [None] * capacity  
        self.top = -1

    def push(self, item):
        if self.top >= self.capacity - 1: 
            return
        self.top += 1
        self.items[self.top] = item

    def pop(self):
        if self.isEmpty():
            return None
        item = self.items[self.top]
        self.top -= 1
        return item

    def peek(self):
        if self.is_empty():  
            return None
        return self.items[self.top]

    def isEmpty(self):
        return self.top == -1

    def size(self):
        return self.top + 1

def isPal(s):
  stack = Stack(len(s) + 1)
  for c in s: stack.push(c)
  idx = 0

  while not stack.isEmpty():
    if stack.pop() != s[idx]: return False
    idx += 1
  
  return True

s =input()

if isPal(s): print(1)
else: print(0)