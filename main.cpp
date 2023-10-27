#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int money = 500;  // �ʱ� �ں��� ����
int betting = 0; // ���� �ݾ� �ʱ�ȭ

int rollRoulette();
int placeBet();
void printRemainingMoney();
void resetGameMoney();

int main() {
	int com, player, menu;

	// ���� �õ� �ʱ�ȭ
	srand(time(NULL));

	do {
		printf("\n*****************\n");
		printf("*   �귿 ����   *\n");
		printf("*****************\n");
		printf("1. �����ϱ�\n");
		printf("2. �귿 ���� ����\n");
		printf("3. ���� �� ����\n");
		printf("4. ���� �Ӵ� ����\n");
		printf("5. �귿 ���� ����\n");
		scanf("d", &menu);
		printf("\n");

		switch (menu) {
		case 1:
			betting = placeBet();
			break;

		case 2:
			if (money <= 0) {
				printf("���� �����ϴ�.\n");
				break;
			}
			if (betting == 0) {
				printf("������ �����ϼ���.\n");
				break;
			}

			printf("���� ���þ� %d\n\n", betting);

			printf("��ǻ�Ͱ� �귿�� �����ϴ�.\n");
			com = rollRoulette();
			printf("������ �귿�� �����ϴ�.\n");
			player = rollRoulette();

			// ���� ��� ��� �� ���
			if (player > com)
			{
				money += betting;
				printf("������ �̰���ϴ�. �����ݾ�: %d\n", money);
			}
			else if (player < com)
			{
				money -= betting;
				printf("��ǻ�Ͱ� �̰���ϴ�. �����ݾ�: %d\n", money);
			}
			else
			{
				printf("�����ϴ�. �����ݾ�: %d\n", money);
			}
			break;

		case 3:
			printRemainingMoney();
			break;

		case 4:
			resetGameMoney();
			printf("���ӸӴϰ� ���µǾ����ϴ�. ���� ��: %d\n", money);
			break;

		case 5:
			printf("������ �����մϴ�.\n");
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
		printf("* "); // ������ �׷��� ǥ��
		total += result;
	}
	printf("\n => ������ %d\n", total);
	return total;
}

int placeBet() {
	int betAmount;
	printf("������ �ݾ��� �Է��ϼ���: ");
	scanf("d", &betAmount);

	if (betAmount > money) {
		printf("���� �����մϴ�.\n");
		return 0; // ���� ����
	}

	return betAmount;
}

void printRemainingMoney() {
	printf("���� ���� %d�� �Դϴ�.\n", money);
}

void resetGameMoney() {
	money = 500; // �ʱ� �ں������� ����
}
