#define _CRT_SECURE_NO_WARNINGS

#include<iostream>
#include <cstdio>
#include <cstring>
using namespace std;

const int MAX = 7;

int arr[MAX][MAX];
int arr1[MAX][MAX];
int arr2[MAX][MAX];
int arr3[MAX][MAX];

void display(int N, const int board[]) {
	for (int j = 0; j < N; j++) {
		cout << board[j];
	}
}

void rotate(int N, const int src[][MAX], int dst[][MAX]) {

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			dst[i][j] = src[N - 1 - j][i];
		}
	}
	return;
}

int main(int argc, char** argv)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int test_case;
	int T;

	//freopen("input.txt", "r", stdin);

	cin >> T;
	for (test_case = 1; test_case <= T; ++test_case)
	{
		int N;
		cin >> N;

		memset(arr, 0, sizeof(arr));
		memset(arr1, 0, sizeof(arr1));
		memset(arr2, 0, sizeof(arr2));
		memset(arr3, 0, sizeof(arr3));

		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				cin >> arr[i][j];
			}
		}

		rotate(N, arr, arr1);
		rotate(N, arr1, arr2);
		rotate(N, arr2, arr3);

		cout << "#" << test_case << "\n";
		for (int i = 0; i < N; i++) {
			display(N, arr1[i]);
			cout << " ";
			display(N, arr2[i]);
			cout << " ";
			display(N, arr3[i]);
			cout << "\n";
		}
	}
	return 0;
}
