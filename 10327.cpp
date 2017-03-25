#include <cstdio>
#include <cstdlib>

using namespace std;

int num;
int arr[10000];
int i, j;
int counter, temp;

int main()
{
	while (scanf("%d", &num) != EOF)
    {
        counter = 0;
        for (i=0; i<num; i++)
            scanf("%d", &arr[i]);

        for (i=0; i<num; i++)
        {
            for (j=num-1; j>=i; j--)
            {
                if (arr[j-1]>arr[j])
                {
                    counter++;
                    temp = arr[j];
                    arr[j] = arr[j-1];
                    arr[j-1] = temp;
                }
            }
        }
		printf("Minimum exchange operations : %d\n", counter);      
    }
	
    return 0;
}
