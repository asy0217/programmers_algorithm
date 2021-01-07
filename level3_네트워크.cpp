/*1.bfs�� �湮�߰ų�, �湮���� ���� ����� ������ ���� ������ ���Ǵ� �˰����̴�. bfs�˰����� Ǫ�� �������� queue�� ����Ѵ�.
2.dfs�� ��͸� ����Ѵ�(bfs�� ��͸� ������� �ʴ´�).
3.vector�� stack �ڷᱸ���� LIFO�̰�, queue�� FIFO�̴�.*/
#include <string>
#include <vector>
#include <queue>

using namespace std;
const int MAX = 200; //��ǻ�� ����(����� ����) n�� �ִ밪
bool check[MAX] = { 0, };//�� ��� �湮�ߴ��� üũ��. �湮������1, �湮�������� 0.
void bfs(int start, int n, vector<vector<int>> computers) {
    queue<int> q;
    check[start] = true;//�湮�����Ƿ�, 1�� �ٲ���
    for (int i = 0; i < n; i++) {
        int connected = computers[start][i]; //�ٸ� ������ ���� ���� �ľ�
        if (connected == 1 && check[i] == 0) {//����Ǿ��µ�, ���� �湮���� ���� �����
            check[i] = true;//check�ϴ� ���� ����� ��� �� �湮���� ���� ���� �湮üũ �� ť�� Ǫ��
            q.push(i);
        }
    }
    while (q.empty() == 0) { //queue�� �� �������
        int x = q.front();
        q.pop();//���Լ���
        for (int i = 0; i < n; i++) {
            int connected = computers[x][i];
            if (connected == 1 && check[i] == 0) {
                check[i] = true;//check�ϴ� ���� ����� ��� �� �湮���� ���� ���� �湮üũ �� ť�� Ǫ��
                q.push(i);
            }
        }
    }
}
int solution(int n, vector<vector<int>> computers) {
    int answer = 0;
    for (int i = 0; i < n; i++) {
        if (check[i] == 0) { //ù��° ���� ������ ����
//i=0����, bfs�Լ��� ���� ù��° ���� ������ִ� ������ ��� check[i]=1�� ����->ù��° ���� ���� �ȵ� ��尡, bfs�Լ��� ���� ������ִ� ������ ��� check[i]=1�� ����->...
            bfs(i, n, computers); //bfs�� ���� ù��° ���� ����� ��Ʈ��ũ���� ��� check[i]=1�� ����, �湮�� ���� ǥ����
            answer += 1; //�������� ��ȸ �� �湮���� ���� ���� ���� ��Ʈ��ũ�� ���Ե��� �ʱ� ������ ���ο� ��Ʈ��ũ�� �������� ����, answer+1
        }
    }
    return answer;
}