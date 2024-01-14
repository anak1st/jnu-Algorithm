inf = 10 ** 9

n = int(input())
a = [[0] * n for i in range(n)]
for i in range(n):
    a[i] = list(map(float, input().split())) 
    for j in range(n):
        if a[i][j] == 0:
            a[i][j] = inf

def print_path(path : list):
    l = len(path)
    for i in range(l):
        print(path[i] + 1, end='->' if i != l - 1 else '\n')


def tsp():
    cnt = 0
    stack = []
    start = [0], 0
    stack.append(start)
    mn = inf
    ans_path = []
    while len(stack) != 0:
        v, s = stack.pop()
        if cnt < 20:
            cnt += 1
            print_path(v)
        if s >= mn:
            continue

        if len(v) == n:
            s += a[v[-1]][0]
            if s < mn:
                mn = s
                ans_path = v
        
        for i in range(n - 1, -1, -1):
            if i not in v:
                if (s + a[v[-1]][i]) < mn:
                    stack.append((v + [i], s + a[v[-1]][i]))
    
    return mn, ans_path

mn, ans_path = tsp()
if (abs(mn - round(mn)) < 0.0001):
    mn = int(mn)
    print(mn, end=': ')
    print_path(ans_path)
else:
    print("{:.3f}".format(mn), end=': ')
    print_path(ans_path)
