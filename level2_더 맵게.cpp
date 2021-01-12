/*heap 알고리즘: 우선순위 큐(priority_queue<int, vector<int>, greater<int>> PQ;) 자료구조 사용하는 알고리즘. 
우선순의 큐는 들어간 순서에 상관없이(일반적인 큐는 FIFO) 우선순위가 높은 데이터가 먼저 나옴(pop/top할 때). 
cf)우선순위 큐는 보통 내림차순/오름차순 우선순위 설정할 때 사용함. priority_queue<int, vector<int>, greater<int>> PQ; 하면
오름차순으로(작은것부터) pop/top 됨. greater대신 less쓰면 내림차순으로(큰 것부터) pop/top 됨.
cf)greater,less가 아니라, 직접 클래스 만들어서, 우선순위 기준 만들기도 가능함
cf)정렬은, push한 순서대로 정렬됨(스택,큐,우선순위 큐 모두)
cf)우선순위 큐는, sort를 이용한 내림차순/오름차순 정렬 or 정렬 기준을 둬서 정렬한 것보다 효율성이 좋아서 사용함
*/
#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(vector<int> scoville, int K) {
    priority_queue<int, vector<int>, greater<int>> PQ;//우선순위 큐 선언
    int answer = 0;
    for (int i = 0; i < scoville.size(); i++) {
        PQ.push(scoville[i]);
    }
    int first, second;
    while (PQ.top() < K) {//가장 작은 원소<K를 만족한다면
        if (PQ.size() <= 1) {
            return -1;//모든 음식의 스코빌 지수를 K이상으로 만들 수 없는 경우에는 -1을 return
        }
        first = PQ.top();
        PQ.pop();//큐에서 제거
        second = PQ.top();
        PQ.pop();//큐에서 제거
        first = first + second * 2;
        PQ.push(first);//정렬대신 우선순위 큐를 이용하면, push 후에 다시 정렬하지 않아도되서, 효율성이 좋음
        answer++;
    }
    return answer;
}