
/*그리디 알고리즘은, 최소값인지 확인하는 과정이 필요함.
여러가지 경우의 수로 후보 값들을 가져오고, 후보끼리 비교해서 최소값 구하는 과정이 들어가야함*/
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int solution(string name) {
    int answer = 0;
    int nowidx = 0;
    string tmp = "";
    for (int i = 0; i < name.size(); i++) { //tmp의 모든 원소를 A로 초기화
        tmp.push_back('A');
    }
    while (1) {
        answer += min(name[nowidx] - 'A', 'Z' - name[nowidx] + 1);  //위방향, 아래방향 중 최소값
        tmp[nowidx] = name[nowidx];
        if (name == tmp) {
            break;
        }
        //왼쪽이동:while문 돌때마다 왼쪽이동할지, 오른쪽이동할지 판단됨(단방향 말고도, 왔다갔다 가능)
        int leftidx = nowidx;
        int left_cnt = 0; //while문 돌때마다 0으로 리셋
        while (tmp[leftidx] == name[leftidx]) {
            leftidx--;
            left_cnt++;
            if (leftidx < 0) {
                leftidx = name.size() - 1;
            }
        }
        //오른쪽이동:while문 돌때마다 왼쪽이동할지, 오른쪽이동할지 판단됨(단방향 말고도, 왔다갔다 가능)
        int rightidx = nowidx;
        int right_cnt = 0; //while문 돌때마다 0으로 리셋
        while (tmp[rightidx] == name[rightidx]) {
            rightidx++;
            right_cnt++;
        }

        if (left_cnt < right_cnt) {
            answer += left_cnt;
            nowidx = leftidx;
        }
        else {
            answer += right_cnt;
            nowidx = rightidx;
        }
    }
    return answer;
}