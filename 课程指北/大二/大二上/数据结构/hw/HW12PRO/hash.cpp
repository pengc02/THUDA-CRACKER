#pragma warning(disable:4996)
#include"stdio.h"
#include<vector>
#include<algorithm>
using namespace std;

#define MD 10005 //Í°µÄ¸öÊý

int hash[MD];

std::vector<long long> h[MD];

void hashing(long long k) {
    long long key;
    key = k % 9991;
    h[key].push_back(k);
}

bool searching(long long k) {
    long long key;
    key = k % 9991;
    vector<long long>::iterator result = find(h[key].begin(), h[key].end(), k);
    if (result == h[key].end()) return 0;
    else return 1;
}

void deleting(long long k) {
    long long key;
    key = k % 9991;
    vector<long long>::iterator result = find(h[key].begin(), h[key].end(), k);
    while (result != h[key].end()) {
        *result = 0;
      result = find(h[key].begin(), h[key].end(), k);
    }

 /*   for (int i = 0 ; i < h[key].size(); i++) {
        if (h[key][i] == k) {
            h[key][i] = 0;
        }
    }*/
}

int main() {

    void hashing(long long k);
    void deleting(long long k);
    bool searching(long long k);
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
            deleting(x);
        }
        else {
            printf("%d\n", searching(x));
        }
        n--;
    }
    return 0;
}

