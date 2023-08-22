n = int(input())

def getBase16Num(val):
	if val < 10:
		return str(val)
	if val < 16:
		return chr(ord('A') + val - 10)
	return ''

if n < 16:
	print('0' + getBase16Num(n))
else:
	print(getBase16Num(n // 16) + getBase16Num(n % 16))
