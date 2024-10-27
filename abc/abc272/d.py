import math

N, M = map(int, input().split())

valids = set()
i = 0
while i <= math.sqrt(M / 2):
    other = math.floor(math.sqrt(M - i * i))
    if M == i * i + other * other:
        valids.add((i, other))
        valids.add((-i, other))
        valids.add((i, -other))
        valids.add((-i, -other))
        valids.add((other, i))
        valids.add((-other, i))
        valids.add((other, -i))
        valids.add((-other, -i))
    i += 1

grid = [[-1 for _ in range(N)] for _ in range(N)]
grid[0][0] = 0

def is_valid(pos):
    return pos[0] >= 0 and pos[0] < N and pos[1] >= 0 and pos[1] < N

q = [(0, 0)]
while q:
    next_q = []
    for pos in q:
        for valid in valids:
            next_pos = (pos[0] + valid[0], pos[1] + valid[1])

            if not is_valid(next_pos):
                continue
            if grid[next_pos[0]][next_pos[1]] >= 0:
                continue
            grid[next_pos[0]][next_pos[1]] = grid[pos[0]][pos[1]] + 1
            next_q.append(next_pos)
    q = next_q

for row in grid:
    print(' '.join(map(str, row)))

