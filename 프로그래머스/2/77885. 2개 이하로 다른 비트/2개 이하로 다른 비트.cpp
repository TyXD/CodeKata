#include <string>
#include <vector>

using namespace std;

vector<long long> solution(vector<long long> numbers) {
    vector<long long> answer;
    for(const long long& number : numbers)
    {
        if(number % 2 == 0)
        {
            answer.push_back(number+1);
        }
        else
        {
            long long mask = number ^ (number+1);
            long long add = (mask + 1) >> 2;
            answer.push_back(number+add);
        }
    }
    return answer;
}