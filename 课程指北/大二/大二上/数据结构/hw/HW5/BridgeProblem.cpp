
#include"stdio.h"

int we[101];
int on[101];
int le[101];
int main() {
	//int getsum(int* chain, int a, int b);
	int pe, max;
	int temp,tp=0;
	scanf("%d%d", &pe, &max);

	for (int i = 0; i < pe; i++) {
		scanf("%d%d%d", we + i, on + i, &temp);
		if (on[i] + temp > tp) {
			le[i] = on[i] + temp;
			tp = le[i];
		}	
		else le[i] = tp;
		
	}
	int i=0, j=0;
	int sumwe=0;
	while (j != pe) {
		sumwe += we[j];
		if (sumwe > max) {
			printf("%d", j + 1);
			break;
		}
		 if (on[j] >= le[i]) {
			 sumwe -= we[i];
			 i++;
		 }
		 //sumwe = getsum(we, i, j + 1);
		/* if (sumwe > max) {
			 printf("%d", j + 1);
			 break;
		 }*/
		j++;
	}
	if (j == pe)
		printf("safe");

}
//int getsum(int* chain,int a,int b) {
//	int sumwe=0;
//	for (int i = a; i < b; i++) {
//		sumwe += chain[i];
//	}
//	return sumwe;
//}