N, S = map(int, input().split())
pairs = []
diffs = []
sum = 0
for _ in range(N):
    a, b = map(int, input().split())
    pairs.append((a, b))
    diffs.append(b - a)
    sum += a

target = S - sum

possibles = {0: []}
for i in range(N):
    append_list = []
    for val in possibles:
        key = diffs[i] + val
        append_list.append((key, val))
    for key, val in append_list:
        if key in possibles:
            continue
        possibles[key] = possibles[val] + [i]

if target in possibles:
    print('Yes')
    tails = possibles[target]

    result = []
    index = 0
    current = 0
    for i in range(N):
        if current < len(tails) and tails[current] == i:
            result.append('T')
            current += 1
        else:
            result.append('H')
        i += 1
    res_str = ''.join(result)
    print(res_str)

else:
    print('No')
