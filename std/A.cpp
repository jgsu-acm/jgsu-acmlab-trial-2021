#include <iostream>
using namespace std;
const int maxn = 2e6+5;
bool vis[maxn];
int cnt, prime[maxn];
int kcnt[maxn], exkcnt[maxn];
int kcntmax[maxn], exkcntmax[maxn];
int main()
{
    // 首先进行线性筛
    for(int i=2;i<maxn;i++)
    {
        if(!vis[i])
        {
            prime[cnt++]=i;
            kcnt[i]=exkcnt[i]=1;
        }
        for(int j=0;j<cnt&&i*prime[j]<maxn;j++)
        {
            vis[i*prime[j]]=true;   // 这个数不是质数
            kcnt[i*prime[j]]=kcnt[i]+1; // 显然i*prime[j]这个数因为多乘上了一个质数所以可以由kcnt[i]+1个质数相乘来得到
            if(i%prime[j]==0) break;    // 找到了i的最小素因子
            // 当i和prime[j]互质时继续执行
            if(exkcnt[i]) exkcnt[i*prime[j]]=exkcnt[i]+1;   // 只有当i没有平方因子的时候才是完全k素数
    }
    for(int i=2;i<maxn;i++) // 处理出前i个数中最大由多少个质数相乘得到
    {
        kcntmax[i]=max(kcntmax[i-1], kcnt[i]);
        exkcntmax[i]=max(exkcntmax[i-1], exkcnt[i]);
    }
    int t;
    cin>>t;
    while(t--)
    {
        int n,k;
        cin>>n>>k;
        if(k==0)    // 能由0个质数乘出来的数字只有1
        {
            cout<<"1 1"<<endl<<"1 1"<<endl;
            continue;
        }
        int ktot=0, kans=0, exktot=0, exkans=0; // 注意异或和处置为0因为0异或任何数结果等于这个数
        if(k<=kcntmax[n])   // 质数因子个数最多的数字都不能由k个质数拼出来的话直接byebye。以下同理
        {
            for(int i=1;i<=n;i++)
                if(kcnt[i]==k)
                    kans ^= i, ktot++;
        }
        if(k<=exkcntmax[n])
        {
            for(int i=1;i<=n;i++)
                if(exkcnt[i]==k)
                    exkans ^= i, exktot++;
        }
        cout<<ktot;
        if(ktot) cout<<' '<<kans; cout<<endl;
        cout<<exktot;
        if(exktot) cout<<' '<<exkans; cout<<endl;
    }
    return 0;
}