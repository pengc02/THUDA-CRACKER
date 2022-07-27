#pragma warning(disable:4996)
#include"stdio.h"


int matrix[505][505];
int cnt[505] = {0};
bool visit[505] = { 0 };

int main() {
	bool searchcircle(int n);
	bool searchroad(int fo, int la);
	for (int i = 0; i < 505; i++) {
			matrix[i][0] = -1;
	}

	int M, N,K;
	scanf("%d%d%d",& N,&M,&K);
	for (int i = 0; i < M; i++) {
		int v1, v2;
		scanf("%d%d", &v1, &v2);
		matrix[v1][cnt[v1]] = v2;
		cnt[v1]++;
	}
	bool circle= searchcircle(N);
	if (circle == 1) {
		printf("%d\n", -1);
		return 0;
	}


	for (int j = 0; j < K; j++) {
		int srch1, srch2;
		scanf("%d%d", &srch1, &srch2);
		if (searchroad(srch1, srch2)) {
			printf("%d\n",1);
		}
		else if (searchroad(srch2, srch1)) {
			printf("%d\n", -1);
		}
		else printf("%d\n", 0);
	}
	return 0;

}

bool searchcircle(int n){
	bool searchroad(int fo, int la);
	int re = 0;
	for (int i = 0; i < n; i++) {
		re+=searchroad(i,i);
	}
	return re;
}

bool searchroad(int fo,int la) {
	int re=0;

	if (matrix[fo][0] == -1) {
		return 0;
	}
	for (int i = 0; i < cnt[fo]; i++) {
		if (matrix[fo][i] == la) {
			return 1;
		}
	}
	visit[fo] = 1;
	for (int i = 0; i < cnt[fo]; i++) {
		if (visit[matrix[fo][i]] == 0) continue;
		 re= searchroad(matrix[fo][i], la);
		 if (re == 1) return 1;
	}
	if (re == 0) return 0;
}

//int st[505];
//int top;
//
//bool serchroad2(int fo, int la) {
//	if (matrix[fo][0] == -1) {
//		return 0;
//	}
//	for (int i = 0; i < cnt[fo]; i++) {
//		if (matrix[fo][i] == la) {
//			return 1;
//		}
//	}
//
//}

