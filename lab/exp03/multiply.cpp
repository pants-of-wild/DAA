#include <bits/stdc++.h>
using namespace std;

const int size = 1500;
int num;           
int p[size];       
int m[size][size]; 
void matrixchain()
{
    int i, r, j, k, q;
    //��������������ʼ�������Ӿ������ĳ���(r��ʾ�������ĳ���)
    for (r = 2; r <= num; r++)
    {
        //�����������ѡȡ����ߵľ���
        for (i = 1; i <= num - r + 1; i++) // iֵΪ��˵�λ�ã�ȡֵ���ܴ���num-r+1
        {
            j = i + r - 1; // jΪ�Ҷ˵�λ��
            m[i][j] = m[i + 1][j] + p[i - 1] * p[i] * p[j];

            for (k = i + 1; k < j; k++) 
            {
                q = m[i][k] + m[k + 1][j] + p[i - 1] * p[k] * p[j]; //���㻮�ֵĴ���
                if (q < m[i][j])
                {
                    m[i][j] = q; //�����ŵ�ֵq������m[i][j]��
                }
            }
        }
    }
    cout << m[1][num] << endl;
}

int main()
{
    while (scanf("%d", &num) != EOF)
    {
        for (int i = 0; i <= num; i++)
        {
            cin >> p[i];
        }
        matrixchain();
    }
    return 0;
}


