import sys

def solve():
    input_data = sys.stdin.read().split()
    if not input_data:
        return
    n = int(input_data[0])
    count = 0
    idx = 1
    for _ in range(n):
        if int(input_data[idx]) + int(input_data[idx+1]) + int(input_data[idx+2]) >= 2:
            count += 1
        idx += 3
    print(count)

if __name__ == '__main__':
    solve()