#include <stdio.h>
#include <stdlib.h>
#define MAX 20

//평균 횟수를 구할 변수선언
int count = 0;
//평균 횟수를 구하기 위한 이동 및 비교 횟수를 넣을 리스트 선언
int q_compar[MAX], q_move[MAX];

//리스트 초기화 함수
void init_list(int arr[]) {
    for (int i = 0; i < MAX; i++) {
        arr[i] = 0;
    }
}

// 랜덤으로 난수 20개를 만드는 함수
void RandomArray(int arr[]) {
    for (int i = 0; i < MAX; i++) {
        arr[i] = rand() % 100; // 0부터 99까지의 난수를 생성한 후 리스트에 저장
    }
}

// 배열 출력 함수
void printArray(int arr[]) {
    for (int i = 0; i < MAX; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// 리스트의 인덱스 값을 교환하는 함수
void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// 비교 횟수와 이동 횟수 평균 구하는 함수
void result(int move[], int compar[]) {
    int m_result = 0;
    int c_result = 0;

    for (int i = 0; i < MAX; i++) {
        m_result += move[i];
        c_result += compar[i];
    }

    printf("평균 이동 횟수 : %d\n", (m_result / MAX));
    printf("평균 비교 횟수 : %d\n", (c_result / MAX));
}

int partition(int arr[], int left, int right, int* comparisons, int* movements) {
    int pivot = arr[left]; // 피벗을 리스트의 가장 왼쪽 값으로 설정
    int low = left + 1; // 왼쪽에서 피벗 다음 위치
    int high = right; // 리스트의 가장 오른쪽 값으로 설정

    //피벗과 low, high 의 값을 비교
    while (low <= high) {
        while (low <= right && arr[low] <= pivot) {
            low++;
            (*comparisons)++;
        }

        while (high >= (left + 1) && arr[high] >= pivot) {
            high--;
            (*comparisons)++;
        }

        if (low <= high) {
            swap(&arr[low], &arr[high]);
            (*movements)++;
        }
    }

    swap(&arr[left], &arr[high]);
    (*movements)++;

    return high; // 피벗의 위치를 반환
}

void quick_sort(int arr[], int left, int right, int* comparisons, int* movements) {
    if (left < right) {
        //분할 위치를 찾아서 재귀적으로 정렬
        int q = partition(arr, left, right, comparisons, movements);

        //분할하여 정렬
        quick_sort(arr, left, q - 1, comparisons, movements);
        quick_sort(arr, q + 1, right, comparisons, movements);
    }
    if(count == 0)
        printArray(arr);
}

int main() {
    int q_list[MAX];    //리스트 변수 선언
    int comparisons = 0; // 비교 횟수 변수 선언
    int movements = 0; // 이동 횟수 변수 선언

    RandomArray(q_list);
    printf("Original List\n");
    printArray(q_list);
    printf("\n");

    printf("Quick Sort\n");
    quick_sort(q_list, 0, MAX - 1, &comparisons, &movements);

    printf("\n");
    // 비교 횟수 및 이동 횟수 출력
    printf("Average Move Count : %d\n", movements);
    printf("Average Compare Count : %d\n", comparisons);

    q_move[count] = movements;
    q_compar[count] = comparisons;

    count++;

    for (int i = 1; i < MAX; i++) {
        comparisons = 0;
        movements = 0;
  
        //선택 정렬
        init_list(q_list);
        RandomArray(q_list); // 랜덤 리스트 생성
        quick_sort(q_list, 0, MAX - 1, &comparisons, &movements);
        printArray(q_list);

        q_move[count] = movements;
        q_compar[count] = comparisons;

        count++;
    }

    printf("\n<퀵 정렬의 평균 횟수 출력>\n");
    result(q_move, q_compar);

    return 0;
}
