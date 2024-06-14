#include <iostream>
#include <string>
using namespace std;

int min(string s)
{
    int result = 0;
    string temp = "";
    bool minus = false;
    for (int i = 0; i <= s.size(); i++)
    {
        if (s[i] == '+' || s[i] == '-' || s[i] == '\0')
        {
            if (minus)
                result -= stoi(temp);
            else
                result += stoi(temp);
            temp = "";

            if (s[i] == '-')
                minus = true;
            continue;
        }

        temp += s[i];
    }
    return result;
}

int main() {
    string str;
    getline(cin, str); //cin >> str; 과 동일?

    cout << min(str) << endl;

    return 0;
}