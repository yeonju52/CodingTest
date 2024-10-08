#include <bits/stdc++.h>
using namespace std;

// sort vs stable_sort (동일한 우선순위를 가진 원소들 사이에서의 상대적인 순서가 보장되지 않음. 배열의 순서대로 나오지 않음)
// pair, tuple은 원소의 순서대로 sort 진행 (첫번째 원소 sort -> 두번째 원소 sort), 별도의 구조체를 둘 필요 없음
// 비교함수 내가 정할 수 있음 (bool cmp())

bool cmp(int a, int b){
    if (a % 5 != b % 5) return a % 5 < b % 5;
    return a < b; // a <= b (런타임 에러 발생 가능성 높음)
    // 비교 함수는 두 값이 같을 때(혹은 우선 순위가 같을 때) -> false를 반환해야한다. -> 런타임 에러가 발생할 수 있다
    // 비교 함수의 인자로 STL 또는 클래스 객체 전달 시, reference(&) 사용 -> 불필요한 연산 없애자
}

int main(){
    int a[7] = {1, 2, 3, 4, 5, 6, 7};
    sort(a, a + 7, cmp);

    vector<int> vec = {1, 5, 4, 2, 7};
    sort(vec.begin(), vec.end());
}