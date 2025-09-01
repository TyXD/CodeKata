#include <string>
#include <vector>
#include <set>

using namespace std;

vector<int> solution(vector<int> numbers) {
    vector<int> answer;
    set<int> con;
    for (int i = 0; i < numbers.size(); ++i)
    {
        for(int j = i+1; j < numbers.size(); ++j)
        {
            con.insert(numbers[i] + numbers[j]);
        }
    }
    for(auto& c : con)
    {
        answer.push_back(c);
    }
    return answer;
}