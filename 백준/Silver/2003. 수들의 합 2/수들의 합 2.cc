#include <iostream>
using namespace std;

int N, M;
int A[10001];

int main() {
  cin >> N >> M;
  for (int i = 0; i < N; i++) {
    cin >> A[i];
  }

  int result = 0;
  int sum = 0;
  int st = 0, ed = 0;

  for (int i = 0; i < N; i++) {
    while (ed <= N){
      if (sum < M) {
        sum += A[ed];
        ed++;
      }
      if (sum >= M){
        if (sum == M){
          result++;
        }
        sum -= A[st];
        st++;
      }
    }
  }
  cout << result << endl;
}