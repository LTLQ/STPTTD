#include <algorithm>
#include <stdio.h>
using namespace std;
bool comp(int a, int b) {return a < b;}
int main() {
    freopen("in.in", "r", stdin);
    freopen("out.out", "w", stdout);
    int arr[43], cnt;
    while(scanf("%d", &arr[0]) != EOF) {
        int ch;
        cnt = 1;
        while((ch = getchar()) == ' ' && ch != EOF) {
            scanf("%d", &arr[cnt++]);
        }
        sort(arr, arr + cnt, comp);
        for(int i = 0; i < cnt; i++) {
            printf(i == cnt - 1 ? "%d\n" : "%d ", arr[i]);
        }
    }
    return 0;
}
