#include <iostream>
#include <vector>
#include <string>
#include <random>

using namespace std;

int main() {
	vector<string> menu = {
		"���� Ȥ�� Ŵġ�", "�λ�� ��������","�ϻɽ� ���", "������ ���", "������ ���� ���� ���", "�ڸ��� AZ��Ÿ�� ����", "�ϻɽ� ���", "�߱��� ��Ḧ �̿��� �߱���"// ���⿡ ���ϴ� ������ �߰��ϼ���
		// �߰��� ������ ��� �����ϼ���
	};

	random_device rd;
	mt19937 rng(rd());

	uniform_int_distribution<int> dist(0, menu.size() - 1);

	int choice = dist(rng);

	cout << "������ �Ļ� �޴�: " << menu[choice] << endl;

	return 0;
}