#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e6 + 10;
int a[N], tmp[N];
ll merge_sort(int q[], int l, int r)
{
	if(l >= r) return 0;
	
	int mid = l + r >> 1;
	
	ll ans = merge_sort(q, l, mid) + merge_sort(q, mid + 1, r);
	
	int k = 0, i = l, j = mid + 1;
	while(i <= mid && j <= r)
	{
		if(q[i] <= q[j]) tmp[k ++ ] = q[i ++ ];
		else
		{
			tmp[k ++ ] = q[j ++ ];
			ans += mid - i + 1;
		}
	}
	
	while(i <= mid) tmp[k ++ ] = q[i ++ ];
	while(j <= r) tmp[k ++ ] = q[j ++ ];
	
	for(i = l, j = 0; i <= r; i ++, j ++ ) q[i] = tmp[j];
	
	return ans;
}
int main()
{
	int n; scanf("%d", &n);
	for(int i = 0; i < n; i ++ ) scanf("%d", &a[i]);
	
	cout<<merge_sort(a, 0, n-1);
	
	return 0;
}
