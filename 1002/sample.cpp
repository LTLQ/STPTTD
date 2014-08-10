#include <stdio.h>
#include <malloc.h>

typedef struct NODE {
    int data;
    struct NODE *next;
} Node;

/*
 * initialize the circle list
 */
Node* initCircle(int n) {
    int i;
    Node *head = (Node *) malloc(n * sizeof(Node));
    for(i = 0; i < n - 1; i++) {
        head[i].data = i + 1;
        head[i].next = &head[i + 1];
    }
    head[n - 1].data = n;
    head[n - 1].next = &head[0];
    return head;
}

/*
 * travel m step and print&delete current node
 */
void Josephus(Node *head, int m) {
    Node **plink = &(head->next);
    while(*plink != head) {
        plink = &((*plink)->next);
    }
    while((*plink)->next != (*plink)) {
        for(int i = 1; i < m; i++) {
            plink = &(*plink)->next;
        }
        printf("%d ", (*plink)->data);
        *plink = (*plink)->next;
    }
    printf("%d\n", (*plink)->data);
}

void destroy(Node *head) {
    free(head);
}

int main() {
    freopen("in.in", "r", stdin);
    freopen("out.out", "w", stdout);
    int n, m;
    while(scanf("%d %d", &n, &m) != EOF) {
        Node *L = initCircle(n);
        Josephus(L, m);
        destroy(L);
    }
    return 0;
}
