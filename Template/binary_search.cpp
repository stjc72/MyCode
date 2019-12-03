#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n, q; scanf("%d%d", &n, &q);
	int a[10000 + 7];
	for(int i = 0; i < n; i ++ ) scanf("%d", a + i);
	
	while(q -- )
	{
		int x; scanf("%d", &x);
		
		int l = 0, r = n - 1, mid = l + r >> 1;
		while(l < r)//l = r时退出循环 
		{ 
		    mid = l + r >> 1;//第一类二分, r = mid
		    
			if(a[mid] < x) l = mid + 1;
			else r = mid;
		}
		if(a[l] != x) printf("-1 -1\n");
		else
		{
			printf("%d ", mid);
			
			l = mid, r = n - 1, mid = l + r >> 1;
			while(l < r)
			{
				mid = l + r + 1 >> 1;//第二类二分, l = mid 
				if(a[mid] > x) r = mid - 1;
				else l = mid;
			}
			
			printf("%d\n", mid);
		}
	}
	return 0;
}
