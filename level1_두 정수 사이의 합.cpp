/*level1_두 정수 사이의 합*/
#include <iostream>
#include <string>
#include <vector>

using namespace std;

long long solution(int a, int b) {
    long long answer = 0;
    long long long_long_a = (long long)a;
    long long long_long_b = (long long)b;
    if (long_long_a <= long_long_b) {
        for (long_long_a; long_long_a <= long_long_b; long_long_a++) {
            answer += long_long_a;
        }
    }
    else {
        for (long_long_b; long_long_b <= long_long_a; long_long_b++) {
            answer += long_long_b;
        }
    }
    return answer;
}