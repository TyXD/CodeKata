#include <string>
#include <vector>

using namespace std;

string solution(string s) {
    string answer = "";
    
    char temp = ' ';
    
    for(auto& word : s)
    {
        if(temp == ' ' && islower(word))
        {
            word = toupper(word);
        }
        if(temp != ' ' && isupper(word))
        {
            word = tolower(word);
        }
        temp = word;
    }
    return s;
}