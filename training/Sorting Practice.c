#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//각 정렬의 비교와 이동 횟수를 넣은 리스트와 몇번 돌리는 지 확인하는 변수 선언
int count = 0;
// 선택 정렬
int s_compar[20], s_move[20];
// 삽입 정렬
int i_compar[20], i_move[20];
//버블 정렬
int b_compar[20], b_move[20];


//리스트 초기화 함수
void init_list(int arr[]) {
    for (int i = 0; i < 20; i++) {
        arr[i] = 0;
    }
}

// 랜덤으로 난수 20개를 만드는 함수
void RandomArray(int arr[]) {
	for (int i = 0; i < 20; i++) {
		arr[i] = rand() % 100; //0부터 99까지의 난수를 생성한 후 리스트에 저장
	}
}

// 배열 출력 함수
void printArray(int arr[]) {
	for (int i = 0; i < 20; i++) {
		printf("%d ", arr[i]);
	}
	printf("\n");
}

// 비교 횟수와 이동 횟수 평균 구하는 함수
void result(int move[], int compar[]) {
    int m_result = 0;
    int c_result = 0;

    for (int i = 0; i < 20; i++) {
        m_result += move[i];
        c_result += compar[i];
    }

    printf("평균 이동 횟수 : %d\n", (m_result / 20));
    printf("평균 비교 횟수 : %d\n", (c_result / 20));
}

// 선택 정렬 함수
void selectionSort(int arr[], int count) {
    int comparisons = 0; //비교 횟수 변수
    int movements = 0; //이동 횟수 변수

    if(count == 0)
        printf("Selection Sort\n");

    for (int i = 0; i < 19; i++) {
        int min_idx = i;
        //최솟값 비교
        for (int j = i + 1; j < 20; j++) {
            comparisons++; //비교 횟수 증가
            if (arr[j] < arr[min_idx]) {
                min_idx = j;
            }
        }
        // 값 교환
        int temp = arr[min_idx];
        arr[min_idx] = arr[i];
        arr[i] = temp;
        movements++; //이동 횟수 증가

        if (count == 0) {
            for (int i = 0; i < 20; i++) {
                printf("%d ", arr[i]);
            }
            printf("\n");
        }
    }

    s_compar[count] = comparisons;
    s_move[count] = movements;

    if (count == 0) {
        printf("\n");
        printf("Move Count : %d\n", movements);
        printf("Compare Count : %d\n", comparisons);
    }
}

// 삽입 정렬 함수
void insertionSort(int arr[], int count) {
    int comparisons = 0; //비교 횟수 변수 선언
    int movements = 0;  //이동 횟수 변수 선언

    if(count == 0)
        printf("Insertion Sort\n");

    for (int i = 1; i < 20; i++) {
        int key = arr[i];
        int j = i - 1;
        // 첫번째 값과 현재 인덱스의 값을 비교
        while (j >= 0 && arr[j] > key) {
            comparisons++; //비교 횟수 증가
            arr[j + 1] = arr[j]; //값 교환
            j = j - 1;
            movements++; //이동 횟수 증가
        }
        //값 교환
        arr[j + 1] = key;
        movements++;
        //배열 값 출력
        if (count == 0) {
            for (int i = 0; i < 20; i++) {
                printf("%d ", arr[i]);
            }
            printf("\n");
        }
    }

    i_move[count] = movements;
    i_compar[count] = comparisons;

    if (count == 0) {
        printf("\n");
        printf("Move Count : %d\n", movements);     //이동 횟수 출력
        printf("Compare Count : %d\n", comparisons);//비교 횟수 출력
    }
}

//버블 정렬 함수
void bubblesort(int arr[], int count) {
    int comparisons = 0; //비교 횟수 변수 선언
    int movements = 0;  //이동 횟수 변수 선언

    if (count == 0)
        printf("Bubble Sort\n");

    for (int i = 0; i < 20 - 1; i++) {
        for (int j = 0; j < 20 - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                comparisons++; //비교 횟수 증가
                // 현재 요소와 다음 요소를 비교하여 순서가 올바르지 않으면 위치를 교환
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                movements++; //이동 횟수 증가
            }
        }
        //배열 값 출력
        if (count == 0) {
            for (int i = 0; i < 20; i++) {
                printf("%d ", arr[i]);
            }
            printf("\n");
        }
    }

    b_move[count] = movements;
    b_compar[count] = comparisons;

    if (count == 0) {
        printf("\n");
        printf("Move Count : %d\n", movements);     //이동 횟수 출력
        printf("Compare Count : %d\n", comparisons);//비교 횟수 출력
    }
}


int main() {

    int s_list[20]; //선택 정렬 배열
    int i_list[20]; //삽입 정렬 배열
    int b_list[20]; //버블 정렬 배열
    int count = 0;
    
    //선택 정렬 첫번째 배열 정렬 출력
    RandomArray(s_list);
    printf("Original List\n");
    printArray(s_list);
    selectionSort(s_list,count);

    printf("\n");

    //삽입 정렬 첫번째 배열 정렬 출력
    RandomArray(i_list);
    printf("Original List\n");
    printArray(i_list);
    insertionSort(i_list, count);

    printf("\n");

    //버블 정렬 첫번째 배열 정렬 출력
    RandomArray(b_list);
    printf("Original List\n");
    printArray(b_list);
    bubblesort(b_list, count);

    count++;

    for (int i = 1; i < 20; i++) {
        //선택 정렬
        init_list(s_list);
        RandomArray(s_list); // 랜덤 리스트 생성
        selectionSort(s_list, count); // 선택 정렬 실행
        
        //삽입 정렬
        init_list(i_list);
        RandomArray(i_list); // 랜덤 리스트 생성
        insertionSort(i_list, count); // 삽입 정렬 실행

        //버블 정렬
        init_list(b_list);
        RandomArray(b_list); // 랜덤 리스트 생성
        bubblesort(b_list, count); // 삽입 정렬 실행

        count++;
    }

    printf("\n정렬들의 평균 횟수 출력\n");
    printf("\n<선택 정렬의 평균 횟수 출력>\n");
    result(s_move, s_compar);

    printf("\n<삽입 정렬의 평균 횟수 출력>\n");
    result(i_move, i_compar);
   
    printf("\n<버블 정렬의 평균 횟수 출력>\n");
    result(b_move, b_compar);

	return 0;
}