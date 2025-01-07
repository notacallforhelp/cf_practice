from math import gcd
 
for _ in range(int(input())):
	n = int(input())
	a = list(map(int, input().split()))
	g = 0
	for i in range(n - 1):
		g = gcd(g, a[i + 1] - a[i])
	g = max(g, 1)
	print(g)
	a.sort()
	j = n - 1
	res = a[-1]
	while True:
		while j >= 0 and a[j] > res:
			j -= 1
		if j < 0 or a[j] != res:
			break
		res -= g
	print((a[-1] * (n + 1) - (sum(a) + res)) // g)