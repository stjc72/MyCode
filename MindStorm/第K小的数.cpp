#include<bits/stdc++.h>
using namespace std;
const int  N = 100010;
int a[N];
int quick_choose(int l, int r, int k)
{
	if(l >= r) return a[l];
	
	int x = a[l + r >> 1];
	int i= l - 1, j = r + 1;
	while(i < j)
	{
		do i ++ ; while(a[i] < x);
		do j -- ; while(a[j] > x);
		if(i < j) swap(a[i], a[j]);
	}
	int sl = j - l + 1;
	if(k <= sl) return quick_choose(l, j, k);
	else return quick_choose(j + 1, r, k - sl);
}
int main()
{
	int n,k;
	scanf("%d%d", &n, &k);
	for(int i = 0; i < n; i ++ ) scanf("%d", a + i);
	cout<<quick_choose(0, n - 1, k);
	return 0;
}
