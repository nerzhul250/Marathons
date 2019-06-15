#include <iostream>

using namespace std;

int main()
{
    while (scanf("%d %lld", &n, &m) == 2) {
		for (int i = 0; i < n; i++)
			scanf("%lld", &A[i]);

		meetInMiddle();
	}
	return 0;
}
