/*level1_약수의 합*/
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    int answer = 0;
    vector<int> v;
    vector<int>::iterator iter = v.begin(); //iterator은 vector의 원소를 가리키는 포인터
    for (int i = 1; i < n; i++) {
        if (n % i == 0) {
            v.push_back(i);
            v.push_back(n / i);
        }
    }

    for (iter = v.begin(); iter < v.end(); iter++) {  //iter에는 v.begin()이나 v.end()를 대입          
        if (*iter == *(iter + 1)) {                //포인터 iter
            v.erase(iter + 1, v.end());            //iter와 v.end()를 이용한 v.erase
        }
    }

    for (iter = v.begin(); iter < v.end(); iter++) {
        answer += *iter;           //포인터 iter
    }
    return answer;
}