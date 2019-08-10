#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <algorithm>

typedef long long lint;

const size_t MAX_COUNT = 2510;
const lint MOD = 1000000007;

lint combination[MAX_COUNT][MAX_COUNT];

lint quickPower(lint base, lint pow, lint mod = MOD)
{
	lint res = 1;
	while (pow)
	{
		if (pow & 1)
		{
			res = (res * base) % mod;
		}

		base = (base * base) % mod;
		pow >>= 1;
	}

	return res;
}

void init(lint mod = MOD)
{
	combination[0][0] = 1;
	for (int i = 1; i < MAX_COUNT; i++)
	{
		combination[i][0] = 1;
		for (int j = 1; j <= i; j++)
		{
			combination[i][j] = (combination[i - 1][j] + combination[i - 1][j - 1]) % mod;
		}
	}
}

int main()
{
	int vcount = 0, ccount = 0;
	scanf("%d %d", &vcount, &ccount);

	for (int i = 0; i < vcount - 1; i++)
	{
		scanf("%*d");
	}

	init();

	lint res = 0, flag = 1;
	for (int i = ccount; i >= 0; i--)
	{
		lint temp = ((((flag * combination[ccount][i] * i) % MOD) * quickPower((lint)i - 1, (lint)vcount - 1) % MOD) + MOD) % MOD;
		res = (res + temp) % MOD;
		flag = -flag;
	}

	printf("%lld\n", res);
	return 0;
}
