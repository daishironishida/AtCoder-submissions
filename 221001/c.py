N = int(input())
nums = list(map(int, input().split()))

vals = set()
for i in range(len(nums)):
    if nums[i] in vals:
        nums[i] = 100000000
    else:
        vals.add(nums[i])

nums.sort()

i = 0
index = 0
max = len(nums)
while index < max:
    if nums[index] == i + 1:
        i += 1
        index += 1
        continue
    if index + 2 <= max:
        max -= 2
        i += 1
        continue
    break
print(i)
