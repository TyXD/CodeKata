#include <string>
#include <vector>

using namespace std;

int solution(int n, int m, vector<int> section) {
    int answer = 0;
    int index = 0;
    
    for( const auto& sector : section)
    {
        if(index == 0)
        {
            answer++;
            index = sector;
        }
        else if( m <= sector - index )
        {
            answer++;
            index = sector;
        }
    }
    return answer;
}