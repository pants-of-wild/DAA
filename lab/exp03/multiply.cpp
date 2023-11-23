#include <bits/stdc++.h>
using namespace std;

const int size = 1500;
int num;           
int p[size];       
int m[size][size]; 
void matrixchain()
{
    int i, r, j, k, q;
    //从两个矩阵链开始，逐次添加矩阵链的长度(r表示矩阵链的长度)
    for (r = 2; r <= num; r++)
    {
        //解决方案优先选取先左边的矩阵
        for (i = 1; i <= num - r + 1; i++) // i值为左端点位置，取值不能大于num-r+1
        {
            j = i + r - 1; // j为右端点位置
            m[i][j] = m[i + 1][j] + p[i - 1] * p[i] * p[j];

            for (k = i + 1; k < j; k++) 
            {
                q = m[i][k] + m[k + 1][j] + p[i - 1] * p[k] * p[j]; //计算划分的代价
                if (q < m[i][j])
                {
                    m[i][j] = q; //将最优的值q保存在m[i][j]中
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


