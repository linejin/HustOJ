#include<cstdio>
#include<algorithm>
using namespace std;
int main()
{
    int n;
    scanf("%d", &n);
    int num[100000];
    int sum = 0;
    for(int i = 0; i < n; i++)
    {
        scanf("%d",&num[i]);
        sum += num[i];
    }
    printf("%d\n",sum/n);
    sort(num, num + n);
    printf("%d",num[n/2]);
}