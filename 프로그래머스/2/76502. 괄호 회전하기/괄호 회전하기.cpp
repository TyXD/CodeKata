#include <string>
#include <vector>
#include <stack>

using namespace std;

bool isCorrect(string s) 
{
    stack<char> st;
    for (char c : s) 
    {
        if (c == '(' || c == '{' || c == '[') 
        {
            st.push(c);
        } 
        else 
        {
            if (st.empty()) 
            {
                return false;
            }
            
            if (c == ')' && st.top() == '(') 
            {
                st.pop();
            } 
            else if (c == '}' && st.top() == '{') 
            {
                st.pop();
            } 
            else if (c == ']' && st.top() == '[') 
            {
                st.pop();
            } 
            else 
            {
                return false;
            }
        }
    }
    return st.empty();
}

int solution(string s) {
    int answer = 0;
    if (s.length() % 2 != 0) {
        return 0;
    }

    for (int i = 0; i < s.length(); ++i) {
        if (isCorrect(s)) {
            answer++;
        }
        char front = s.front();
        s.erase(s.begin());
        s.push_back(front);
    }

    return answer;
}