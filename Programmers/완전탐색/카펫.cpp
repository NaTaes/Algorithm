// https://programmers.co.kr/learn/courses/30/lessons/42842

// 문제가 개편되었습니다. 이로 인해 함수 구성이나 테스트케이스가 변경되어, 과거의 코드는 동작하지 않을 수 있습니다.
// 새로운 함수 구성을 적용하려면 [코드 초기화] 버튼을 누르세요. 단, [코드 초기화] 버튼을 누르면 작성 중인 코드는 사라집니다.
#include <string>
#include <vector>

using namespace std;

vector<int> solution(int brown, int red) {
    vector<int> answer;

    int limit = red;

    for(int i=1; i <= limit; i++)
    {
        if(red % i != 0)
            continue;

        limit = red / i;

        if((limit+2)*2 + (i*2) == brown)
        {
            answer.push_back(limit+2);
            answer.push_back(i+2);
            break;
        }
    }

    return answer;
}