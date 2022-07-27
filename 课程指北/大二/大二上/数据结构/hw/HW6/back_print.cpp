#pragma warning(disable:4996)
#include"stdio.h"
int forw[30005];
int midw[30005];
//typedef struct thetree
//{
//	int num;
//	int* pro;
//	int* mid;
//}thetree;
int main() {
	/*int total;
	scanf("%d", &total);
	thetree* trees = new thetree[total];
	for (int i = 0; i < total; i++) {
		scanf("%d", &trees[i].num);
		int* m = new int[trees[i].num];
		int* n = new int[trees[i].num];
		for (int j = 0; j < trees[i].num; j++) {
			scanf("%d", m+j);
		}
		for (int j = 0; j < trees[i].num; j++) {
			scanf("%d", n + j);
		}
		back_print(m, n, trees[i].num);
	}

	delete trees;*/
	void back_print(int i, int j, int m, int n);
	int tree_num;
	scanf("%d", &tree_num);
	for (int i = 0; i < tree_num; i++) {
		int node;
		scanf("%d", &node);
		for (int j = 0; j < node; j++) {
			scanf("%d", forw + j);
		}
		for (int j = 0; j < node; j++) {
			scanf("%d", midw + j);
		}
		back_print(0, node-1, 0, node-1);
		printf("\n");
	}
	return 0;
}
//void back_print(int *i,int *j,int len) {
//	if (len == 0) {
//		printf("%d", i[0]);
//		return;
//	}
//	int fir = i[0];
//	int k=0;
//	while (j[k] != fir) {
//		k++;
//	}
//	if (k == 1) {
//		printf("%d ", j[0]);
//	}
//	else if (k == 0) {
//
//	}
//	else {
//		int* m = new int[k];
//		int* n = new int[k];
//		for (int a = 0; a < k; a++) {
//			m[a] = j[a];
//			n[a] = i[a + 1];
//		}
//		back_print(n, m, k);
//	}
//	printf("%d ", fir);
//	if (len-k-1 == 1) {
//		printf("%d ", j[0]);
//	}
//	else if (len - k - 1 == 0) {
//
//	}
//	else {
//		int* mm = new int[len - k - 1];
//		int* nn = new int[len - k - 1];
//		for (int a = k + 1; a < len; a++) {
//			mm[a] = j[a];
//			nn[a] = i[a];
//		}
//		back_print(nn, mm, len - k - 1);
//	}
//
//	//delete m, n, mm, nn;
//	return;
//}
void back_print(int i,int j,int m,int n) {
	if (m == n) {
		printf("%d ", midw[m]);
		return;
	}
	int firt = forw[i];
	int k = m;
	while (midw[k]!=firt) {
		k++;
	}
	if (k != m) {
		back_print(i + 1, i + k - m, m, k - 1);
	}
	if (k != n) {
		back_print(i + k - m + 1, j, k + 1, n);
	}
	printf("%d ", midw[k]);
}