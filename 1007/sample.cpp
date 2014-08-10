#include <string>
#include <stdio.h>
#include <string.h>
#include <iostream>
using namespace std;
struct Mat {
    int mat[2][2];
    Mat() {
        memset(mat, 0, sizeof(mat));
    }
    Mat(int k) {
        memset(mat, 0, sizeof(mat));
        if(k == 1) mat[0][0] = mat[1][1] = 1;
    }
    Mat operator * (Mat b) {
        Mat c;
        for(int i = 0; i < 2; i++) {
            for(int j = 0; j < 2; j++) {
                for(int k = 0; k < 2; k++) {
                    c.mat[i][j] += mat[i][k] * b.mat[k][j];
                }
            }
        }
        return c;
    }
};

int main() {
    freopen("in.in", "r", stdin);
    freopen("out.out", "w", stdout);
    Mat L(1), R(1);
    L.mat[0][1] = R.mat[1][0] = 1;
    string str;
    while(cin >> str) {
        Mat ans(1);
        for(int i = 0; i < str.size(); i++) {
            if(str[i] == 'L') {
                ans = ans * L;
            } else {
                ans = ans * R;
            }
        }
        printf("%d %d\n", ans.mat[0][0] + ans.mat[0][1], ans.mat[1][0] + ans.mat[1][1]);
    }
    return 0;
}
