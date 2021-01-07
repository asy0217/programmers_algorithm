#include <string>
#include <vector>
#include <cmath>

using namespace std;

vector<int> solution(int brown, int yellow) {
    vector<int> answer;
    int area = brown + yellow;//카펫의 면적
    for (int height = 3; height <= sqrt(area); height++) {//세로는 최소 3이상이므로, 세로가 3일 때부터 탐색 시작함. 카펫의 세로는 가로보다 작거나 같아야 하기 때문에 sqrt(area)이하까지 탐색함.
        if (area % height == 0) {
            int width = area / height;//가로 초기화
            if (((height - 2) * (width - 2)) == yellow) { //(세로-2)*(가로-2)==yellow 격자의 개수(이 식이 성립하면, brown 격자가 yellow 격자를 감싸는 배치가 가능함)
                answer.push_back(width);
                answer.push_back(height);
                break;
            }
        }
    }
    return answer;
}