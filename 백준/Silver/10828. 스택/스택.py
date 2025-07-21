import sys

class Node:
  def __init__(self, val):
    self.next = None
    self.val = val

class Stack:
  def __init__(self):
    self.size = 0
    self.head = None
  
  def push(self, val):
    newNode = Node(val)
    newNode.next = self.head
    self.head = newNode
    self.size += 1
    
  def pop(self):
    if self.size == 0:
      return
    t = self.head
    self.head = self.head.next
    self.size -= 1
    del t 

  def top(self):
    if self.size == 0:
      return
    return self.head.val
  

N = int(input())
S = Stack()
ans = []
for i in range(N):
  l = input().split(" ")
  op = l[0]

  if op == 'push':
    S.push(l[1])
  elif op == 'pop':
    if S.size == 0:
      ans.append('-1')
    else:
      ans.append(S.top())
      S.pop()
      

  elif op == 'size':
    ans.append(str(S.size))

  elif op == 'empty':
    if S.size == 0:
      ans.append('1')
    else:
      ans.append('0')

  elif op == 'top':
    if S.size == 0:
      ans.append('-1')
    else:
      ans.append(S.top())
     
print('\n'.join(ans))