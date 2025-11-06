#include <string>
#include <vector>

using namespace std;

int Zero = 0;
int One = 0;


bool United(vector<vector<int>>& arr, int x, int y, int size)
{
    int unitedNum = arr[x][y];
    for(int i = x; i < size + x; ++i)
    {
        for(int j = y; j < size + y; ++j)
        {
            if(unitedNum != arr[i][j])
            {
                return false;
            }
        }
    }
    return true;   
}

void Quad(vector<vector<int>>& arr, int x, int y, int size)
{
    if(United(arr, x, y, size))
    {
        if(arr[x][y] == 0)
        {
            Zero++;
        }
        else
        {
            One++;
        }
        return;
    }
   
    int newSize = size / 2;
    Quad(arr, x, y, newSize);                        
    Quad(arr, x, y + newSize, newSize);               
    Quad(arr, x + newSize, y, newSize);      
    Quad(arr, x + newSize, y + newSize, newSize);  
}

vector<int> solution(vector<vector<int>> arr) {
    vector<int> answer;
    Zero = 0;
    One = 0;
    
    Quad(arr, 0, 0, arr.size());
    answer.push_back(Zero);
    answer.push_back(One);
    return answer;
}