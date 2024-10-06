// 틀린 이유
// roatate() 에서 tmp[]에 변한 좌표를 넣어야 함. 솔직히 이해 안됨.
#include <bits/stdc++.h>
using namespace std;

int N, M, K;
int r, c;
int board[42][42];
int stk[12][12];

bool putSTK(int x, int y){
    for (int i = 0; i < r; i++){
        for (int j = 0; j < c; j++){
            if (board[x + i][y + j] == 1 && stk[i][j] == 1) return false;
        }
    }
    for (int i = 0; i < r; i++){
        for (int j = 0; j < c; j++){
            if (stk[i][j] == 1) board[x + i][y + j] = 1;
        }
    }
    return true;
}

void rotate(){
    int tmp[12][12];
    // cout << "rotation\n";
    for (int i = 0; i < r; i++){
        for (int j = 0; j < c; j++){
            tmp[j][r - 1 - i ] = stk[i][j];
        }
    }
    for (int i = 0; i < c; i++){
        for (int j = 0; j < r; j++){
            stk[i][j] = tmp[i][j];
            // cout << stk[i][j] << " ";
        }
        // cout << endl;
    }
    swap(r, c);
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N >> M >> K;

    while(K--){
        cin >> r >> c;
        for (int x = 0; x < r; x++){
            for (int y = 0; y < c; y++){
                cin >> stk[x][y];
            }
        }
        
        bool isPut = false;
        for (int rot = 0; rot < 4; rot++){
            for (int x = 0; x <= N - r; x++){
                if (isPut) break;
                for (int y = 0; y <= M - c; y++){
                    if (putSTK(x, y)) {
                        isPut = true;
                        break;
                    }
                }
            }
            if (isPut) break;
            rotate();
        }
        // cout << endl << K << endl;
        // for (int x = 0; x < N; x++){
        //     for (int y = 0; y < M; y++){
        //         cout << board[x][y];
        //     }
        //     cout << endl;
        // }
    }
    int cnt = 0;
    for (int x = 0; x < N; x++){
        for (int y = 0; y < M; y++){
            if (board[x][y]) cnt++;
        }
    }
    cout << cnt;
}