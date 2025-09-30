
#include <string>
#include <vector>
#include <unordered_set>

using namespace std;

int solution(vector<int> elements) {
    unordered_set<int> sums;
    int n = elements.size();

    for (int i = 0; i < n; ++i) 
    {
        int current_sum = 0;

        for (int j = 0; j < n; ++j) 
        {
            int index = (i + j) % n;
            current_sum += elements[index];
            sums.insert(current_sum);
        }
    }

    return sums.size();
}