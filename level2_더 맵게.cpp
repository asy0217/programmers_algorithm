/*heap �˰���: �켱���� ť(priority_queue<int, vector<int>, greater<int>> PQ;) �ڷᱸ�� ����ϴ� �˰���. 
�켱���� ť�� �� ������ �������(�Ϲ����� ť�� FIFO) �켱������ ���� �����Ͱ� ���� ����(pop/top�� ��). 
cf)�켱���� ť�� ���� ��������/�������� �켱���� ������ �� �����. priority_queue<int, vector<int>, greater<int>> PQ; �ϸ�
������������(�����ͺ���) pop/top ��. greater��� less���� ������������(ū �ͺ���) pop/top ��.
cf)greater,less�� �ƴ϶�, ���� Ŭ���� ����, �켱���� ���� ����⵵ ������
cf)������, push�� ������� ���ĵ�(����,ť,�켱���� ť ���)
cf)�켱���� ť��, sort�� �̿��� ��������/�������� ���� or ���� ������ �ּ� ������ �ͺ��� ȿ������ ���Ƽ� �����
*/
#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(vector<int> scoville, int K) {
    priority_queue<int, vector<int>, greater<int>> PQ;//�켱���� ť ����
    int answer = 0;
    for (int i = 0; i < scoville.size(); i++) {
        PQ.push(scoville[i]);
    }
    int first, second;
    while (PQ.top() < K) {//���� ���� ����<K�� �����Ѵٸ�
        if (PQ.size() <= 1) {
            return -1;//��� ������ ���ں� ������ K�̻����� ���� �� ���� ��쿡�� -1�� return
        }
        first = PQ.top();
        PQ.pop();//ť���� ����
        second = PQ.top();
        PQ.pop();//ť���� ����
        first = first + second * 2;
        PQ.push(first);//���Ĵ�� �켱���� ť�� �̿��ϸ�, push �Ŀ� �ٽ� �������� �ʾƵ��Ǽ�, ȿ������ ����
        answer++;
    }
    return answer;
}