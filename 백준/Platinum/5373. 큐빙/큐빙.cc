#define _CRT_SECURE_NO_WARNINGS

#include<iostream>
#include <string>
#include <unordered_map>
#include<cstring>
using namespace std;

const int MAX = 3;

int N;

int color[6] = { 'w', 'y', 'r', 'o', 'g', 'b' };
unordered_map<char, int> dmap = { {'U', 0}, {'D', 1}, {'F', 2}, {'B', 3}, {'L', 4}, {'R', 5} };
char board[6][MAX][MAX]; // 윗, 아래, 앞, 뒤, 왼, 오

void move(const char d, const bool c);
void display_up(int k);
void display();

int main(int argc, char** argv)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int test_case;
	int T;
	
	//freopen("input.txt", "r", stdin);
	//cin >> T;
	T = 1;

	//display();

	for (test_case = 1; test_case <= T; ++test_case)
	{
		cin >> N;
		while (N--) {
			for (int k = 0; k < 6; k++) {
				fill(&board[k][0][0], &board[k][0][0] + 9, color[k]);
			}
			int t, d, c;
			cin >> t;
			cin.ignore(0);
			while (t--) {
				string s;
				cin >> s;
				d = s[0], c = s[1] == '+';
				move(d, c);
				/*cout << s << "\n";
				display();*/
			}
			display_up(0);
		}
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}

char backup[6][MAX][MAX];

void rotate_self(const int d, const bool c) {
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			if (!c) board[d][i][j] = backup[d][j][2 - i];
			else board[d][i][j] = backup[d][2 - j][i];
		}
	}

}
void move(const char d, const bool c)
{
	memcpy(backup, board, sizeof(backup));
	//cout << i << "," << j << "->" << 2 - j << "," << i << "\n";
	//board[][][] = backup[][][];
	rotate_self(dmap[d], c);
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			if (d == 'U') {
				if (!c) {
					board[4][i][2] = backup[3][2][2 - i];
					board[2][0][j] = backup[4][j][2];
					board[5][i][0] = backup[2][0][2 - i];
					board[3][2][i] = backup[5][i][0];
				}
				else {
					board[5][i][0] = backup[3][2][i];
					board[2][0][j] = backup[5][2 - j][0];
					board[4][i][2] = backup[2][0][i];
					board[3][2][j] = backup[4][2 - j][2];
				}
			}
			else if (d == 'D'){
				if (!c) {
					board[5][i][2] = backup[3][0][i];
					board[2][2][j] = backup[5][2 - j][2];
					board[4][i][0] = backup[2][2][i];
					board[3][0][j] = backup[4][2 - j][0];
				}
				else {
					board[4][i][0] = backup[3][0][2 - i];
					board[2][2][j] = backup[4][j][0];
					board[5][i][2] = backup[2][2][2- i];
					board[3][0][j] = backup[5][j][2];
				}
			}
			else if (d == 'F') {
				if (!c) {
					board[4][2][j] = backup[0][2][j];
					board[1][2][j] = backup[4][2][j];
					board[5][2][j] = backup[1][2][j];
					board[0][2][j] = backup[5][2][j];
				}
				else {
					board[5][2][j] = backup[0][2][j];
					board[1][2][j] = backup[5][2][j];
					board[4][2][j] = backup[1][2][j];
					board[0][2][j] = backup[4][2][j];
				}
			}
			else if (d == 'B') {
				if (!c) {
					board[4][0][j] = backup[1][0][j];
					board[0][0][j] = backup[4][0][j];
					board[5][0][j] = backup[0][0][j];
					board[1][0][j] = backup[5][0][j];
				}
				else {
					board[5][0][j] = backup[1][0][j];
					board[0][0][j] = backup[5][0][j];
					board[4][0][j] = backup[0][0][j];
					board[1][0][j] = backup[4][0][j];
				}
			}
			else if (d == 'L') {
				if (!c) {
					board[1][i][2] = backup[3][2 - i][0];
					board[2][i][0] = backup[1][2 - i][2];
					board[0][i][0] = backup[2][i][0];
					board[3][i][0] = backup[0][i][0];
				}
				else {
					board[0][i][0] = backup[3][i][0];
					board[2][i][0] = backup[0][i][0];
					board[1][i][2] = backup[2][2 - i][0];
					board[3][i][0] = backup[1][2 - i][2];
				}
			}
			else if (d == 'R') {
				if (!c) {
					board[0][i][2] = backup[3][i][2];
					board[2][i][2] = backup[0][i][2];
					board[1][i][0] = backup[2][2 - i][2];
					board[3][i][2] = backup[1][2 - i][0];
				}
				else {
					board[1][i][0] = backup[3][2 - i][2];
					board[2][i][2] = backup[1][2 - i][0];
					board[0][i][2] = backup[2][i][2];
					board[3][i][2] = backup[0][i][2];
				}
			}
		}
	}
}

void display_up(int k) {
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			cout << board[k][i][j];
		}
		cout << "\n";
	}
}

void display() {
	for (int x = 0; x < 9; x++) {
		for (int y = 0; y < 12; y++) {
			if (x >= 0 && x < 3 && y >= 3 && y < 6) {
				cout << board[3][x % 3][y % 3];
			}
			else if (x >= 3 && x < 6 && y >= 0 && y < 3) {
				cout << board[4][x % 3][y % 3];
			}
			else if (x >= 3 && x < 6 && y >= 3 && y < 6) {
				cout << board[0][x % 3][y % 3];
			}
			else if (x >= 3 && x < 6 && y >= 6 && y < 9) {
				cout << board[5][x % 3][y % 3];
			}
			else if (x >= 3 && x < 6 && y >= 9 && y < 12) {
				cout << board[1][x % 3][y % 3];
			}
			else if (x >= 6 && x < 9 && y >= 3 && y < 6) {
				cout << board[2][x % 3][y % 3];
			}
			else {
				cout << " ";
			}
		}
		cout << "\n";
	}
}