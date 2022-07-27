#pragma warning(disable:4996)
#include"stdio.h"
#include"string.h"

#define MD 2000005 //桶的个数

long long hash[MD];

void hashing(long long k) {             //线性试探法插入
    long long key;
    key = (k * 5 + 3) % 999983;
    while (hash[key] != 0) key = (key + 1) % MD;
    hash[key] = k;
}

void dele(long long k) {              //线性试探法删除
    long long key;
    key = (k * 5 + 3) % 999983;
    while (hash[key] != 0) {
        int t = hash[key];
        if (t == k) hash[key] = -1;
        key = (key + 1) % MD;
        }
}

int searching(long long k) {  // 线性试探法查找
    long long key;
    key = (k * 5 + 3) % 999983;
    while (hash[key] != 0) {
        int t = hash[key];
        if (t == k) return 1;
        key = (key + 1) % MD;
    }
    return 0;
}

int main() {
    memset(hash, 0, sizeof(hash));
    void hashing(long long k);
    void dele(long long k);
    int searching(long long k);
    int n;
    int t;
    long long x;
    scanf("%d", &n);
    while (n > 0) {
        scanf("%d %lld", &t, &x);
        if (t == 1) {
            hashing(x);
        }
        else if (t == 2) {
            dele(x);
        }
        else {
            printf("%d\n",searching(x));
        }
        n--;
    }
    return 0;
}

