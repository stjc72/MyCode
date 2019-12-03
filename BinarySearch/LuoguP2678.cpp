#include<bits/stdc++.h>
using namespace std;
const int N = 50010;
typedef long long ll;

ll d[N]={0};
ll L, n, m;

bool check(int x)
{
	int cnt = 0;
	int i = 0;
	int  now = 0;
	while(i < n + 1)
	{
		i++;
		if(d[i] - d[now] < x) cnt++;
		else now = i;
	}
	return cnt <= m;
}
int main()
{
	scanf("%lld %lld %lld",&L, &n, &m);
	for(int i = 1; i <= n; i ++ ) scanf("%lld", d + i);
	d[n + 1] = L;//第n块石头不是终点，第n+1块才是 
	
	int l = 1, r = L, mid; 
	while(l < r)
	{
		mid = l + r + 1 >> 1;
		if(check(mid)) l = mid;
		else r = mid - 1;
	}
	printf("%d", l);
	
	return 0;
}
