#include <string>
#include <vector>
#include <algorithm>
using namespace std;

string solution(string s, string skip, int index) {
    string answer = "";
    vector<char>alphabet = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};
    
    for ( const auto& sk : skip)
    {
        auto it = find(alphabet.begin(), alphabet.end(), sk);
        if(it != alphabet.end())
        {
            alphabet.erase(it);
        }
    }
    for(auto& ch : s)
    {
        auto it = find(alphabet.begin(), alphabet.end(), ch);
        int in = it - alphabet.begin();
        in = (in+index)%alphabet.size();
        answer += alphabet[in];
    }
    return answer;
}