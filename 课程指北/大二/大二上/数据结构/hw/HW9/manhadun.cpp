#pragma warning(disable:4996)

#include <cstring>
#include <cstdio>
#include <algorithm>
#include <queue>
using namespace std;

int a[6];
bool vis[60005];
typedef struct ascending_node
{
    int id, data;
    bool operator<(const ascending_node& a) const
    {
        return data > a.data;
    }
}anode;
typedef struct descending_node
{
    int id, data;
    bool operator<(const descending_node& a) const
    {
        return data < a.data;
    }
}dnode;

int main()
{
    int m, n, sum=0;
    int result = 0;
    int in[6];
    scanf("%d %d", &m, &n);
    priority_queue<anode> apq[1 << 5];
    priority_queue<dnode> dpq[1 << 5];
    anode t1;
    dnode t2;
    memset(vis, false, sizeof(vis));
    int insert, dele;
    for (int i = 0; i < m; i++) {
        scanf("%d", &insert);
        if (!insert) {
            t1.id = i;
            t2.id = i;
     
                for (int k = 0; k < n; k++) {
                    scanf("%d", &in[k]);
                }
                for (int j = 0; j < 1 << n; j++) {
                    for (int k = 0; k < n; k++) {
                    int r = j & 1 << k;    //1为+，0为-,&符号表示当两二进制数同样位置上均为1时结果的该位置为1
                    if (r) sum += in[k];
                    else sum -= in[k];
                }
              
                t1.data = sum;
                apq[j].push(t1);
                t2.data = sum;
                dpq[j].push(t2);
                sum = 0;
            }
        }
        else {
            scanf("%d", &dele);
            vis[dele-1] = 1;
        }

        for (int q = 0; q < 1<<n; q++) {
            int temp;
            while (vis[apq[q].top().id] == 1) {
                apq[q].pop();
            }
            while (vis[dpq[q].top().id] == 1) {
                dpq[q].pop();
            }
            temp = dpq[q].top().data - apq[q].top().data;
            if (temp > result) {
                result = temp;
            }
           
        }
        printf("%d\n", result);
        result = 0;

    }
}