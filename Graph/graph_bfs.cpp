#include<bits/stdc++.h>
using namespace std;
const int N = 100010, M = N + N;
int n, m;
int h[N], e[M], ne[M], ide = 0;
int d[N];
bool vis[N];

int bfs()
{
	memset(d, -1, sizeof d);
	
	queue<int> q;
	q.push(1);
	d[1] = 0;
	
	while(q.size())
	{
		int t = q.front();
		q.pop();
		
		for(int i = h[t]; i != -1; i = ne[i])
		{
			int j = e[i];
			if(d[j] == -1)
			{
				d[j] = d[t] + 1;
				q.push(j);
			}
		}
	}
	return d[n];
}

void add(int x, int y)
{
	e[ide] = y; ne[ide] = h[x]; h[x] = ide ++;
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
	}
	
	cout<<bfs()<<endl;
	
	return 0;
} 
