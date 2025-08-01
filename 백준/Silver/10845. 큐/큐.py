class Node:
  def __init__(self, val):
    self.val = val
    self.next = None
    
class Queue:
  def __init__(self):
    self.sz = 0
    self.head = None
    self.tail = None
  
  def size(self):
    return self.sz
  
  def push(self, val):
    n_node = Node(val)
    if self.size() == 0:
      self.head = self.tail = n_node 
    
    else:
      self.tail.next = n_node
      self.tail = n_node

    self.sz += 1

  def pop(self):
    if self.size() == 0:
      return
    
    t_node = self.head
    self.head = self.head.next
    del t_node
    self.sz -= 1
    if self.size() == 0:
      self.tail = None
  
  def front(self):
    if self.size() == 0:
      return
    return self.head.val
  
  def back(self):
    if self.size() == 0:
      return
    return self.tail.val
  
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