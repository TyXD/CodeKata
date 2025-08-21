#include <string>
#include <vector>

using namespace std;

string solution(string phone_number) {
    string answer = "";
    string str;
    for(int i = 0; i < phone_number.size()-4; ++i)
    {
        answer += '*';
    }
    str = phone_number.substr(phone_number.size()-4, 4);
    answer += str;
    
    return answer;
}