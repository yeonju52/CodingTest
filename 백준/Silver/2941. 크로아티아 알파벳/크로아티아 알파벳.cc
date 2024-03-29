#include <iostream>
#include <vector>
using namespace std;

int main(){
    string s;
    string check;
    int cnt = 0;
    int flag = 0;
    vector<string> arr2 = {"c=", "c-", "d-", "lj", "nj", "s=", "z="};
    
    getline(cin, s);
    
    while(s.length() > 0){
        cnt++;
        
        check = s.substr(0, 3);
        if (check == "dz="){
            s = s.substr(3);
            continue;
        }

        check = s.substr(0, 2);
        for(int i = 0; i < arr2.size(); i++){
            if(check == arr2[i]){
                s = s.substr(2);
                flag = 1;
                break;
            }
        }
        if (flag == 0){
            s = s.substr(1);
        }
        flag = 0;
    }
    cout << cnt << endl;
}