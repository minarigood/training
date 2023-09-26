#include <stdio.h>
#include <stdlib.h>

//트리 노드 구조체
typedef struct treenode {
	int data; // 노드의 값 변수
	struct tree* left, * right; // 노드의 왼쪽, 오른쪽 노드 가리킴
}treenode;

//노드 추가 함수 
treenode* createnode(int data) {
	treenode* newnode = (treenode*)malloc(sizeof(treenode));
	newnode->data = data;
	newnode->left = newnode->right = NULL;

	return newnode;
}



void look_menu(){
	printf("------------------------\n");
	printf("| s : 검색             |\n");
	printf("| i : 노드 추가        |\n");
	printf("| d : 노드 삭제        |\n");
	printf("| t : 중위 순회        |\n");
	printf("| I : 노드 추가(반복)  |\n");
	printf("| D : 노드 삭제(반복)  |\n");
	printf("| c : 종료             |\n");
	printf("------------------------\n");
}

void node_search() {
	int find_num;
	printf("검색할 값 입력 : ");
	scanf_s("%d", &find_num);
	search(root, find_num);
}

int main() {

	//
	look_menu();
	char choice;

	while (1)
	{
		printf("메뉴 입력 : ");
		scanf_s("%c", &choice);
		if (choice == 's')
			node_search();
		else if (choice == 'i')

		else if (choice == 'd')

		else if (choice == 't')

		else if (choice == 'l')

		else if (choice == 'D')

		else if (choice == 'c')
	}

	return 0;
}