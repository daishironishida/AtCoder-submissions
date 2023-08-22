N = int(input())
nums = list(map(int, input().split()))

max_odd_1 = -1
max_odd_2 = -1
max_even_1 = -1
max_even_2 = -1

for num in nums:
    if num % 2 == 1:
        if num > max_odd_1 or num > max_odd_2:
            if max_odd_1 < max_odd_2:
                max_odd_1 = num
            else:
                max_odd_2 = num
    else:
        if num > max_even_1 or num > max_even_2:
            if max_even_1 < max_even_2:
                max_even_1 = num
            else:
                max_even_2 = num

if max_odd_1 == -1 and max_even_1 == -1:
    print(-1)
else:
    if max_odd_1 + max_odd_2 > max_even_1 + max_even_2:
        print(max_odd_1 + max_odd_2)
    else:
        print(max_even_1 + max_even_2)
