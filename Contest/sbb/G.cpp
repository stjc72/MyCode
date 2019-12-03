#include<bits/stdc++.h>
using namespace std;
int main()
{
	int a[10], h, ans=0;
	for(int i = 0; i < 10; i ++ ) scanf("%d", a + i);
	scanf("%d", &h); h+= 30;
	for(int i = 0; i < 10; i ++ ) if(a[i] <= h) ans++;
	printf("%d", ans);
	return 0;
}
