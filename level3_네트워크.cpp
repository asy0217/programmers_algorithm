/*1.bfs는 방문했거나, 방문하지 않은 노드의 개수를 세는 문제에 사용되는 알고리즘이다. bfs알고리즘을 푸는 과정에서 queue를 사용한다.
2.dfs는 재귀를 사용한다(bfs는 재귀를 사용하지 않는다).
3.vector는 stack 자료구조로 LIFO이고, queue는 FIFO이다.*/
#include <string>
#include <vector>
#include <queue>

using namespace std;
const int MAX = 200; //컴퓨터 개수(노드의 개수) n의 최대값
bool check[MAX] = { 0, };//각 노드 방문했는지 체크함. 방문했으면1, 방문안했으면 0.
void bfs(int start, int n, vector<vector<int>> computers) {
    queue<int> q;
    check[start] = true;//방문했으므로, 1로 바꿔줌
    for (int i = 0; i < n; i++) {
        int connected = computers[start][i]; //다른 노드와의 연결 여부 파악
        if (connected == 1 && check[i] == 0) {//연결되었는데, 아직 방문하지 않은 노드라면
            check[i] = true;//check하는 노드와 연결된 노드 중 방문하지 않은 노드는 방문체크 후 큐에 푸시
            q.push(i);
        }
    }
    while (q.empty() == 0) { //queue가 안 비었으면
        int x = q.front();
        q.pop();//선입선출
        for (int i = 0; i < n; i++) {
            int connected = computers[x][i];
            if (connected == 1 && check[i] == 0) {
                check[i] = true;//check하는 노드와 연결된 노드 중 방문하지 않은 노드는 방문체크 후 큐에 푸시
                q.push(i);
            }
        }
    }
}
int solution(int n, vector<vector<int>> computers) {
    int answer = 0;
    for (int i = 0; i < n; i++) {
        if (check[i] == 0) { //첫번째 노드는 무조건 만족
//i=0에서, bfs함수를 통해 첫번째 노드와 연결되있는 노드들을 모두 check[i]=1로 만듬->첫번째 노드와 연결 안된 노드가, bfs함수를 통해 연결되있는 노드들을 모두 check[i]=1로 만듬->...
            bfs(i, n, computers); //bfs를 통해 첫번째 노드와 연결된 네트워크들을 모두 check[i]=1로 만들어서, 방문한 것을 표시함
            answer += 1; //이전까지 순회 중 방문하지 않은 노드는 이전 네트워크에 포함되지 않기 때문에 새로운 네트워크의 등장으로 보고, answer+1
        }
    }
    return answer;
}