N, M = map(int, input().split())
input_nums = list(map(int, input().split()))

nums = set()
for i, num in enumerate(input_nums):
    nums.add((i, num))

def get_result(m):
    values = set()
    removes = set()
    for i, num in nums:
        result = num + (i + 1) * (m + 1)
        if result > N:
            removes.add((i, num))
            continue
        if result >= 0: 
            values.add(result)
    for remove in removes:
        nums.remove(remove)
    
    found = False
    for i in range(N):
        if i not in values:
            print(i)
            found = True
            break
    if not found:
        print(N)
    
for j in range(M):
    get_result(j)
