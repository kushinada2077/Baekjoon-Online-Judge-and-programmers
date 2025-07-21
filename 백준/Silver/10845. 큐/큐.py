class Node:
  def __init__(self, val):
    self.next = None
    self.val = val 

class Queue:
  def __init__(self):
    self.head = Node(0)
    self.tail = self.head
    self.sz = 0
  
  def size(self):
    return self.sz
  def push(self, val):
    newNode = Node(val)
    self.tail.next = newNode
    self.tail = self.tail.next 
    self.sz += 1
  def front(self):
    if self.size() == 0:
      return
    return self.head.next.val
  def back(self):
    if self.size() == 0:
      return
    return self.tail.val
      

  def pop(self): 
    if self.size() == 0:
      return 
    t = self.head.next
    self.head.next = t.next
    self.sz -= 1
    if self.tail == t:
      self.tail = self.head
    del t

N = int(input())
Q = Queue()
ans = []
for i in range(N):
  l = input().split(" ")
  op = l[0]

  if op == 'push':
    Q.push(l[1])

  elif op == 'pop':
    if Q.size() == 0:
      ans.append('-1')
    else:
      ans.append(Q.front())
      Q.pop()

  elif op == 'size':
    ans.append(str(Q.size()))

  elif op == 'empty':
    if Q.size() == 0:
      ans.append('1')
    else:
      ans.append('0')

  elif op == 'front':
    if Q.size() == 0:
      ans.append('-1')
    else:
      ans.append(Q.front())

  elif op == 'back':
    if Q.size() == 0:
      ans.append('-1')
    else:
      ans.append(Q.back())
     
print('\n'.join(ans)) 