/*level1_����� ��*/
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    int answer = 0;
    vector<int> v;
    vector<int>::iterator iter = v.begin(); //iterator�� vector�� ���Ҹ� ����Ű�� ������
    for (int i = 1; i < n; i++) {
        if (n % i == 0) {
            v.push_back(i);
            v.push_back(n / i);
        }
    }

    for (iter = v.begin(); iter < v.end(); iter++) {  //iter���� v.begin()�̳� v.end()�� ����          
        if (*iter == *(iter + 1)) {                //������ iter
            v.erase(iter + 1, v.end());            //iter�� v.end()�� �̿��� v.erase
        }
    }

    for (iter = v.begin(); iter < v.end(); iter++) {
        answer += *iter;           //������ iter
    }
    return answer;
}