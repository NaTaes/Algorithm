#include<iostream>

using namespace std;
int A[501];
int D[501];

int main()
{
	int T, max=0;
	cin >> T;

	for(int i=0; i<T; i++)
	{
		int n, k;
		cin >> n >> k;
		A[n] = k; //A�� ��ȣ�� index, B�� ��ȣ�� �迭�� ��
	}
	//���� �� �����ϴ� �κ� ������ �����.
	for(int i=1; i<=500; i++)
	{
		if(A[i]==0) continue; //���� ���ٸ� continue
        D[i] = 1;
        int temp = 1;
        for(int j=1; j<i; j++) //���� �� �����ϴ� �κм���(11053��) ���� ����.
        {
			if(A[i] > A[j] && temp < D[i]+D[j])
			{
				temp = D[i] + D[j];
				max = max < temp ? temp : max;
			}
		}
        D[i] = temp;
    }

    cout << T-max << endl; //���� �� ���̹Ƿ� �� �ټ� - ���� �� �κм����� ����
}