N, M = map(int, input().split())

met = [[False for _ in range(N)] for i in range(N)]

for _ in range(M):
    nums = list(map(int, input().split()))[1:]
    for i in range(len(nums)):
        for j in range(i+1, len(nums)):
            met[nums[i]-1][nums[j]-1] = True
            met[nums[j]-1][nums[i]-1] = True

all = True
for i in range(N):
    for j in range(i+1, N):
        if not met[i][j]:
            all = False
            break
    if not all:
        break
if all:
    print('Yes')
else:
    print('No')