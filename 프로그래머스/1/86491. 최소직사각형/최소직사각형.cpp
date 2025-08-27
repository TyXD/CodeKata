#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<vector<int>> sizes) {
    int answer = 0;
    vector<int> mSize = {0, 0};
    for(auto& it : sizes)
    {
        sort(it.begin(), it.end());
        if(mSize[0] < it[0])
        {
            mSize[0] = it[0];
        }
        if(mSize[1] < it[1])
        {
            mSize[1] = it[1];
        }
    }
    answer = mSize[0] * mSize[1];
    return answer;
}