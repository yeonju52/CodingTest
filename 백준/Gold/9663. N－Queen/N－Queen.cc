#include <iostream>
using namespace std;
int N;
int m[15];
int answer = 0;

bool isOk(int line){
    for(int i = 0; i < line; i++){
        if(m[i] == m[line] || m[i] - m[line] == line - i || m[i] - m[line] == -(line - i)) return false;
    }
    return true;
}

void DFS(int line, int lb)
{
    //종료조건(한줄씩 다 확인)
    if(line + 1 == N)
    {
        answer++; //체크를 다 끝내고 Nqueen 만족
        return;
    }
    
    m[line] = lb;
    
    
    for (int i = 0 ; i < N; i++){
        m[line + 1] = i;
        if(isOk(line + 1) == true) DFS(line + 1, i);
    }
    
    
}

int main(){
    cin >> N;
    
    for(int i = 0; i < N; i ++){
        DFS(0, i);
    }
    
    cout << answer << endl;
    
}