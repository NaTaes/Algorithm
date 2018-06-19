#include<iostream>
#include<vector>
using namespace std;

vector<int> vec;
int A[501];

int main(void)
{
	int T, count = 0;
	cin >> T;

	while(T--)
	{
		int n, k;
		cin >> n >> k;
		A[n] = k; //A쪽 번호를 index, B쪽 번호를 배열의 값
	}

	for(T=1; A[T]==0; T++); //값이 0이 아닌 가장 작은 index를 추출

	vec.push_back(A[T]); //해당 값을 벡터에 push

	for(int i=T+1; i<=500; i++)
	{
		if(A[i]==0) continue; //값이 0이면 continue
		if(vec[vec.size()-1] > A[i]) //벡터의 마지막 값보다 작다면 실행
		{
			for(int j=0; j<vec.size(); j++) //벡터 search
			{
				if(vec[j] > A[i]) //벡터안의 수보다 작은 위치를 찾는다.
				{
					vec[j] = A[i]; //벡터안의 수 중에서 자신보다 큰 수의 위치에 들어간다.
					count++; //변경했다는 말은 그 값은 사용되지 않는 다는 것으로 count++를 해준다.
					break; //벡터안의 수는 정렬 되어있으므로 위치를 변경 했으면 search를 그만둔다.
				}
			}
		}
		else //벡터의 마지막 값보다 크다면, 벡터안의 모든 수보다 크므로 벡터의 맨 뒤에 push 해준다.
			vec.push_back(A[i]);
	}
	cout << count << endl;
	//cout << T-vec.size() << endl; 도 가능하다. 단, T 값을 유지 시켜야한다.
}