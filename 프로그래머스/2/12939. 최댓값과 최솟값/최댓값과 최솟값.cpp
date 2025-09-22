#include <string>
#include <vector>
#include <algorithm>
#include <sstream>
#include <iostream>

using namespace std;

string solution(string s) {
    string answer = "";
    string stringtoint;
    
    stringstream toInt;
    toInt.str(s);
    toInt >> stringtoint;
    int maxInt = stoi(stringtoint);
    int minInt = stoi(stringtoint);
    while(toInt >> stringtoint)
    {
        maxInt = max(maxInt, stoi(stringtoint));
        minInt = min(minInt, stoi(stringtoint));
    }
    answer += to_string(minInt);
    answer += " ";
    answer += to_string(maxInt);
    return answer;
}