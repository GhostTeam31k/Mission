#include <iostream> //STL 

using namespace std;// std = standard , std :: cout -> std;를 치면 cout로 생략가능

int main()
{
    int Pocket[52]; // 0+1~51+1

    for (int i = 0; i < 52; ++i)
    {
        Pocket[i] = i + 1;
    }

    srand(time(nullptr));

    for (int i = 0; i < 10000; ++i)
    {
        int First = rand() % 52;
        int Second = rand() % 52;
        int Temp = Pocket[First];
        Pocket[First] = Pocket[Second];
        Pocket[Second] = Temp;
    }
    for (int i = 0; i < 4; ++i)
    {
        cout << Pocket[i] << endl;

    }

    return 0;
}