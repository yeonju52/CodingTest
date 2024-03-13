#include <iostream>
#include <cstring>
using namespace std;

#define MAX 16 // for 글자 수 <= 15

int Time_score(char word[], int len)
{
	int dial_time[26] = {3, 3, 3, 4, 4, 4, 5, 5, 5, 6, 6, 6, 7, 7, 7, 8, 8, 8, 8, 
		9, 9, 9, 10, 10, 10, 10}; //알파벳이 총 26개이므로 직접 배열을 적는 것이 가능.

	int total = 0;
	for (int i = 0; i < len; i++)
	{
		int ASCII = word[i] - 65; // 'A'의 ASCII 코드에 해당하는 숫자는 65이다.
		total = total + dial_time[ASCII];
	}

	return total;
}

int main()
{
	char word[MAX];
	cin >> word;

	if (1 < strlen(word)) //for 글자 수 >= 2
	{
		int sum = Time_score(word, strlen(word));
		cout << sum;
	}
	else
		return 0; // 글자수 조건이 맞지 않으므로 return으로 if문 종료
}
