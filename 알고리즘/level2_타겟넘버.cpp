#include <string>
#include <vector>

using namespace std;

int num;//Ÿ�ٳѹ��� ����� ����� ���� ������ ���� ����

void DFS(vector<int> numbers, int target, int n, int sum) { //DFS�Լ� ����
    if (n == numbers.size()) { //�迭�� ��� ���Ҹ� ������� ��, n==numbers.size()�� true�̴�
        if (sum == target) { //Ÿ�ٳѹ�(target)��, sum�� ���ٸ�
            num++; 
        }
        return;
    }
    //�迭�� ��� ���Ҹ� ������� �ʾ��� ��
    DFS(numbers, target, n + 1, sum + numbers[n]); //����Լ� ȣ��:sum+numbers[n]���� �����
    DFS(numbers, target, n + 1, sum - numbers[n]);//����Լ� ȣ��:sum-numbers[n]���� �����
}

int solution(vector<int> numbers, int target) {
    int answer = 0;

    DFS(numbers, target, 1, numbers[0]);
    DFS(numbers, target, 1, -numbers[0]);

    answer = num;

    return answer;
}