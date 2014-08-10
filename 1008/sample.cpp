#include <stdio.h>
#include <string>
#include <iostream>
using namespace std;

int gcd(int a, int b) {
    b == 0 ? a : gcd(b, a % b);
}

int main() {
    freopen("in.in", "r", stdin);
    freopen("out.out", "w", stdout);
    string str1, str2;
    while(cin >> str1 >> str2) {
        puts(gcd(str1.size(), str2.size()) == 1 ? "Yes" : "No");
    }
    return 0;
}
