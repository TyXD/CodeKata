#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> solution(vector<int> answers) {
    vector<vector<int>> patterns = {
        {1,2,3,4,5},
        {2,1,2,3,2,4,2,5},
        {3,3,1,1,2,2,4,4,5,5}
    };
    
    vector<int> scores(3);
    
    for(int i = 0; i < 3; ++i) {
        scores[i] = count_if(answers.begin(), answers.end(), 
            [&, i, idx = 0](int ans) mutable {
                return ans == patterns[i][idx++ % patterns[i].size()];
            });
    }
    
    int max_score = *max_element(scores.begin(), scores.end());
    
    vector<int> answer;
    for(int i = 0; i < 3; ++i) {
        if(scores[i] == max_score) {
            answer.push_back(i + 1);
        }
    }
    
    return answer;
}
