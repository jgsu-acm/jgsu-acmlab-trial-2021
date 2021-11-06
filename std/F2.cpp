#include <iostream>
using namespace std;
int p[7];
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int A;
        cin>>A;
        for(int i=1;i<=4;i++) cin>>p[i];
        double mul = 1;
        int sum = 0;
        for(int i=1;i<=4;i++, mul *= 0.85)
            sum += (int)(A * mul * (1 - p[i] / 100.0));
        cout<<sum<<endl;
    }
    return 0;
}