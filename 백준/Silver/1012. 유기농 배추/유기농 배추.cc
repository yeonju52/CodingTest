#include <iostream>
using namespace std;

int M; int N;
int input[50][50];
int label[50][50];

void reset() { //input 배열 0으로 초기화
	for (int x = 0; x < M; x++) {
		for (int y = 0; y < N; y++) {
			input[x][y] = 0;
		}
	}
}

void reset2() { //label 배열 0으로 초기화
	for (int x = 0; x < M; x++) {
		for (int y = 0; y < N; y++) {
			label[x][y] = 0;
		}
	}
}

void output() { //input 배열 출력 (컴파일용)
	for (int y = 0; y < N; y++) {
		for (int x = 0; x < M; x++) {
			cout << input[x][y] << " ";
		}
		cout << '\n';
	}
}

void output2() { //label 배열 출력 (컴파일용)
	for (int y = 0; y < N; y++) {
		for (int x = 0; x < M; x++) {
			cout << label[x][y] << " ";
		}
		cout << '\n';
	}
}

bool isOK(int x, int y) { //x, y가 배열의 범위에 벗어나는지 확인
	if (x < 0 || y < 0 || x >= M || y >= N) return false;
	else return true;
}

void dfs(int x, int y) { //인접한 위치를 한 그룹으로
	label[x][y] = 1;

	for (int i = 0; i < 4; i++) {
		int a; int b;
		switch (i) {
			case 0: a = x + 1; b = y; break;
			case 1: a = x - 1; b = y; break;
			case 2: a = x; b = y + 1; break;
			case 3: a = x; b = y - 1; break;
		}

		if (isOK(a, b) && input[a][b] == 1 && label[a][b] == 0) dfs(a, b);
	}
}

int main() {
	int T; cin >> T;

	for (int i = 0; i < T; i++) {
		int K;
		cin >> M >> N >> K;
		
		reset();
		reset2();

		for (int j = 0; j < K; j++) { //입력
			int x; int y;
			cin >> x >> y;
			input[x][y] = 1;
		}

		int count = 0;
		for (int y = 0; y < N; y++) {
			for (int x = 0; x < M; x++) {
				if (input[x][y] == 1 && label[x][y] == 0) {
					dfs(x, y);
					count++; //필요한 배추 흰지렁이 개수 count
				}
			}
		}

		//output(); output2();//컴파일용
		//cout << '\n';
		cout << count << '\n';
	}
}