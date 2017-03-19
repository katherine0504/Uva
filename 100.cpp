#include <cstdio>
#include <cstdlib>

using namespace std;

void compute(int a, int b);

int main ()
{
	int a,b;
	char space;
	int pair = 0;
	int ans[10000][2];
	int i;
	
	while(scanf("%d", &a) != EOF )
	{
		scanf("%c%d",&space, &b );
		ans[pair][0] = a;
		ans[pair][1] = b;
		pair++;
	}
	
	for ( i=0; i<pair; i++ )
	{
		a = ans[i][0];
		b = ans[i][1];

		compute(a,b);
	}
	
	return 0;
}

void compute(int a, int b)
{
	int i;
	int n;
	int max, min; 
	int cycle = 0;
	int maxCycle = 0;
			
	if ( a>b )
	{
		max = a;
		min = b;
	}
	else
	{
		max = b;
		min = a;
	}
	
	for ( i=max; i>=min; i-- )
	{
		
		n = i;
		cycle = 0;
		
		while ( n!=1 ) 
		{
			if ( n%2 == 0 )
				n = n/2;
			else
				n = 3*n+1;
			cycle++;
		}
		cycle++; 
		if ( cycle>maxCycle )
			maxCycle = cycle;
	}
	
	printf("%d %d %d\n", a, b, maxCycle);
}


