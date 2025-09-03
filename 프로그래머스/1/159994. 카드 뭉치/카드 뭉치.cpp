#include <string>
#include <vector>
#include <queue>

using namespace std;

string solution(vector<string> cards1, vector<string> cards2, vector<string> goal) 
{
    string answer = "No";
    queue<string> deck1, deck2, deckG;
    for( const auto& card : cards1)
    {
        deck1.push(card);
    }
    for(const auto& card : cards2)
    {
        deck2.push(card);
    }
    for(const auto& word : goal)
    {
        deckG.push(word);
    }
    
    while(!deckG.empty())
    {
        if(deck1.front() == deckG.front())
        {
            deck1.pop();
            deckG.pop();
            continue;
        }
        else if(deck2.front() == deckG.front())
        {
            deck2.pop();
            deckG.pop();
            continue;
        }
        else
        {
            break;
        }
    }
    
    if(deckG.empty())
    {
        answer = "Yes";
    }
    return answer;
}