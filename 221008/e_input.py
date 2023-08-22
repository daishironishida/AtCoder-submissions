with open('e_in.txt', 'w') as f:
    f.write('10000 10000\n')
    out = ' '.join(map(str, range(-1, -10000, -1)))
    f.write(out)