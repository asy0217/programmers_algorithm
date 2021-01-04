#include <string>
#include <vector>

using namespace std;

int num;//타겟넘버를 만드는 방법의 수를 저장할 변수 선언

void DFS(vector<int> numbers, int target, int n, int sum) { //DFS함수 정의
    if (n == numbers.size()) { //배열의 모든 원소를 사용했을 때, n==numbers.size()는 true이다
        if (sum == target) { //타겟넘버(target)와, sum이 같다면
            num++; 
        }
        return;
    }
    //배열의 모든 원소를 사용하지 않았을 때
    DFS(numbers, target, n + 1, sum + numbers[n]); //재귀함수 호출:sum+numbers[n]으로 실행됨
    DFS(numbers, target, n + 1, sum - numbers[n]);//재귀함수 호출:sum-numbers[n]으로 실행됨
}

int solution(vector<int> numbers, int target) {
    int answer = 0;

    DFS(numbers, target, 1, numbers[0]);
    DFS(numbers, target, 1, -numbers[0]);

    answer = num;

    return answer;
}