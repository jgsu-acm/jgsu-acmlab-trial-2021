#include <iostream>
#include <cstring>
using namespace std;
int mj[5][15], cpy[5][15];  // mj一维从0到3分别代表万饼条字牌，二维代表点数
bool check2()
{
    memcpy(cpy, mj, sizeof(mj));            // 此函数用途为往cpy里复制一个mj，防止误伤到mj数组
    for(int i=1;i<=9;i++)
    {
        for(int j=0;j<4;j++) cpy[j][i]%=3;  // 删掉所有的刻子
        if(cpy[3][i]) return false;         // 因为字牌不能成顺子，所以若还剩下了字牌则必然不能和牌
        // 因为雀头和刻子都没了所以以下只需要判断顺子
        for(int j=0;j<3;j++)                // 遍历顺子的最小牌
        {
            if(cpy[j][i])
            {
                if(i>7) return false;       // 如果还有多余的8,9则必然不能成顺子
                // 删除顺子
                if(cpy[j][i+1]<cpy[j][i]||cpy[j][i+2]<cpy[j][i])    // 如果不能成顺子
                    return false;
                cpy[j][i+1] -= cpy[j][i];
                cpy[j][i+2] -= cpy[j][i];
                // 因为cpy[j][i]以后不会被访问到，所以cpy[j][i]这个位置可以不减
            }
        }
    }
    return true;
}
bool check1()
{
    bool flag;
    for(int i=1;i<=9;i++)
    {
        for(int j=0;j<4;j++)
        {
            if(mj[j][i]>1)          // 枚举雀头
            {
                mj[j][i]-=2;        // 删掉雀头
                flag = check2();    // 判断
                mj[j][i]+=2;        // 再把雀头加回来
                if(flag) return true;
            }
        }
    }
    return false;
}
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        memset(mj, 0, sizeof(mj));
        for(int i=0;i<14;i++)
        {
            string s;
            cin>>s;
            int x = s[0]-'0';
            switch(s[1])
            {
            case 'w': mj[0][x]++; break;
            case 'b': mj[1][x]++; break;
            case 't': mj[2][x]++; break;
            case 'z': mj[3][x]++; break;
            }
        }
        cout << (check1() ? "Tsumo!" : "Waiting for Tsumo!") << endl;
    }
    return 0;
}