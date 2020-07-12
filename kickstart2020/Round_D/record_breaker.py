def solve():
    N = int(input())
    V = [int(x) for x in input().split(' ')]
    breaking_days = 0
    
    max_previous = -1

    for i in range(len(V)):
        if V[i] > max_previous and (i+1 == len(V) or V[i] > V[i+1]):
            breaking_days += 1
        max_previous = max(max_previous, V[i])

    return breaking_days

test_cases = int(input())

for i in range(1, test_cases + 1):
    answer = solve()
    print('Case #{}: {}'.format(i, answer))
    