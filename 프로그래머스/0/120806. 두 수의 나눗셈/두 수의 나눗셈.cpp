#include <string>
#include <vector>

using namespace std;

int solution(int num1, int num2) {
    float result = (float)num1 / (float)num2;
    result = result * 1000;
    return (int)result;
}