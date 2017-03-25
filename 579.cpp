#include <cstdio>
#include <cstdlib>

int hour, minute;
double hDegree, mDegree, degree;


int main()
{
	while (scanf("%d:%d", &hour, &minute) )
	{
		if (hour==0 && minute==0)
			break;
		
		hDegree = hour*30+minute*0.5;
		mDegree = minute*6;
		
		if (hDegree>mDegree)
			degree = hDegree - mDegree;
		else
			degree = mDegree - hDegree;
		
		if (degree >= 180)
			degree = 360 - degree;
		
		printf("%.3f\n", degree);
	}
	return 0;
}
