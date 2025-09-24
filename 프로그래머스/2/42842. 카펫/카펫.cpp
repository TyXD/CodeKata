#include <string>
#include <vector>

using namespace std;

vector<int> solution(int brown, int yellow) {
    vector<int> answer;
    int height = 1;
    while(true)
    {
        if(yellow % height == 0)
        {
            int width = yellow / height;
            if((width+height+2)*2 == brown)
            {
                answer.push_back(width+2);
                answer.push_back(height+2);
                break;
            }
        }
        height++;
        
    }
    /*
    노란색을 인수분해하고
    그 중에서 가로 세로 2씩 더하고 그걸 2로 곱한 다음에 
    거기서 2를 뺀 값이 브라운이면 
    리턴?
    */
    return answer;
}