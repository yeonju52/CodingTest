#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

struct book{
    int age;
    string name;
};
book b[100000];

bool compare(const book &b1, const book &b2){
    return (b1.age < b2.age);
}

int main(){
    int N;
    cin >> N;
    for (int i = 0; i < N; i++){
        cin >> b[i].age;
        cin.ignore();
        getline(cin, b[i].name);
    }

    stable_sort(b, b + N, compare);
    for (int i = 0; i < N; i++){
        cout << b[i].age << ' ' << b[i].name << '\n';
    }
}