#include <iostream>
#include <queue>
#include <tuple>
using namespace std;
const int maxn = 15;
typedef tuple<int,int,int> tp3;
bool vis[maxn][maxn];
int main()
{
    int x1,y1,x2,y2;
    cin>>x1>>y1>>x2>>y2;
    static queue<tp3> que;
    que.emplace(x1,y1,0);
    while(!que.empty())
    {
        auto [p,q,c] = que.front();
        que.pop();
        if(p==x2&&q==y2)
        {
            cout<<c<<endl;
            break;
        }
        if(p<1||p>10||q<1||q>9) continue;
        if(vis[p][q]) continue;
        vis[p][q] = true;
        que.emplace(p-2,q-1,c+1);
        que.emplace(p-2,q+1,c+1);
        que.emplace(p+2,q-1,c+1);
        que.emplace(p+2,q+1,c+1);
        que.emplace(p-1,q-2,c+1);
        que.emplace(p-1,q+2,c+1);
        que.emplace(p+1,q-2,c+1);
        que.emplace(p+1,q+2,c+1);
    }
    return 0;
}