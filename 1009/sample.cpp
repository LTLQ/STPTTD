#include <stdio.h>
#include <string>
#include <stack>
#include <iostream>
using namespace std;

int main() {
    freopen("in.in", "r", stdin);
    freopen("out.out", "w", stdout);
    string str;
    while(cin >> str) {
        stack<char> S;
        for(int i = 0; i < str.size(); i++) {
            if(!S.empty() &&
               ((S.top() == '(' && str[i] == ')')
                || (S.top() == '[' && str[i] == ']')
                || (S.top() == '{' && str[i] == '}')) ) {
                    S.pop();
                } else {
                    S.push(str[i]);
                }
        }
        puts(S.empty() ? "Yes" : "No");
    }
    return 0;
}
