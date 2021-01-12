/*������ȹ�� �˰���:�κ� ������ ���� �� ��ȭ���� ���Ѵ�->�ݺ���(bottom-up����� �ݺ����� �̿��ؼ� �����ذ���)��
��ȭ���� �̿��Ͽ�, Bottom-up(���� ��������ū ������ Ȯ���ϸ鼭 �����ذ��ϴ� ����� �ǹ�) ������� �����ذ�*/
#include <string>
#include <vector>
#include <algorithm>
#define max_int 499

using namespace std;

int answer = 0;//�迭d(����� ���� ������ �迭)�� �� �࿡��, �ִ밪�� answer�� ���Ե�
int height = 0;
int d[max_int][max_int] = { 0, };//�� ����� ���� �����ؼ� ������ ���� �迭
//ex){{7},{10,15},{18,max(10,15)+1,15},...}

int solution(vector<vector<int>> triangle) {
    d[0][0] = triangle[0][0];//�� ����� ���� ������Ŵ
    answer = d[0][0];//ù��° �࿡�� �ִ밪�� d[0][0]�̹Ƿ�, d[0][0]�� answer�� ������
    height = (int)triangle.size();//�ﰢ���� ���̸� ��� 
    for (int i = 1; i < height; i++) {//�ι�° ����� ����:�� ����� ���� ������Ŵ
        for (int j = 0; j <= i; j++) {
            if (j == 0) {// 1) �ﰢ�� ���� ���� ���� ���
                d[i][j] = d[i - 1][j] + triangle[i][j]; //��ȭ�� 
            }
            else if (j == i) {// 2) �ﰢ�� ���� ������ ���� ���
                d[i][j] = d[i - 1][j - 1] + triangle[i][j]; //��ȭ��
            }
            else {// 3) �ﰢ�� ����, ������ ���� �ƴ� ������ ���
                d[i][j] = max(d[i - 1][j - 1], d[i - 1][j]) + triangle[i][j]; //��ȭ��
            }
            answer = max(answer, d[i][j]);//�� �࿡ ���ؼ� �ִ밪 ����:�迭d(����� ���� ������ �迭)�� �� �࿡��, �ִ밪�� answer�� ���Ե�.
        }
    }
    return answer;
}