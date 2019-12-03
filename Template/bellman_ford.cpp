#include<bits/stdc++.h>
using namespace std;
const int M = 10010, N = 510;

struct edge{
	int a, b, w;
}e[M];

int dist[N], last[N];
int n, m, k;

void bellman_ford()
{
	memset(dist, 0x3f, sizeof dist);
	dist[1] = 0;
	
	for(int i = 0; i < k; i ++ )//k = n - 1ʱ������Դ���·����kָ��ྭ��k���ߵ����· 
	{
		memcpy(last, dist, sizeof dist);//last�����ֹ�����������2��3�����·��2�����·���� 
		
		for(int j = 0; j < m; j ++ )
		{
			edge t = e[j];
			dist[t.b] = min(dist[t.b], last[t.a] + t.w);//last��dist����ͨ���· 
		}
	}
	
}
int main()
{
	scanf("%d %d %d", &n, &m, &k);
	for(int i = 0; i < m; i ++ )
	{
		int x, y, z; scanf("%d %d %d", &x, &y, &z);
		e[i].a = x; e[i].b = y; e[i].w = z;
	}
	bellman_ford();
	
	if(dist[n] > 0x3f3f3f3f / 2) puts("impossible");
	else printf("%d\n", dist[n]);
	
	return 0;
}
