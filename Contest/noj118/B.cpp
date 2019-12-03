#include<bits/stdc++.h>
using namespace std;

int main()
{
	int T; scanf("%d", &T);
	while(T -- )
	{
		int n; scanf("%d", &n);
		char op[4]; scanf("%s", &op);
		if(op[2] == 'F')
		{
			queue<int> q;
			for(int i = 1; i <= n; i ++ )
			{
				scanf("%s", &op);
				if(op[0] == 'I') 
				{
					int t; scanf("%d", &t);
					q.push(t);
				}
				else
				{
					if(q.empty()) printf("None\n");
					else
					{
						printf("%d\n", q.front());
						q.pop();
					}
				}
			}
		}
		
		else
		{
			stack<int> s;
			for(int i = 1; i <= n; i ++ )
			{
				scanf("%s", &op);
				if(op[0] == 'I')
				{
					int t; scanf("%d", &t);
					s.push(t);
				}
				else
				{
					if(s.empty()) printf("None\n");
					else
					{
						printf("%d\n", s.top());
						s.pop();
					}
				}
			}
		}
		
	}
	
	return 0;
}
