#include <iostream>
#include <cstring>
using namespace std;
int ans[15][15];
int x2,y2;  // 终点
void dfs(int x,int y,int cnt)   // x,y：当前走到了哪个点；cnt：当前已走了几步
{
    if(cnt>=ans[x][y]) return;   // 若当前花费的步数已经大于等于之前走到此处花费的步数，则不用继续走了
    ans[x][y]=min(ans[x][y],cnt);   // 更新答案
    if(x==x2&&y==y2) return;    // 若走到终点则不用走了
    // 分别尝试往八个方向走，并且使花费的步数+1。注意用if判断防止走到棋盘外
    if(x-2>=1&&y-1>=1) dfs(x-2,y-1,cnt+1);
    if(x-2>=1&&y+1<=9) dfs(x-2,y+1,cnt+1);
    if(x-1>=1&&y-2>=1) dfs(x-1,y-2,cnt+1);
    if(x-1>=1&&y+2<=9) dfs(x-1,y+2,cnt+1);
    if(x+1<=10&&y-2>=1) dfs(x+1,y-2,cnt+1);
    if(x+1<=10&&y+2<=9) dfs(x+1,y+2,cnt+1);
    if(x+2<=10&&y-1>=1) dfs(x+2,y-1,cnt+1);
    if(x+2<=10&&y+1<=9) dfs(x+2,y+1,cnt+1);
}
int main()
{
    int x1,y1;
    cin>>x1>>y1>>x2>>y2;
    memset(ans, 0x3f, sizeof(ans));     // 要求最小值，ans数组设置为无穷大
    dfs(x1,y1,0);
    cout<<ans[x2][y2]<<endl;
    return 0;
}