#pragma warning(disable:4996)

#include <cstring>
#include <cstdio>
#include <algorithm>
#include <queue>
using namespace std;

int map[211][211]={0};
int dx[] = { 1,1,-1,-1,2,2,-2,-2 };
int dy[] = { 2,-2,2,-2,1,-1,1,-1 };//围棋马能走的八个方向 

struct Node {
	int x;
	int y;
	int step;
};//将每个点的位置和达到所用步数打包成Node类型（结构体） 


int main() {
	int x_final, y_final;
	scanf("%d %d", &x_final, &y_final);
	x_final = x_final + 105;
	y_final = y_final + 105;
	if (x_final == 105 && y_final == 105) {
		printf("%d", 0);
		return 0;
	}//搜索原点，直接输出0；

	int n;
	int hole_x, hole_y;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d %d", &hole_x, &hole_y);
		map[hole_x+105][hole_y+105] = -1;
	}//将凹陷点标记为-1

	queue<Node> Q;
	Q.push(Node{ 105, 105, 0 });//将原点压入队列
	int xs=105, ys=105;


	while (!Q.empty()) {//广度优先搜索
		for (int j = 0; j < 8; j++) {
			xs = Q.front().x + dx[j];
			ys = Q.front().y + dy[j];
			if (xs >= 0 && xs <= 210 && ys >= 0 && ys <= 210) {//在棋盘范围内
				if (map[xs][ys] == 0) {//未被搜到过而且不是凹陷点
					map[xs][ys] = Q.front().step + 1;
					Q.push(Node{ xs,ys,map[xs][ys] });
				}

			}
			if (xs == x_final && ys == y_final) {//已经搜到终点
				break;
			}
		}
		if (xs == x_final && ys == y_final) {//已经搜到终点
			break;
		}
		Q.pop();
	}
	if (map[x_final][y_final] == 0) {
		printf("fail");
		return 0;
	}
	printf("%d", map[x_final][y_final]);
	
	return 0;

}