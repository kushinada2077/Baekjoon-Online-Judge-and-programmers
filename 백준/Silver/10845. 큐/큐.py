class Queue:
    def __init__(self, max_size=1000005):
        self.dat = [0] * max_size
        self.head = 0
        self.tail = 0

    def push(self, x):
        self.dat[self.tail] = x
        self.tail += 1

    def pop(self):
        self.head += 1
    
    def empty(self):
        return not (self.tail - self.head)

    def front(self):
        return self.dat[self.head]

    def back(self):
        return self.dat[self.tail - 1]


q = Queue()
n = int(input())
ans = []

for i in range(n):
    op = input()
    if op == "pop":
        if q.empty():
            ans.append('-1') 
            continue
        ans.append(q.front())
        q.pop()
    elif op == 'size':
        ans.append(str(q.tail - q.head))
    elif op == 'empty':
        ans.append(str(int(q.empty())))
    elif op == 'front':
        if q.empty():
            ans.append('-1')
            continue
        ans.append(q.front())
    elif op == 'back':
        if q.empty():
            ans.append('-1')
            continue
        ans.append(q.back())
    else:
        num = op.split()[1]
        q.push(num)
print("\n".join(ans))