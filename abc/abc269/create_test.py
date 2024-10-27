N, M = map(int, input().split())
s_list = []
letter_count = -1
for _ in range(N):
    string = input()
    s_list.append(string)
    letter_count += len(string) + 1
t_list = set()
for _ in range(M):
    t_list.add(input())

if letter_count < 3:
    print('-1')
    exit()
additional_count = 16 - letter_count

def get_perms(values):
    if len(values) == 0:
        return []
    if len(values) == 1:
        return [values]

    result = []
    for i in range(len(values)):
        others = get_perms(values[:i] + values[i+1:])
        for other in others:
            result.append([values[i]] + other)
    return result

def get_underbars(underbars, additional):
    # can optimize
    if additional == 0:
        return [underbars]
    result = []
    result += get_underbars(underbars, additional - 1)
    for i in range(len(underbars)):
        new_underbars = underbars[:i] + [underbars[i] + '_'] + underbars[i+1:] 
        result += get_underbars(new_underbars, additional - 1)
    return result

def create_usernames(words, underbars):
    result = []
    for underbar in underbars:
        new_word = []
        for u in range(len(underbar)):
            new_word.append(words[u])
            new_word.append(underbar[u])
        new_word.append(words[-1])
        username = ''.join(new_word)
        result.append(username)
    return result

unders = get_underbars(['_'] * (len(s_list) - 1), additional_count)
for perm in get_perms(s_list):
    for username in create_usernames(perm, unders):
        print(username)