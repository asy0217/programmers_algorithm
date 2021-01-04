
/*�׸��� �˰�����, �ּҰ����� Ȯ���ϴ� ������ �ʿ���.
�������� ����� ���� �ĺ� ������ ��������, �ĺ����� ���ؼ� �ּҰ� ���ϴ� ������ ������*/
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int solution(string name) {
    int answer = 0;
    int nowidx = 0;
    string tmp = "";
    for (int i = 0; i < name.size(); i++) { //tmp�� ��� ���Ҹ� A�� �ʱ�ȭ
        tmp.push_back('A');
    }
    while (1) {
        answer += min(name[nowidx] - 'A', 'Z' - name[nowidx] + 1);  //������, �Ʒ����� �� �ּҰ�
        tmp[nowidx] = name[nowidx];
        if (name == tmp) {
            break;
        }
        //�����̵�:while�� �������� �����̵�����, �������̵����� �Ǵܵ�(�ܹ��� ����, �Դٰ��� ����)
        int leftidx = nowidx;
        int left_cnt = 0; //while�� �������� 0���� ����
        while (tmp[leftidx] == name[leftidx]) {
            leftidx--;
            left_cnt++;
            if (leftidx < 0) {
                leftidx = name.size() - 1;
            }
        }
        //�������̵�:while�� �������� �����̵�����, �������̵����� �Ǵܵ�(�ܹ��� ����, �Դٰ��� ����)
        int rightidx = nowidx;
        int right_cnt = 0; //while�� �������� 0���� ����
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