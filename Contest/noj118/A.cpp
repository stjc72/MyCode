#include<iostream>
#include<cstdio>
#include<cstdlib>
using namespace std;
int main()
{
	string a;
	int l, o = 0, n = 0, e = 0, z = 0, r = 0;
	scanf("%d", &l);
	cin >> a;
	for(int i = 0; i < l; i ++ )
	{
		if(a[i] == 'o') o++;
		if(a[i] == 'n') n++;
		if(a[i] == 'e') e++;
		if(a[i] == 'z') z++;
		if(a[i] == 'r') r++;
	}
//	printf("%d %d %d %d %d\n", o, n, e, z, r);
	int one = min(min(o, n), e);
	o -= one; n -= one; e -= one;
	int zero = min(min(z, e), min(r, o));
//	printf("%d %d %d %d %d\n", o, n, e, z, r);
//	cout<<one<<endl<<zero;
	while(one)
	{
		one -- ;
		printf("1 ");
	}
	while(zero)
	{
		zero -- ;
		printf("0 ");
	}
	return 0;
 } 
