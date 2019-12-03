#include<bits/stdc++.h>
using namespace std;
const int N = 100010, M = N + N;
int n, m;
int h[N], e[M], ne[N], ide = 0;
int inde[N] = {0}, ans[N], cnt = 0;
void add(int x, int y)
{
	e[ide] = y, ne[ide] = h[x], h[x] = ide ++ ;
}
int main()
{
	scanf("%d %d", &n, &m);
	memset(h, -1, sizeof h);
	for(int i = 0; i < m; i ++ )
	{
		int a, b; 
		scanf("%d %d", &a, &b);
		add(a, b);
		inde[b] ++ ;
	}
//	for(int i = 1; i <= n; i ++ ) printf("%d--%d\n", i, inde[i]);
	queue<int> q;
	for(int i = 1; i <= n; i ++ )
	{
		if(inde[i] == 0) q.push(i); 
	}
	
	if(q.empty()) {printf("-1"); return 0; }
	
	while(!q.empty())
	{
		int t = q.front(); ans[cnt ++ ] = t; q.pop();
		
		for(int i = h[t]; i != -1; i = ne[i])
		{
			int j = e[i];
			inde[j] -- ;
			if(inde[j] == 0) q.push(j); 
		}
	}
//	for(int i = 1; i <= n; i ++ ) printf("%d--%d\n", i, inde[i]);
	if(cnt == n) for(int i = 0; i < n; i ++ ) printf("%d ", ans[i]);
	
	else printf("-1");
	
	return 0;
}
