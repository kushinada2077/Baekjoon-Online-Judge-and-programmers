class Node:
  def __init__(self, data):
    self.data = data
    self.prev = None
    self.next = None

class LinkedList:
  def __init__(self):
    self.head = Node(None)
  
  def insert(self, addr, data):
    newNode = Node(data)
    newNode.next = addr.next
    newNode.prev = addr
    if (addr.next): addr.next.prev = newNode
    addr.next = newNode 

  def erase(self, addr):
    if addr == self.head: return
    if (addr.next == None):
      addr.prev.next = None
      return
    
    addr.prev.next = addr.next
    addr.next.prev = addr.prev
  
  def traverse(self):
    cur = self.head.next

    while cur:
      print(cur.data, end="")
      cur = cur.next

text = input()
N = int(input())
ll = LinkedList()
cursor = ll.head

for c in text:
  ll.insert(cursor, c)
  cursor = cursor.next

for i in range(N):
  splited = input().split()
  op = splited[0]

  if op == "L":
    if cursor == ll.head: continue
    cursor = cursor.prev

  elif op == "D":
    if cursor.next == None: continue
    cursor = cursor.next

  elif op == "B":
    if cursor == ll.head: continue
    ll.erase(cursor)
    cursor = cursor.prev

  elif op == "P":
    c = splited[1]
    ll.insert(cursor, c) 
    cursor = cursor.next

ll.traverse()