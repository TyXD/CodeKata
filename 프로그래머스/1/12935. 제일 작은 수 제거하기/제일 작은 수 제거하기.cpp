#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> arr) {
    vector<int> answer;
    int i = 0;
    int temp = arr[0];
    int index = 0;
    if(arr.size() == 1)
    {
        answer.push_back(-1);
        return answer;
    }
    
    for(i; i < arr.size(); ++i)
    {
        if(temp > arr[i])
        {
            temp = arr[i];
            index = i;
        }
    }
    arr.erase(arr.begin() + index);
    return arr;
}