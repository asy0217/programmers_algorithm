/*그래프 알고리즘:bfs/dfs 탐색기법을 응용한 알고리즘임.
cf)bfs:방문 체크하기 위한 배열, 그래프의 연결관계(+단방향,양방향도 고려) 파악하기 위한 graph 배열(연결관계 저장 후, 연결여부 확인)이나 connected 변수(연결여부 확인) 사용이 필요로 됨.
cf)탐색기법:bfs,dfs,이분탐색,완전탐색
*/
#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int solution(int n, vector<vector<int>> edge) {
    int answer = 0, max = 0;
    queue<int> q;
    bool visited[20000] = { false, };//bfs는 방문을 체크하는 배열을 만들어줘야 함
    bool check[20001][20001] = { false, };//그래프의 연결관계 파악하기 위한 graph 배열
    int dist[20000] = { 0, };//depth를 나타내는 배열

    for (int i = 0; i < edge.size(); i++)//for문으로 check배열에 그래프를 이어준다. 
    {
        check[edge[i][0]][edge[i][1]] = true;//check[3][6]=1
        check[edge[i][1]][edge[i][0]] = true;//check[6][3]=1,그래프 선이 양방향이므로 양방향 모두 처리해줌
    }

    q.push(1);//1번 노드 push. 1번 노드를 0으로 표시하지 않고, 숫자 그대로 1로 사용하도록 코드 짬. 다른 노드들도 마찮가지임
    visited[1] = true;//1번 노드 방문표시

    while (q.empty() == 0)
    {
        int node = q.front();//node에 1 대입
        q.pop();

        for (int i = 2; i <= n; i++)//n개의 노드라서, i<=n
        {
            if (check[node][i] == true && visited[i] == false)
            {//1번 노드와 연결되있고&&방문 하지 않은 노드라면
                q.push(i);
                visited[i] = true;
                dist[i] = dist[node] + 1;//dist[2]=1, dist[3]=1
                                         //dist[4]=2, dist[5]=2
                                         //dist[6]=2
                if (dist[i] > max)
                    max = dist[i];//max 갱신
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