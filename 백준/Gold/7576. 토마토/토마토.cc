//N행 M열
//익은 토마토가 인접한 곳에 있으면 익지않은 토마토도 익은 토마토가 됨.
//철수는 창고에 보관된 토마토들이 며칠이 지나면 다 익게 되는지, 그 최소 일수를 알고 싶어 한다.
//
//며칠이 지나면 토마토들이 모두 익는지, 그 최소 일수를 구하는 프로그램을 작성하라.
//
//단, 상자의 일부 칸에는 토마토가 들어있지 않을 수도 있다.
//
// 2 ≤ M, N ≤ 1, 000 이다.둘째 줄부터는 하나의 상자에 저장된 토마토들의 정보가 주어진다.
//	즉, 둘째 줄부터 N개의 줄에는 상자에 담긴 토마토의 정보가 주어진다.
//	하나의 줄에는 상자 가로줄에 들어있는 토마토의 상태가 M개의 정수로 주어진다.
//	정수 1은 익은 토마토, 정수 0은 익지 않은 토마토, 정수 - 1은 토마토가 들어있지 않은 칸을 나타낸다.
//
//
//여러분은 토마토가 모두 익을 때까지의 최소 날짜를 출력해야 한다.
//만약, 저장될 때부터 모든 토마토가 익어있는 상태이면 0을 출력해야 하고, 
//토마토가 모두 익지는 못하는 상황이면 - 1을 출력해야 한다.
//

#include <iostream>
#include <vector>
#include <queue>
using namespace std;
#define X first
#define Y second
int MAP[1005][1005];
int dist[1005][1005];
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0, -1, 0, 1 };
int N, M;
vector<pair<int, int> > canEat;
vector<pair<int, int> > cannotEat;
int maxV;
void Input()
{
	for (int i = 0; i < 1005; i++)
		fill(dist[i], dist[i] + 1005, -1);
	cin >> N >> M;
	for (int i = 0; i< M; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cin >> MAP[i][j];
			if (MAP[i][j] == 1) canEat.push_back(make_pair(i, j));
			else if (MAP[i][j] == 0) cannotEat.push_back(make_pair(i, j));
			else if (MAP[i][j] == -1) dist[i][j] = -2;
		}
	}
}
void Solution()
{
	queue<pair<int, int>> Q;
	for (pair<int, int> i : canEat)
	{
		Q.push(make_pair(i.X, i.Y));
		dist[i.X][i.Y] = 0;
	}

	while (!Q.empty())
	{
		pair<int, int> cur = Q.front(); Q.pop();

		for (int dir = 0; dir < 4; dir++)
		{
			int nx = cur.X + dx[dir];
			int ny = cur.Y + dy[dir];

			if (nx < 0 || nx >= M || ny < 0 || ny >= N) continue;
			if (MAP[nx][ny] == -1) continue;
			if (dist[nx][ny] != -1) continue;

			Q.push(make_pair(nx, ny));
			dist[nx][ny] = dist[cur.X][cur.Y] + 1;
			maxV = dist[nx][ny];
			/*if (cannotEat.size() != 0)
			{
				vector<pair<int, int>>::iterator it = cannotEat.begin();
				while (it != cannotEat.end())
				{
					if (nx == (*it).X && ny == (*it).Y) {
						it = cannotEat.erase(it);
						if (it == cannotEat.end())
						{
							break;
						}
					}

					it++;
				}
			}*/
		}
	}
}
int main()
{
	Input();
	if (cannotEat.size() == 0) {
		cout << 0;
		return 0;
	}
	Solution();

	for (int i = 0; i < M; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (dist[i][j] == -1) {
				cout << -1;
				return 0;
			}
		}
	}
	cout << maxV;
}