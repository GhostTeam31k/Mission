#include <iostream>
#include <vector>
#include <string>
#include <random>

using namespace std;

int main() {
	vector<string> menu = {
		"댄쟝 혹은 킴치찌개", "부산식 돼지국밥","니뽄식 돈까스", "조선식 돈까스", "집밥이 생각 날땐 백반", "코리안 AZ스타일 제육", "니뽄식 라멘", "중국산 재료를 이용한 중국집"// 여기에 원하는 음식을 추가하세요
		// 추가할 음식을 계속 나열하세요
	};

	random_device rd;
	mt19937 rng(rd());

	uniform_int_distribution<int> dist(0, menu.size() - 1);

	int choice = dist(rng);

	cout << "오늘의 식사 메뉴: " << menu[choice] << endl;

	return 0;
}