N, Q = map(int, input().split())
num_lists = []

for _ in range(N):
	values = list(map(int, input().split()))
	num_lists.append(values[1:])

for _ in range(Q):
	s, t = list(map(int, input().split()))
	print(num_lists[s - 1][t - 1])
	
