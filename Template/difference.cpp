#include <bits/stdc++.h>
using namespace std;
const int N = 100010;
int a[N]={0}, d[N]={0};
int main()
{
	int n, m;
	scanf("%d", &n);scanf("%d", &m);
	for(int i = 1; i <= n; i ++ ) scanf("%d", a + i);
	for(int i = 1; i <= n; i ++ ) d[i] = a[i] - a[i - 1];
	
	while(m --)
	{
		int l, r, c;
		scanf("%d%d%d", &l, &r, &c);
		d[l] += c; d[r + 1] -= c;
	}
	
	int ans = 0;
	for(int i = 1; i <= n; i ++ ) 
	{
		ans += d[i];
		printf("%d ", ans);
	}
	return 0;
}
