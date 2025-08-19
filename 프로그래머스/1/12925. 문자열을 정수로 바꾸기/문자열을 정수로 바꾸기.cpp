#include <string>
#include <vector>
#include <cmath>
using namespace std;

int solution(string s) {
    int sign = 1;
    int result = 0;
    if(s[0] == '+' || s[0] == '-')
    {
        if(s[0] == '+')
            sign = 1;
        else
            sign = -1;
        for(int i = 1; i < s.length(); ++i)
        {
            result += (s[s.length()-i] - '0') * (int)pow(10, i-1);
        }
        result *= sign;
    }
    else
    {
        for(int i = 0; i < s.length(); ++i)
        {
            result += (s[s.length()-1-i] - '0') * (int)pow(10, i);
        }
    }
    return result;
}