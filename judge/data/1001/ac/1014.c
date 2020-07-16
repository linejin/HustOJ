#include <cstdio>

int main()
{
    char c;
    int i;
    long long l; 
    double d;
    char s[100]; 
    
    scanf("%c %d %lld %lf %s", &c, &i, &l, &d, s);
    printf("%s %.1lf %lld %d %c", s, d, l, i, c);
}