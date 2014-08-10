#include <stdio.h>
#include <stack>
using namespace std;
int main() {
    freopen("in.in", "r", stdin);
    freopen("out.out", "w", stdout);
    stack<char>S;
    int ch;
    while((ch = getchar()) != EOF) {
        if(ch == '#') {
            while(!S.empty()) {
                putchar(S.top());
                S.pop();
            }
        } else {
            S.push(ch);
        }
    }
    return 0;
}
