#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <string.h>
#include <algorithm> 
using namespace std;

string Multiply(string s, string t) {
    int sum[200];
    int a[100], b[100], tmp, extra, i, j, start, len1, len2;
    char goal[10005];
    reverse(s.begin(), s.end());
    reverse(t.begin(), t.end());
    len1 = s.length();
    len2 = t.length();
    for (i = 0; i < len1; i++) {
        a[i] = (int)(s[i] - '0');
    }
    for (i = 0; i < len2; i++) {
        b[i] = (int)(t[i] - '0');
    }
    for (i = 0; i < 200; i++) {
        sum[i] = 0;
    }
    for (i = 0; i < len1; i++) {
        for (j = 0; j < len2; j++) {
            sum[i+j] += a[i] * b[j];
        }
    }

    for (i = 0; i < len1 + len2 - 1; i++) {
        sum[i + 1] += sum[i] / 10;
        sum[i] = sum[i] % 10;
    }
    while (sum[i] == 0) {
        i--;
    }
    for (j = i,start = 0; j >= 0; j--,start++) {
        goal[start] = (char)(sum[j] + '0');
    }
    goal[start] = '\0';
    return (string)goal;
}

int main() {
    string s, t;
    int times;
    cin >> times;
    for (int i = 0; i < times; i++) {
        cin >> s >> t;
        cout << Multiply(s, t) << endl;
    }

}
