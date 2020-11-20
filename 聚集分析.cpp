#include <iostream>
using namespace std;

const int N = 11;
int s[N+2]= {-1,1,3,0,5,3,5,6,8,8,2,12,65535};
int f[N+2]= {-1,4,5,6,7,8,9,10,11,12,13,14,65535};

//trace[i][j]����������S(i,j)ÿ������ʱ�Ļ���
int trace[N+2][N+2];

//dp[i][j]��ʾ������S(i,j)�������ݻ��
int dp[N+2][N+2];

/*S(i,j)={ak,fi<=sk<fk<=sj}��ʾ�ڻai����֮����aj��ʼ֮ǰ�Ļ��������������ռ�ɱ�ʾΪS(0,n+1),
*������ӻa0��an+1��s0=f0=0,sn+1=fn+1=2^32-1
*����dp[i][j]�ĺ���,����S(i,j)�в������κεĻ����(������S(i,j)����Ļ������)����dp[i][j]=0��
*���򣬼���akʱS(i,j)�д��ڵ�һ�����ݻ,��
*ô�����������S(i,j)�������ӽṹ:S(i,k)��S(k,j).
*�����������������Զ�������ĵݹ��ṹ:
*dp[i][j]=0,���S(i,j) =NULL
*dp[i][j]=max{dp[i][k]+dp[k][j]+1},i<k<j
*/
void dp_solve()
{
    int i =0;
    int j = 0;
    int l = 0;
    int k = 0;
    for(i=1; i<=N+1; i++)
        for(j=1; j<=N+1; j++)
            if(i==j)
                dp[i][j]=1;
    dp[0][0] = dp[N+1][N+1] = 0;
    for(l=1; l<N+2; l++)
        for(i=0; i+l<N+2; i++)
        {
            j=i+l;
            if(j<N+2)
            {
                dp[i][j] = 0;
                trace[i][j] = 0;
                for(k=i+1; k<j; k++)
                {
                    if(f[i]<=s[k] && f[k]<=s[j])//Ѱ����dp[i][k]+dp[k][j]����ֵ
                    {
                        if(dp[i][k] + dp[k][j]+1 > dp[i][j])
                        {
                            dp[i][j] = dp[i][k]+dp[k][j] +1;
                            trace[i][j] = k;
                        }
                    }
                }
            }
        }
}
void print(int i,int j)
{
    int k =0;
    if(trace[i][j]==0)
        return;
    k = trace[i][j];
    cout << k << "  ";
    print(i,k);
    print(k,j);
}

int main()
{
    dp_solve();
    print(0,N+1);
    cout<<endl;
    int i,j;
    cout<<"dp matrix:"<<endl;
    for(i=0; i<=N+1; i++)
    {
        for(j=0; j<=N+1; j++)
            cout<<dp[i][j]<<" ";
        cout<<endl;
    }
    cout<<"trace matrix:"<<endl;
    for(i=0; i<=N+1; i++)
    {
        for(j=0; j<=N+1; j++)
            cout<<trace[i][j]<<" ";
        cout<<endl;
    }
    return 0;
}
