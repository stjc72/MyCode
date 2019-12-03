#include <bits/stdc++.h>
using namespace std;
const int N = 100010;
int a[N]={0}, s[N]={0};
int main()
{
	int n, m;
	scanf("%d", &n);scanf("%d", &m);
	for(int i = 1; i <= n; i ++ ) scanf("%d", a + i);
	for(int i = 1; i <= n; i ++ ) s[i] = s[i - 1] + a[i];
	
	while(m --)
	{
		int l, r;
		scanf("%d%d", &l, &r);
		printf("%d\n", s[r] - s[l - 1]);
	}
	return 0;
}
