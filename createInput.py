n = 200000

with open('input.txt', 'w') as f:
    f.write(f'{n}\n')
    for i in range(1, n+1):
        f.write(f'{i} ')
