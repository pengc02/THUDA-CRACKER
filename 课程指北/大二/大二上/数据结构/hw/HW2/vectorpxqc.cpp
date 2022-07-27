#pragma warning(disable:4996)
#include<vector>
#include<stdio.h>
#include<algorithm>


class pair {
private:
	int x;
	int y;
public:
	pair();
	bool operator>(const pair& p) const;
	bool operator<(const pair& p) const;
	bool operator>=(const pair& p) const;
	bool operator<=(const pair& p) const;
	bool operator==(const pair& p) const;
	void print();
	void get(int X, int Y);
};
//pair 的比较方式：
//即对于Vi和Vj，先比较它们的x项，若xi > xj，则Vi > Vj；若xi < xj，则Vi<Vj。
//若xi = xj，则继续比较y项的大小，若yi<yj，则vi<vj，若yi>yj，则vi>vj。若xi = xj且yi = yj，则认为Vi = Vj。
//我们的任务是，对任一一个乱序的向量，输出其中所有不相等的项，并按从小到大的顺序输出。
bool pair::operator>(const pair& p) const {
	if (x > p.x)
	{
		return true;
	}
	else if (x < p.x)
	{
		return false;
	}
	else
	{
		if (y > p.y)
			return true;
		else
			return false;
	}
}
bool pair::operator<(const pair& p) const {
	if (x < p.x)
	{
		return true;
	}
	else if (x > p.x)
	{
		return false;
	}
	else
	{
		if (y < p.y)
			return true;
		else
			return false;
	}
}
bool pair::operator>=(const pair& p) const {
	if (x > p.x)
	{
		return true;
	}
	else if (x < p.x)
	{
		return false;
	}
	else
	{
		if (y >= p.y)
			return true;
		else
			return false;
	}
}
bool pair::operator<=(const pair& p) const {
	if (x < p.x)
	{
		return true;
	}
	else if (x > p.x)
	{
		return false;
	}
	else
	{
		if (y <= p.y)
			return true;
		else
			return false;
	}
}
bool pair::operator==(const pair& p) const {
	if (x == p.x && y == p.y)
	{
		return true;
	}
	else return false;
	
}
void pair::print() {
	printf("%d %d\n", x, y);
}
void pair::get(int X,int Y) {
	x = X; y = Y;
}
pair::pair() {
}
int main() {
	int len,x,y;
	scanf("%d", &len);
	pair* vec = new pair[len];
	for (int i = 0; i < len; i++) {
		scanf("%d %d", &x, &y);
		vec[i].get(x, y);
	}
	std::sort(vec, vec + len);
	pair* tail = std::unique(vec, vec + len);
	for (int i = 0; i < tail - vec; i++) {
		vec[i].print();
	}
	
}
