import sys
MAX, f = None, None

def g(n, k):
    global f, MAX
    if n == 0:
        f[k] == True
        MAX = max(MAX, k)
    else:
        for r in range(n):
            pass

def main() -> None:
    global MAX, f
    n = int(sys.stdin.readline().strip())
    if n == 0:
        print(0)
        return
    MAX = -1
    max_k = n * (n - 1) // 2
    f = [False] * (max_k + 1)




if __name__ == '__main__':
    main()
