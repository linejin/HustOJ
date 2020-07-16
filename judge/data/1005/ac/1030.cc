#include <cstdio>

int main()
{
    int n;
    scanf("%d", &n); 
    int s = 0;
    for(int i = n; i > 0; i /= 10)
    {
        s += i % 10; 
    }
    printf("%d\n", s); 
}