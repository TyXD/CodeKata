#include <string>
#include <vector>
#include <cmath>

using namespace std;

int solution(string word) {
    string vowels = "AEIOU";
    int weights[5] = {781, 156, 31, 6, 1};
    int answer = 0;
    
    for(int i = 0; i < word.length(); ++i) {
        int index = vowels.find(word[i]);
        answer += index * weights[i] + 1;
    }
    
    return answer;
}
