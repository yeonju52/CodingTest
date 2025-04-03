#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, M;
int maxi = 19;

void bsearch(int start, int end, vector<int> tree){
    if (start > end){
        return ;
    }
    int sum = 0;
    int mid = (start + end) / 2;
    for (int i = 0; i < N; i++){
        if (tree[i] - mid > 0){
            sum += (tree[i] - mid);
        }
    }
    if (sum == M){
        cout << mid << endl;
        return ;
    }
    else if (sum < M){
        bsearch(start, mid - 1, tree);
    }
    else {
        bsearch(mid + 1, end, tree);
    }
}

int main(){
    cin >> N >> M;
    vector<int> tree(N);
    for (int i = 0; i < N; i++){
        cin >> tree[i];
    }
    int maxi = *max_element(tree.begin(), tree.end());

    bsearch(0, maxi, tree);
}