#pragma warning(disable:4996)
#include"stdio.h"
#include"stdlib.h"
int main() {
	int* p;
	int N, M;
	scanf("%d%d", &N, &M);
	p = new int[N];
	for (int i = 1; i < N + 1; p[i - 1] = ++i);
	return 0;
}