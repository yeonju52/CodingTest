#include <iostream>
#include <vector>
using namespace std;

int dx[4] = {0, 1, 0, -1}; // row 열
int dy[4] = {1, 0, -1, 0}; // col 행
vector<vector<int>> snake = {{1, 1}}; // 뱀의 초기값
vector<vector<int>> apple; // vector는 callByReference 아닌가?
int curX, curY;

void playSnake(int* tInterval, int dir, int* result){ // 초가 아닌 기간, 방향 벡터
    for(int t = tInterval[0] + 1; t <= tInterval[1]; t++){
        // 뱀 이동
        curX = snake.back()[0] + dx[dir];
        curY = snake.back()[1] + dy[dir];
        snake.push_back({curX, curY});
        
        // 위치에 대한 유효성 확인 (벽이나 자기자신과 부딪히면)
        result[1] = t; // isValid[0]: 유효성 확인 isValid[1]: 현재 sec

        if (curX <= 0 || curY <= 0 || curX > apple.size() - 1 || curY > apple.size() - 1){ // N: apple.size() = N + 1
            result[0] = 0;
            return ;
        }
        else {
            for (int i = 0; i < snake.size() - 1; i++){ // 현재 이동 빼고
                if(snake[i][0] == curX && snake[i][1] == curY){
                    result[0] = 0;
                    return ;
                }
            }
        }

        // 사과 유무 확인 (꼬리 유지 or 삭제)
        if (apple[curX][curY] == 1){
            apple[curX][curY] = 0;
        }
        else {
            snake.erase(snake.begin());
        }
    }
    return ;
}

int main(){
    int N, K, L;
    int x, y;

    cin >> N >> K;
    vector<vector<int>> arr(N + 1, vector<int>(N + 1, 0));
    apple = arr;
    for (int i = 0; i < K; i++){
        cin >> x >> y;
        apple[x][y] = 1;
    }

    int dir = 0;
    int prev = 0;
    int sec = 0;
    char rot;
    int tInterval[2] = {0, 0};
    int result[2] = {1, 0}; // 게임 플레이 여부, 게임 끝난 시간

    cin >> L;
    for(int i = 0; i < L; i++){
        cin >> sec >> rot;
        tInterval[1] = sec;
        if (result[0] == 1){
            playSnake(tInterval, dir, result);
        }

        // tInterval과 dir 업데이트
        tInterval[0] = result[1];
        if (rot == 'D'){
            dir = (dir + 1 + 4) % 4;
        }
        else if (rot == 'L') {
            dir = (dir - 1 + 4) % 4;
        }
    }

    while (result[0] == 1){
        tInterval[1] += 1;
        playSnake(tInterval, dir, result);
        tInterval[0] = result[1];
    }

    cout << result[1] << endl;   
}