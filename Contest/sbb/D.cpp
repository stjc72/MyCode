#include<bits/stdc++.h>
#define N 10005
using namespace std;
int n,m,k,x[N],y[N],low[N],high[N],f[N][2005];
bool flag[N];
int main(){
    scanf("%d%d%d",&n,&m,&k);
    for (int i=1;i<=n;i++) scanf("%d%d",&x[i],&y[i]);
    for (int i=1;i<=n;i++){
        high[i]=m;
        low[i]=1;
    }
    //用high和low表示最低能和最高能通过的地方.
    //开始什么地方都是能通过的,所以high初始为m,low初始为1.
    for (int i=1;i<=k;i++){
        int xx,yy,zz;scanf("%d%d%d",&xx,&yy,&zz);
        flag[xx]=1;
        low[xx]=yy+1;
        high[xx]=zz-1;
        //注意这里yy和zz要分别减一和加一.
    }
    memset(f,0x3f3f3f,sizeof(f));
    for (int i=1;i<=m;i++) f[0][i]=0;
    for (int i=1;i<=n;i++){
        for (int j=x[i]+1;j<=x[i]+m;j++) 
            f[i][j]=min(f[i-1][j-x[i]]+1,f[i][j-x[i]]+1);
        //上升
        for (int j=m+1;j<=x[i]+m;j++)
            f[i][m]=min(f[i][m],f[i][j]);
        //飞出了天花板的特殊情况
        for (int j=1;j<=m-y[i];j++)
            f[i][j]=min(f[i][j],f[i-1][j+y[i]]);
        //下降
        for (int j=1;j<low[i];j++)
            f[i][j]=0x3f3f3f;
        for (int j=high[i]+1;j<=m;j++)
            f[i][j]=0x3f3f3f;
        //处理无法通过的地方
    }
    int ans=0x3f3f3f;
    for (int i=1;i<=m;i++) ans=min(ans,f[n][i]);
    if (ans<0x3f3f3f){
        printf("1\n%d\n",ans);
        return 0;
    }
    int i,j;
    for (i=n;i>=1;i--){
        for (j=1;j<=m;j++)
            if (f[i][j]<0x3f3f3f) break;
        if (j<=m) break;
    }
    ans=0;
    for (j=1;j<=i;j++)
        if (flag[j]) ans++;
    printf("0\n%d\n",ans);
    return 0;
}
