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
		A[n] = k; //A�� ��ȣ�� index, B�� ��ȣ�� �迭�� ��
	}

	for(T=1; A[T]==0; T++); //���� 0�� �ƴ� ���� ���� index�� ����

	vec.push_back(A[T]); //�ش� ���� ���Ϳ� push

	for(int i=T+1; i<=500; i++)
	{
		if(A[i]==0) continue; //���� 0�̸� continue
		if(vec[vec.size()-1] > A[i]) //������ ������ ������ �۴ٸ� ����
		{
			for(int j=0; j<vec.size(); j++) //���� search
			{
				if(vec[j] > A[i]) //���;��� ������ ���� ��ġ�� ã�´�.
				{
					vec[j] = A[i]; //���;��� �� �߿��� �ڽź��� ū ���� ��ġ�� ����.
					count++; //�����ߴٴ� ���� �� ���� ������ �ʴ� �ٴ� ������ count++�� ���ش�.
					break; //���;��� ���� ���� �Ǿ������Ƿ� ��ġ�� ���� ������ search�� �׸��д�.
				}
			}
		}
		else //������ ������ ������ ũ�ٸ�, ���;��� ��� ������ ũ�Ƿ� ������ �� �ڿ� push ���ش�.
			vec.push_back(A[i]);
	}
	cout << count << endl;
	//cout << T-vec.size() << endl; �� �����ϴ�. ��, T ���� ���� ���Ѿ��Ѵ�.
}