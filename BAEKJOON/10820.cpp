/*
    24.09.29.
    문자열 분석
*/
#include <iostream>
#include <string>

using namespace std;

int main()
{
    while(1)
    {
        int answer[5] = {0, };
        string str;
        getline(cin, str);

        if (cin.fail())
            break;

        for (int i=0; i < str.length(); i++)
        {
            if ('a' <= str[i] && str[i] <= 'z')
                answer[0]++;
            else if ('A' <= str[i] && str[i] <= 'Z')
                answer[1]++;
            else if ('0' <= str[i] && str[i] <= '9')
                answer[2]++;
            else if (str[i] == ' ')
                answer[3]++;
        }                                                   

        cout << answer[0] << ' ';
        cout << answer[1] << ' ';
        cout << answer[2] << ' ';
        cout << answer[3] << '\n';
    }

    return 0;
}