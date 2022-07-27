#pragma warning(disable:4996)
#include"stdio.h"
#include"stdlib.h"
int joseph(int N,int M) {
	int res = 0;
	for (int i = 1; i < N+1; i++) {
		res = (res + M) % i;
	}
	return res + 1;
}
int main() {
	int N, M;
	scanf("%d%d", &N, &M);
	printf("%d", joseph(N, M));
}