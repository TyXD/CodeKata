#include <string>
#include <vector>
#include <cmath>

using namespace std;

int answer = 0;
int count = 0;
char characters[5] = {'A', 'E', 'I', 'O', 'U'};

void dfs(string answer_word, string word)
{
    if(answer != 0)
    {
        return;
    }
    
    if(answer_word == word)
    {
        answer = count;
        return;
    }
    
    if(answer_word.size() >= 5)
    {
        return;
    }
    
    for(int i = 0; i < 5; ++i)
    {
        count++;
        dfs(answer_word+characters[i], word);
    }
}

int solution(string word) 
{
    
    answer = 0;
    count = 0;
    dfs("", word);

    return answer;
}