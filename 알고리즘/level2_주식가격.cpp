#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> solution(vector<int> prices) {
    vector<int> answer;
    int count = 0;
    for (int i = 0; i < prices.size(); i++) {
        for (int j = i; j < prices.size(); j++) {
            count++;
            if (prices[i] > prices[j]) {
                break;
            }
        }
        answer.push_back(count - 1);
        count = 0;
    }
    return answer;
}