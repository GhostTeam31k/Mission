#include <iostream>

using namespace std;

int main() {
	// 결과 배열 초기화
	int resultArray[9][10] = {
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
	};

	// 배열 변환
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 10; j++) {
			if ((i % 4 == 0) || (j % 4 == 0)) {
				resultArray[i][j] = 0;
			}
			else {
				resultArray[i][j] = 1;
			}
		}
	}

	// 결과 출력
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 10; j++) {
			cout << resultArray[i][j];
		}
		cout << endl;
	}

	return 0;
}
