N, M, K = map(int, input().split())

roads = []
for _ in range(M):
    a, b, c = map(int, input().split())
    roads.append((a, b, c))
e_s = list(map(int, input().split()))

mins = {}
def min_to_city(city):
    if city == 1:
        return 0
    if city not in mins:
        return -1
    return mins[city]

for e in e_s:
    a, b, c = roads[e - 1]
    
    value = min_to_city(a)
    if value < 0:
        continue

    current = value + c
    if b not in mins or mins[b] > current:
        mins[b] = current

result = min_to_city(N)
print(result)
    