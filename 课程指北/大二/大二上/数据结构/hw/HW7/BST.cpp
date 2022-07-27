#pragma warning(disable:4996)
#include"stdio.h"
int a[50005];

int main() {
	int m, n;
	scanf("%d%d", &m, &n);
	for (int i = 0; i < m; i++) {
		scanf("%d", a + i);
	}
	int x, y,result;
	for (int j = 0; j < n; j++) {
		scanf("%d%d", &x, &y);
		for (int i = 0; i < m; i++) {
			if (a[i] >= (x < y ? x : y) && a[i] <= (x > y ? x : y)) {
				result = a[i]; break;
			}
		}
		printf("%d\n", result);
	}


}