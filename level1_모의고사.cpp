#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> answers) {
    vector<int> answer;
    int score[3] = { 0, }; //1��, 2��, 3���� score�� ��� 0���� �ʱ�ȭ
    int max_score = 0;
    int test1[5] = { 1, 2, 3, 4, 5 };//1��
    int test2[8] = { 2, 1, 2, 3, 2, 4, 2, 5 };//2��
    int test3[10] = { 3, 3, 1, 1, 2, 2, 4, 4, 5, 5 };//3��
    for (int i = 0; i < answers.size(); i++) {
        if (answers[i] == test1[i % 5]) score[0] += 1;//answers�� ���� �ϳ��ϳ� ������ Ȯ���ϰ�, ���ٸ� score ������ 1 �ø�
        //%5���� 5��, 1���� ������ ������ 5���� �ǹ���
        if (answers[i] == test2[i % 8]) score[1] += 1;
        if (answers[i] == test3[i % 10]) score[2] += 1;
    }
    max_score = max(max(score[0], score[1]), score[2]);
    for (int i = 0; i < 3; i++) {
        if (score[i] == max_score)
            answer.push_back(i + 1);
    }
    return answer;
}