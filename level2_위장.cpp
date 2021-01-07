/*�ؽ� �˰���: �ؽ� ���̺��� key�� value�� ������ ���̺���.
key(input)�� �̿��� value(output)�� �˾Ƴ�.
map<string, int> m; ���� key�� string, value�� int��*/
#include <string>
#include <vector>
#include <map>

using namespace std;

int solution(vector<vector<string>> clothes) {
    int answer = 1;
    map<string, int> m; //key�� �ǻ��� ����(�ڷ��� string), value�� �ǻ��� ����(�ڷ��� int)

    for (int i = 0; i < clothes.size(); i++) { //clothes.size()�� ���� ���� ��ȯ��
        m[clothes[i][1]]++;	 //m[key]+=value;��� hash function����, �ؽ����̺� �ʱ�ȭ. input�� key�� hash function�� �̿���, output�� value�� ����	
    }

    map<string, int>::iterator it;
    for (it = m.begin(); it != m.end(); it++) { //m.begin()�� �ּҰ� ��ȯ��.
        //it++�ϸ�, ���� ���ҷ� �Ѿ
        //�ؽ����̺����� 1���� key�� value�� �Ѱ��� ���� ��޵Ǿ�, it++�ϸ� ���� key�� value ������ �Ѿ
        
        answer *= (it->second) + 1; //it->second��, value�� �ǻ��� ����
    }
    return answer - 1; //0�� �����ϴ� ��� ����
}