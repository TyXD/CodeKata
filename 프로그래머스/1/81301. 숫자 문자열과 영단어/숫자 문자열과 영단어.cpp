#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

enum{
    zero,
    one,
    two,
    three,
    four,
    five,
    six,
    seven,
    eight,
    nine
};

int solution(string s) 
{
    int answer = 0;
    string result = "";
    for(int i = 0; i < s.size(); i++)
    {
        if('a' <= s[i] && s[i] <= 'z')
        {
            if( s[i] == 'z')
            {
                i += 3;
                result += '0';
            }
            else if( s[i] == 'o')
            {
                i += 2;
                result += '1';
            }   
            else if( s[i] == 't')
            {
                if( s[i+1] == 'w')
                {
                    i += 2;
                    result += '2';
                }
                else
                {
                    i += 4;
                    result += '3';
                }
            }
            else if( s[i] == 'f')
            {
                if( s[i+1] == 'o')
                {
                    i += 3;
                    result += '4';
                }
                else
                {
                    i += 3;
                    result += '5';
                }
            }
            else if( s[i] == 's')
            {
                if( s[i+1] == 'i')
                {
                    i += 2;
                    result += '6';
                }
                else
                {
                    i += 4;
                    result += '7';
                }
            }
            else if( s[i] == 'e')
            {
                i += 4;
                result += '8';
            }
            else if( s[i] == 'n')
            {
                i += 3;
                result += '9';
            }
        }
        else
        {
            result += s[i];
        }
    }
    answer = stoi(result);
    return answer;
}