#include <string>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

bool compare(const int& a, const int& b)
{
    return a>b;
}

int solution(int k, int m, vector<int> score) {
    int answer = 0;
    int temp = m;
    map<int, int> table;
    for(const auto& sc : score)
    {
        table[sc]++;
    }
    while(k != 0)
    {
        if(table[k] >= temp)
        {
            answer += m*k;
            table[k] -= temp;
            temp = m;
        }
        else
        {
            temp -= table[k];
            table[k] = 0;
        }
        if(table[k] == 0)
        {
            --k;
        }
    }

    return answer;
}