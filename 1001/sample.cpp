//题目意思是如果左边的第三张满足移动条件就移到第三张，否则判断左边的第一张，只要有卡片的移动，那么我们就要去判断它和它右边的卡片是否可以移动。
#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <stack>
using namespace std;
//卡片的结构体
struct Card {
    char val;//卡片的值
    char suit;//卡片的颜色
};
Card c[52];//存储52个卡片
vector<stack<Card> >v;//开个vector里面放stack， stack里面放Card结构体
string str;

//判断是否满足移动的情况
int judge(Card x, Card y) {
    if (x.val == y.val || x.suit == y.suit)
        return 1;
    return 0;
}

//处理函数
void solve() {
    v.clear();//清空容器
    for (int i = 0; i < 52; i++) {
        stack<Card>s;
        s.push(c[i]);
        v.push_back(s);//插入最后一个位置
        Card temp;
        //printf("%d:  size: %d\n", i, v.size());
        for (int j = v.size() - 1 ; j < v.size() ; j++) {
            temp = v[j].top();//当前栈顶元素
            if (j >= 3) {//如果是当前的位置大于3，判断左边的第三个位置
                if (judge(temp, v[j-3].top())) {//判断左边的第三个是否和它匹配
                    v[j-3].push(temp);//插入到该位置
                    v[j].pop();//删除当前的j的栈顶元素
                    if (v[j].empty()) //如果此时j位置为空则删除它
                        v.erase(v.begin() + j);
                    j -= 4;//到左边的第4个位置,因为考虑左边第三个本身也是要判断的
                }
                else {//如果和左边第三个位置不匹配，则判断是否和左边第一个匹配
                    if (judge(temp, v[j-1].top())) {
                        v[j-1].push(temp);//将temp插入左边的第一个位置
                        v[j].pop();//删除当前的栈顶的元素
                        if (v[j].empty()) //如果为空，则就删除
                            v.erase(v.begin() + j);
                        j -= 2;//位置变为左边的第2个，因为考虑到左边第一个也要判断
                    }
                }
            }
            else if (j > 0 && j < 3) {//如果是0-3只要判断左边第一个即可
                if (judge(temp, v[j-1].top())) {//如果和左边的第一个匹配
                    v[j-1].push(temp);//插入到左边的第一个位置
                    v[j].pop();//删除栈顶元素
                    if (v[j].empty())
                        v.erase(v.begin() + j);
                    j -= 2;//位置变为左边的第2个，因为考虑到左边第一个也要判断
                }
            }

        }
    }
}

//输出函数
void output() {
    int ans = v.size();//最后有几堆
    if (ans == 1)//注意1的情况
        printf("1 pile remaining:");
    else
        printf("%d piles remaining:", ans);
    for (int i = 0; i < ans; i++)
        printf(" %d", v[i].size());
    printf("\n");
}

//输入函数
int main() {
    freopen("in.in", "r", stdin);
    freopen("out.out", "w", stdout);
    int i;
    while (cin >> str && str != "#") {
        i = 0;
        c[i].val = str[0];
        c[i].suit = str[1];
        for (i = 1; i < 52; i++) {
            cin >> str;
            c[i].val = str[0];
            c[i].suit = str[1];
        }
        solve();
        output();
    }
}
