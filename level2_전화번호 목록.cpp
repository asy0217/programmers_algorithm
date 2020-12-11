#include <string>
#include <vector>
using namespace std;

bool solution(vector<string> phone_book) {
    bool answer = true;
    string tmp;
    for (int i = 0; i < phone_book.size() - 1; i++) {   //정렬
        for (int j = 0; j < phone_book.size() - 1 - i; j++) {
            if (phone_book[j].compare(phone_book[j + 1]) > 0) {
                tmp = phone_book[j];
                phone_book[j] = phone_book[j + 1];
                phone_book[j + 1] = tmp;
            }
        }
    }
    for (int i = 0; i < phone_book.size() - 1; i++) { 
        if (phone_book[i] == phone_book[i + 1].substr(0, phone_book[i].size())) { //접두어인 경우가 있으면
            answer = false;
            break;
        }
    }
    return answer;
}