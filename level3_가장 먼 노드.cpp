/*�׷��� �˰���:bfs/dfs Ž������� ������ �˰�����.
cf)bfs:�湮 üũ�ϱ� ���� �迭, �׷����� �������(+�ܹ���,����⵵ ���) �ľ��ϱ� ���� graph �迭(������� ���� ��, ���Ῡ�� Ȯ��)�̳� connected ����(���Ῡ�� Ȯ��) ����� �ʿ�� ��.
cf)Ž�����:bfs,dfs,�̺�Ž��,����Ž��
*/
#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int solution(int n, vector<vector<int>> edge) {
    int answer = 0, max = 0;
    queue<int> q;
    bool visited[20000] = { false, };//bfs�� �湮�� üũ�ϴ� �迭�� �������� ��
    bool check[20001][20001] = { false, };//�׷����� ������� �ľ��ϱ� ���� graph �迭
    int dist[20000] = { 0, };//depth�� ��Ÿ���� �迭

    for (int i = 0; i < edge.size(); i++)//for������ check�迭�� �׷����� �̾��ش�. 
    {
        check[edge[i][0]][edge[i][1]] = true;//check[3][6]=1
        check[edge[i][1]][edge[i][0]] = true;//check[6][3]=1,�׷��� ���� ������̹Ƿ� ����� ��� ó������
    }

    q.push(1);//1�� ��� push. 1�� ��带 0���� ǥ������ �ʰ�, ���� �״�� 1�� ����ϵ��� �ڵ� «. �ٸ� ���鵵 ����������
    visited[1] = true;//1�� ��� �湮ǥ��

    while (q.empty() == 0)
    {
        int node = q.front();//node�� 1 ����
        q.pop();

        for (int i = 2; i <= n; i++)//n���� ����, i<=n
        {
            if (check[node][i] == true && visited[i] == false)
            {//1�� ���� ������ְ�&&�湮 ���� ���� �����
                q.push(i);
                visited[i] = true;
                dist[i] = dist[node] + 1;//dist[2]=1, dist[3]=1
                                         //dist[4]=2, dist[5]=2
                                         //dist[6]=2
                if (dist[i] > max)
                    max = dist[i];//max ����
            }
        }
    }

    for (int i = 1; i <= n; i++)
    {
        if (max == dist[i])
            answer++;
    }

    return answer;
}