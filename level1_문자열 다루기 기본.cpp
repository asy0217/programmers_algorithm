/*level1_���ڿ� �ٷ�� �⺻*/
#include <iostream>
#include <string>
#include <vector>

using namespace std;

bool solution(string s) {
    bool answer = true;
    if (s.size() != 4 && s.size() != 6) {
        return false;
    }
    else if (s.size() == 4) {
        int a = stoi(s);
        if ((a / 1000) >= 1 && (a / 1000) < 10) {
            return answer;
        }
        else { return false; }
    }
    else if (s.size() == 6) {
        int b = stoi(s);
        if ((b / 100000) >= 1 && (b / 100000) < 10) {
            return answer;
        }
        else { return false; }
    }
}