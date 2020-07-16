#include	<stdio.h>

void qsort(int arr[], int l, int r)
{
	int p = arr[l];
	int high = r;
	int low = l;
	int temp;
	do {
		while(arr[low]<p) low++;
		while(arr[high]>p)	high--;
		if(high>=low)
		{
			temp = arr[low];
			arr[low] = arr[high];
			arr[high] = temp;
			low++;
			high--;
		}
	} while(high>=low);

	if(high>l)	qsort(arr, l, high);
	if(low<r)	qsort(arr, low, r);
}


int main()
{
	long N, sum;
	int avg, mid;
	scanf("%ld", &N);
	int numbers[N];
	int temp;
	for(int i=0; i<N; i++)
	{
		scanf("%d", &numbers[i]);
		sum+=numbers[i];
	}
	avg = sum/N;
	printf("%d\n", avg);

	qsort(numbers, 0, N-1);
	printf("%d\n", numbers[(N-1)/2]);
	return 0;
}