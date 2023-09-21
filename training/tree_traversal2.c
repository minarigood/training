#include <stdio.h>
#include <stdlib.h>

#define true 1
#define false 0

typedef struct tree {
    int data; // 노드의 값 변수
    struct tree* left, * right; // 노드의 왼쪽, 오른쪽 노드 가리킴
    int is_thread; // 만약 오른쪽 링크가 스레드이면 True
} treenode;

// 트리에서 중위 후속자(노드)를 반환하는 함수
treenode* find_successor(treenode* root) {
    treenode* q = root->right;
    if (q == NULL || root->is_thread == true)
        return q;
    while (q->left != NULL)
        q = q->left;
    return q;
}

// 스레드 중위 순회 함수
void thread_inorder(treenode* root) {
    treenode* q = root; // 복사본 만들기
    while (q->left != NULL)
        q = q->left;
    do {
        printf("%d ", q->data);
        q = find_successor(q);
    } while (q);
}

treenode* parent(treenode* child) {
    
}

int main() {
    // 노드 초기화
    // 왼쪽
    treenode n1 = { 4, NULL, NULL, 1 };
    treenode n2 = { 5, NULL, NULL, 1 };
    treenode n3 = { 3, &n1, &n2, 0 };
    treenode n4 = { 6, NULL, NULL, 1 };
    treenode n5 = { 2, &n3, &n4, 0 };

    // 오른쪽
    treenode n6 = { 10, NULL, NULL, 1 };
    treenode n7 = { 11, NULL, NULL, 0 };
    treenode n8 = { 9, &n6, &n7, 0 };
    treenode n9 = { 8, NULL, NULL, 1 };
    treenode n10 = { 7, &n9, &n8, 0 };

    // 중앙
    treenode n11 = { 1, &n5, &n10, 0 };
    treenode* root = &n11;

    n1.right = &n3; //4
    n2.right = &n5; //5
    n4.right = &n11;//6
    n9.right = &n10;//8
    n6.right = &n8; //10

    printf("1. 중위 순회 결과\n");
    thread_inorder(root);

    printf("2. Node 4의 부모 : %d",)

    return 0;
}
