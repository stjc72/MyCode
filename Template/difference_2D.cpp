#include<bits/stdc++.h>
using namespace std;
const int N = 1010;
int a[N][N], d[N][N]; 
inline void diff(int x1, int y1, int x2, int y2, int c)
{
	d[x1][y1] += c;
	d[x2 + 1][y1] -= c;
	d[x1][y2 + 1] -= c;
	d[x2 + 1][y2 + 1] += c;
}
int main()
{
	int n, m, q;
	scanf("%d%d%d", &n, &m, &q);
	for(int i = 1; i <= n; i ++ )
	{
		for(int j = 1; j <= m; j ++ )
		{
			scanf("%d", &a[i][j]);
		}
	}
	
	for(int i = 1; i <= n; i ++ )
	{
		for(int j = 1; j<= m; j ++ )
		{
			diff(i, j, i, j, a[i][j]);
		}
	}
	
	while(q -- )
	{
		int x1, y1, x2, y2, c;
		scanf("%d %d %d %d %d", &x1, &y1, &x2, &y2, &c);
		diff(x1, y1, x2, y2, c);
	 } 
	 
	 for(int i = 1; i <= n; i ++ )
	 {
	 	for(int j = 1; j <= m; j ++ )
	 	{
	 		d[i][j] += d[i - 1][j] + d[i][j - 1] - d[i - 1][j - 1];
		 }
	 }
	 
	 for(int i = 1; i <= n; i ++)
	 {
	 	for(int j = 1; j <= m; j ++ )
	 	{
	 		if(j == m) printf("%d\n", d[i][j]);
	 		else printf("%d ", d[i][j]);
		 }
	  } 
	 return 0;
}
