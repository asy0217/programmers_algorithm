/*해시 알고리즘: 해시 테이블은 key와 value로 구성된 테이블임.
key(input)를 이용해 value(output)를 알아냄.
map<string, int> m; 에서 key는 string, value는 int임*/
#include <string>
#include <vector>
#include <map>

using namespace std;

int solution(vector<vector<string>> clothes) {
    int answer = 1;
    map<string, int> m; //key는 의상의 종류(자료형 string), value는 의상의 갯수(자료형 int)

    for (int i = 0; i < clothes.size(); i++) { //clothes.size()는 행의 개수 반환함
        m[clothes[i][1]]++;	 //m[key]+=value;라는 hash function으로, 해시테이블 초기화. input인 key와 hash function을 이용해, output인 value값 도출	
    }

    map<string, int>::iterator it;
    for (it = m.begin(); it != m.end(); it++) { //m.begin()은 주소값 반환함.
        //it++하면, 다음 원소로 넘어감
        //해시테이블에서는 1쌍의 key와 value가 한개의 원소 취급되어, it++하면 다음 key와 value 쌍으로 넘어감
        
        answer *= (it->second) + 1; //it->second는, value인 의상의 갯수
    }
    return answer - 1; //0개 선택하는 경우 빼줌
}