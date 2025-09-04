#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> solution(vector<int> answers) {
    vector<int> answer;
    
    vector<int> supo1 = {1,2,3,4,5};
    vector<int> supo2 = {2,1,2,3,2,4,2,5};
    vector<int> supo3 = {3,3,1,1,2,2,4,4,5,5};
    
    vector<int> supo = {0, 0, 0};
    
    for( int i = 0; i < answers.size(); ++i)
    {
        if(answers[i] == supo1[(i)%5])
        {
            supo[0]++;
        }
        if(answers[i] == supo2[(i)%8])
        {
            supo[1]++;
        }
        if(answers[i] == supo3[(i)%10])
        {
            supo[2]++;
        }
    }
    int max_score = *max_element(supo.begin(), supo.end());
    
    for(int i = 0; i < supo.size(); ++i)
    {
        if(max_score == supo[i])
        {
            answer.push_back(i+1);
        }
    }
    
           
    
    return answer;
}