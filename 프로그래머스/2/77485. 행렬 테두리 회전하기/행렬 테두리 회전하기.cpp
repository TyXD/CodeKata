#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> solution(int rows, int columns, vector<vector<int>> queries) {
    vector<int> answer;
    vector<vector<int>> matrix(rows, vector<int>(columns, 0));
    
    int num = 0;
    for(int i = 0; i < rows; ++i)
    {
        for(int j = 0; j < columns; ++j)
        {
            ++num;
            matrix[i][j] = num;
        }
    }
    
    for(const auto& query : queries)
    {       
        int row_1 = query[0] - 1;
        int column_1 = query[1] - 1;
        int row_2 = query[2] - 1;
        int column_2 = query[3] - 1;
        
        int temp = matrix[row_1][column_1];
        int min_num = temp;
        
        for(int i = row_1; i < row_2; ++i )
        {
            int value = matrix[i + 1][column_1];
            matrix[i][column_1] = value;
            min_num = min(min_num, value);
        }
        
        for(int i = column_1; i < column_2; ++i )
        {
            int value = matrix[row_2][i + 1];
            matrix[row_2][i] = value;
            min_num = min(min_num, value);
        }
        
        for(int i = row_2; i > row_1; --i )
        {
            int value = matrix[i - 1][column_2];
            matrix[i][column_2] = value;
            min_num = min(min_num, value);
        }
        
        for(int i = column_2; i > column_1; --i )
        {
            int value = matrix[row_1][i - 1];
            matrix[row_1][i] = value;
            min_num = min(min_num, value);
        }
        
        matrix[row_1][column_1 + 1] = temp;
        answer.push_back(min_num);
    }
    return answer;
}