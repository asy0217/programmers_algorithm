/*level1_���ڿ��� ������ �ٲٱ�*/
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int solution(string s) {
    int answer = 0;
    if (*(s.begin()) == '+') {
        s.erase(s.begin());
        answer = stoi(s);
    }
    else if (*(s.begin()) == '-') {
        s.erase(s.begin());
        answer = -stoi(s);
    }
    else {
        answer = stoi(s);
    }
    return answer;
}