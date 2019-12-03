#include<bits/stdc++.h>
using namespace std;
typedef pair<int, int> PII;

const int N = 100010, M = N + N;
int h[N], ne[M], e[M], w[M], ide = 0;
int n, m;
int dist[N];
bool vis[N];//已经是最短的 

void add(int a, int b, int c)
{
	e[ide] = b; w[ide] = c; ne[ide] = h[a]; h[a] = ide ++ ;
}

void dijkstra(int startver)
{
    memset(dist,0x3f,sizeof dist);
    
	dist[startver] = 0;
	
	priority_queue<PII, vector<PII>, greater<PII> > heap;
	heap.push({0, startver});//第一维距离，第二维点编号
	
	while(heap.size())
	{
		auto t = heap.top();
		heap.pop();
		
		int ver = t.second, distance = t.first;
		if(vis[ver]) continue;
		vis[ver] = true;
		
		for(int i = h[ver]; i != -1; i = ne[i])
		{
			int j = e[i];
			if(dist[j] > distance + w[i])
			{
				dist[j] = distance + w[i];
				heap.push({dist[j], j});			
			}		
		}	  	
	}
	
}

int main()
{
	scanf("%d %d", &n, &m);
	memset(h, -1, sizeof h);
	for(int i = 0; i < m; i ++ )
	{
		int x, y, z; scanf("%d %d %d", &x, &y, &z);
		add(x, y, z);
	}
	dijkstra(1);
	
	cout << (dist[n] = dist[n] == 0x3f3f3f3f ? -1 : dist[n]);
	
	return 0;
}
