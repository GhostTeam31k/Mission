#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int money = 500;  // 초기 자본금 설정
int betting = 0; // 배팅 금액 초기화

int rollRoulette();
int placeBet();
void printRemainingMoney();
void resetGameMoney();

int main() {
	int com, player, menu;

	// 난수 시드 초기화
	srand(time(NULL));

	do {
		printf("\n*****************\n");
		printf("*   룰렛 게임   *\n");
		printf("*****************\n");
		printf("1. 배팅하기\n");
		printf("2. 룰렛 게임 시작\n");
		printf("3. 남은 돈 보기\n");
		printf("4. 게임 머니 리셋\n");
		printf("5. 룰렛 게임 종료\n");
		scanf("d", &menu);
		printf("\n");

		switch (menu) {
		case 1:
			betting = placeBet();
			break;

		case 2:
			if (money <= 0) {
				printf("돈이 없습니다.\n");
				break;
			}
			if (betting == 0) {
				printf("배팅을 먼저하세요.\n");
				break;
			}

			printf("현재 배팅액 %d\n\n", betting);

			printf("컴퓨터가 룰렛을 돌립니다.\n");
			com = rollRoulette();
			printf("유저가 룰렛을 돌립니다.\n");
			player = rollRoulette();

			// 배팅 결과 계산 및 출력
			if (player > com)
			{
				money += betting;
				printf("유저가 이겼습니다. 보유금액: %d\n", money);
			}
			else if (player < com)
			{
				money -= betting;
				printf("컴퓨터가 이겼습니다. 보유금액: %d\n", money);
			}
			else
			{
				printf("비겼습니다. 보유금액: %d\n", money);
			}
			break;

		case 3:
			printRemainingMoney();
			break;

		case 4:
			resetGameMoney();
			printf("게임머니가 리셋되었습니다. 가진 돈: %d\n", money);
			break;

		case 5:
			printf("게임을 종료합니다.\n");
			break;

		default:
			break;
		}
	} while (menu != 5);

	return 0;
}

int rollRoulette() {
	int total = 0;
	for (int i = 0; i < 3; i++) {
		int result = rand() % 12 + 1;
		printf("* "); // 간단한 그래픽 표현
		total += result;
	}
	printf("\n => 총합은 %d\n", total);
	return total;
}

int placeBet() {
	int betAmount;
	printf("배팅할 금액을 입력하세요: ");
	scanf("d", &betAmount);

	if (betAmount > money) {
		printf("돈이 부족합니다.\n");
		return 0; // 배팅 실패
	}

	return betAmount;
}

void printRemainingMoney() {
	printf("남은 돈은 %d원 입니다.\n", money);
}

void resetGameMoney() {
	money = 500; // 초기 자본금으로 리셋
}
