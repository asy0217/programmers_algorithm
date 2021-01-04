#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    vector<int> answer;
    vector<int> order;
    int first;
    int last;
    int k;
    for (int i = 0; i < commands.size(); i++) {
        first = commands[i][0];
        last = commands[i][1];
        k = commands[i][2];
        int q = last - first; 
        if (first == last) {  //first==last이면, k번째 수는 array.at(first-1)로 고정됨
            answer.push_back(array.at(first - 1));
        }
        else {
            for (int i = -1; i < last - first; i++) {
                order.push_back(array.at(first + i));
            }
            sort(order.begin(), order.end());  //벡터 order 정렬
            answer.push_back(order.at(k - 1));//k번째 수는 order.at(k-1)에 위치함
            order.clear();
        }
    }
    return answer;
}