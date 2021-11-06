#include <iostream>
using namespace std;
const int maxn = 5e5+5;
int q[maxn];
int main()
{
    int n;
    cin>>n;
    for(int i=0;i<n;i++) cin>>q[i];
    int l=0, r=n-1, cnt=0, last=-1;         // last用于记录上一次弹出的数据，初始为无穷小
    while(l<=r)
    {
        if(q[l]<last&&q[r]<last) break;
        ++cnt;
        if(q[l]>last&&q[r]>last)            // 若两边都能弹出，弹出数值较小的一边
        {
            if(q[l]<q[r]) last=q[l++];
            else last=q[r--];
        }
        else if(q[l]>last) last=q[l++];     // 只有左边能弹出
        else last=q[r--];                   // 只有右边能弹出
    }
    cout<<cnt<<endl;
    return 0;
}