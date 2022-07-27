//#pragma warning(disable:4996)

#include "cstdio"
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;
int N, M;
// 用于表示坐标
struct Coordinate
{
	double m_vector[2];

	Coordinate(double x = 0, double y = 0)
	{
		m_vector[0] = x;
		m_vector[1] = y;
	}

	bool isBigger(int dimension, const Coordinate& coor) const
	{
		return m_vector[dimension] > coor.m_vector[dimension];
	}

	bool isSmaller(int dimension, const Coordinate& coor) const
	{
		return m_vector[dimension] < coor.m_vector[dimension];
	}

	double distance(int dimension, const Coordinate& coor) const
	{
		return abs(m_vector[dimension] - coor.m_vector[dimension]);
	}

	double distance(const Coordinate& coor) const
	{
		double x_diff = m_vector[0] - coor.m_vector[0];
		double y_diff = m_vector[1] - coor.m_vector[1];
		return sqrt(x_diff * x_diff + y_diff * y_diff);
	}
};

// 点数据的类型 在坐标的基础上加上数据域 本题限制数据域的类型为字符型
struct PointStruct : public Coordinate
{
	char m_data;

	bool isEqual(PointStruct point)
	{
		return m_data == point.m_data && m_vector[0] == point.m_vector[0]
			&& m_vector[1] == point.m_vector[1];
	}
};

// 树节点 继承自点数据的类型
struct TreeNode : public PointStruct
{
	// 用于表示空间划分的方向 0代表在x方向划分 1代表在y方向划分
	int m_dimension;

	TreeNode* m_pLeftChild;
	TreeNode* m_pRightChild;

	TreeNode(const PointStruct& point)
		: PointStruct(point)
	{
		m_pLeftChild = nullptr;
		m_pRightChild = nullptr;
	}

	~TreeNode()
	{
		if (m_pLeftChild)
			delete m_pLeftChild;
		if (m_pRightChild)
			delete m_pRightChild;
	}
};

struct KdTree
{
	TreeNode* m_pRoot;

	KdTree(std::vector<PointStruct>& pointList)
	{
		m_pRoot = buildTree(pointList, 0);
	}

	~KdTree()
	{
		if (m_pRoot)
			delete m_pRoot;
	}

	static TreeNode* buildTree(std::vector<PointStruct>& pointList, int depth);
	static PointStruct findMedialPoint(int dimension, std::vector<PointStruct>& pointList);
	static void recursionNearestSearch(TreeNode* pNode, int depth, const Coordinate& point, PointStruct& nearest);

	PointStruct nearestSearch(const Coordinate& point)
	{
		PointStruct nearest = (PointStruct)*m_pRoot;
		recursionNearestSearch(m_pRoot, 0, point, nearest);
		return nearest;
	}
};

TreeNode* KdTree::buildTree(std::vector<PointStruct>& pointList, int depth)
{
	if (pointList.empty())
		return nullptr;

	int dimension = depth % 2;
	PointStruct mediaPoint = findMedialPoint(dimension, pointList);

	std::vector<PointStruct> pointListLeft;
	std::vector<PointStruct> pointListRight;
	for (int i = 0; i < pointList.size(); i++)
		if (mediaPoint.isBigger(dimension, pointList[i]))
			pointListLeft.push_back(pointList[i]);
		else if (mediaPoint.isSmaller(dimension, pointList[i]))
			pointListRight.push_back(pointList[i]);
		else if (!mediaPoint.isEqual(pointList[i]))
			pointListRight.push_back(pointList[i]);

	
	TreeNode* pTreeNode = new TreeNode(mediaPoint);
	pTreeNode->m_pLeftChild = buildTree(pointListLeft, depth + 1);
	pTreeNode->m_pRightChild = buildTree(pointListRight, depth + 1);
	pTreeNode->m_dimension = dimension;

	return pTreeNode;
}

PointStruct KdTree::findMedialPoint(int dimension, std::vector<PointStruct>& pointList)
{
	if (pointList.size() > 5000) {
		std::sort(pointList.begin(), pointList.end(),
			[&](const PointStruct& point1, const PointStruct& point2) {
				return point1.isSmaller(dimension, point2);//lambda表达式
			});
	
	}

	int mediaPosition = pointList.size() / 2;
	return pointList[mediaPosition];
}

void KdTree::recursionNearestSearch(TreeNode* pNode, int depth, const Coordinate& point, PointStruct& nearest)
{
	if (!pNode)
		return;

	int dimension = depth % 2;
	if (point.distance(*pNode) < point.distance(nearest))
		nearest = *pNode;

	if (point.isSmaller(dimension, *pNode))
	{
		recursionNearestSearch(pNode->m_pLeftChild, depth + 1, point, nearest);
		if (point.distance(nearest) >= point.distance(dimension, *pNode))
			recursionNearestSearch(pNode->m_pRightChild, depth + 1, point, nearest);
	}
	else
	{
		recursionNearestSearch(pNode->m_pRightChild, depth + 1, point, nearest);
		if (point.distance(nearest) >= point.distance(dimension, *pNode))
			recursionNearestSearch(pNode->m_pLeftChild, depth + 1, point, nearest);
	}
}


int main()
{

	double x, y;
	scanf("%d%d", &N, &M);

	std::vector<PointStruct> vec;
	while (N--)
	{
		PointStruct point;
		scanf("%lf%lf", &point.m_vector[0], &point.m_vector[1]);
		scanf(" %c", &point.m_data);
		vec.push_back(point);
	}

	KdTree kdTree(vec);

	while (M--)
	{
		scanf("%lf%lf", &x, &y);
		Coordinate coor(x, y);
		PointStruct nearest;
		nearest = kdTree.nearestSearch(coor);
		printf("%.4f\n", nearest.distance(coor));
	}
	return 0;

}
//int main(void) {
//
//	int PointCnt;
//	int ToSearchCnt;
//	std::vector<PointStruct> vecPoint;
//	scanf("%d%d", &PointCnt, &ToSearchCnt);
//	for (int i = 0; i < PointCnt; i++) {
//		PointStruct point;
//		scanf("%lf%lf", &point.m_vector[0], &point.m_vector[1]);
//		scanf("%c", &point.m_data);
//		getchar();
//		vecPoint.push_back(point);
//	}
//	KdTree kdTree(vecPoint);
//	std::vector<Coordinate> vecToSearch;
//	std::vector<double> vecRes;
//	for (int i = 0; i < ToSearchCnt; i++) {
//		double x, y;
//		scanf("%lf%lf", &x, &y);
//		vecToSearch.push_back(Coordinate(x, y));
//	}
//	for (int i = 0; i < ToSearchCnt; i++) {
//		PointStruct nearest;
//		nearest = kdTree.nearestSearch(vecToSearch[i]);
//		printf("%.4f\n", nearest.distance(vecToSearch[i]));
//	}
//
//	return 0;
//
//}