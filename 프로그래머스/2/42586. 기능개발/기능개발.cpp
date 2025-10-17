#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    int temp;
    while(!progresses.empty())
    {
        temp = 0;
        for(int i = 0; i < progresses.size(); ++i)
        {
            progresses[i] += speeds[i];
        }
        if(progresses[0] >= 100)
        {
            for(int i = 0; i < progresses.size(); ++i)
            {
                if(progresses[i] >= 100)
                {
                    progresses.erase(progresses.begin()+i);
                    speeds.erase(speeds.begin()+i);
                    ++temp;
                    --i;
                }
                else
                {
                    break;
                }
            }
            answer.push_back(temp);
        }
    }
    return answer;
}