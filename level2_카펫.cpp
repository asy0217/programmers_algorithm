#include <string>
#include <vector>
#include <cmath>

using namespace std;

vector<int> solution(int brown, int yellow) {
    vector<int> answer;
    int area = brown + yellow;//ī���� ����
    for (int height = 3; height <= sqrt(area); height++) {//���δ� �ּ� 3�̻��̹Ƿ�, ���ΰ� 3�� ������ Ž�� ������. ī���� ���δ� ���κ��� �۰ų� ���ƾ� �ϱ� ������ sqrt(area)���ϱ��� Ž����.
        if (area % height == 0) {
            int width = area / height;//���� �ʱ�ȭ
            if (((height - 2) * (width - 2)) == yellow) { //(����-2)*(����-2)==yellow ������ ����(�� ���� �����ϸ�, brown ���ڰ� yellow ���ڸ� ���δ� ��ġ�� ������)
                answer.push_back(width);
                answer.push_back(height);
                break;
            }
        }
    }
    return answer;
}