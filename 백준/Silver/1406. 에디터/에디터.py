class Node:
  def __init__(self, val):
    self.val = val
    self.next = None
    self.prev = None

class LinkedList:
  def __init__(self):
    self.head = None
    self.sz = 0
  
  def size(self):
    return self.sz
  
  def insert(self, val, ptr = None):
    ptr = ptr or self.head
    n_node = Node(val)
    if self.size() == 0:
      self.head = n_node
      n_node.next = n_node
      n_node.prev = n_node
    else:
      if ptr.next != None:
        ptr.next.prev = n_node
      n_node.next = ptr.next
      n_node.prev = ptr
      ptr.next = n_node
    self.sz += 1
  
  def erase(self, ptr):
    if self.size() == 0:
      return
    if self.size() == 1:
      self.head = None 
    else:
      ptr.prev.next = ptr.next
      ptr.next.prev = ptr.prev
    self.sz -= 1
    ret = ptr.prev
    del ptr
    return ret

S = input()
N = int(input())
L = LinkedList()
L.insert(-1)
cursor = L.head
for c in S:
  L.insert(c, cursor)
  cursor = cursor.next

for i in range(N):
  line = input().split()
  if line[0] == 'P':
    L.insert(line[1], cursor)
    cursor = cursor.next
  elif line[0] == 'L' and cursor != L.head:
    cursor = cursor.prev
  elif line[0] == 'D' and cursor.next != L.head:
    cursor = cursor.next
  elif line[0] == 'B' and cursor != L.head:
    cursor = L.erase(cursor)

ptr = L.head.next
ans = []
while ptr != L.head:
  ans.append(ptr.val)
  ptr = ptr.next

print(''.join(ans))