#include <stdio.h>
#include <stdlib.h>

//평균 횟수를 구할 변수선언
int count = 0;
//평균 횟수를 구하기 위한 이동 및 비교 횟수를 넣을 리스트 선언
int s_compar[20], s_move[20];

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

// 배열 출력 함수
void printArray(int arr[]) {
	for (int i = 0; i < 20; i++) {
		printf("%d ", arr[i]);
	}
	printf("\n");
}

//gap 간격의 삽입 정렬 수행하고 비교 횟수, 이동 횟수 반환하는 ㅎ함수
int insertion_sort(int arr[], int first, int last, int gap, int* comparisons, int* movements) {
	int i, j, key;

	//간격에 맞게 요소를 선택하도록 조건 설정 후 for문을 돌림
	for (i = first + gap; i <= last; i += gap) {
		key = arr[i];
		(*comparisons)++; //비교 횟수 증가

		//현재 선택된 요소가 이전 요소보다 작은 경우에 루프를 진행하도록 조건을 세움
		//현재 선택된 요소가 삽입 도리 위치를 찾기 위해서 진행함. 
		//조건을 만족하지 않거나 해당 요소가 삽입 될 위치를 찾지 못하면 루푸를 멈추고 key를 삽입함.
		for (j = i - gap; j >= first && key < arr[j]; j = j - gap) {
			arr[j + gap] = arr[j];
			(*movements)++;	//이동 횟수 증가
		}
		arr[j + gap] = key;
		(*movements)++;		//이동 횟수 증가
	}

	return *comparisons, * movements;
}

void shell_sort(int arr[], int count)
{
	int gap, i, j, temp;
	int comparisons = 0; //비교 횟수 변수 선언
	int movements = 0;	//이동 횟수 변수 선언

	if (count == 0)
		printf("Shell Sort\n");

	// 간격(gap)을 변화시키면서 셸 정렬 수행
	for (gap = 20 / 2; gap > 0; gap = gap / 2) {
		if ((gap % 2) == 0)
			gap++;

		// 각 gap에 따른 부분 리스트에 대해 삽입 정렬 수행
		for (i = 0; i < gap; i++) {
			insertion_sort(arr, i, 20 - 1, gap, &comparisons, &movements);
		}

		if (count == 0)
			printArray(arr);
	}

	s_move[count] = movements;
	s_compar[count] = comparisons;

	if (count == 0) {
		printf("\n");
		//비굑 횟수 및 이동 횟수 출력
		printf("Average Move Count : %d\n", movements);
		printf("Average Compare Count : %d\n", comparisons);
	}
}


int main() {

	int s_list[20];

	RandomArray(s_list);
	printf("Original LIst\n");
	printArray(s_list);
	printf("\n");
	shell_sort(s_list, count);

	count++;

	for (int i = 1; i < 20; i++) {
		//선택 정렬
		init_list(s_list);
		RandomArray(s_list); // 랜덤 리스트 생성
		shell_sort(s_list, count); //합병 정렬 실행

		count++;
	}

	printf("\n<셸 정렬의 평균 횟수 출력>\n");
	result(s_move, s_compar);

	return 0;
}