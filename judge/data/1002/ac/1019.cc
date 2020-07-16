#include <stdio.h>

int main()
{
    int h, m, s, t;
    scanf("%d %d %d", &h, &m, &s);
    scanf("%d", &t);

    // change t to h m s 
    s -= t % 60; 
    t /= 60; 
    if (s < 0) 
    {
        s += 60;
        m--; 
    }
    m -= t % 60; 
    t /= 60; 
    h -= t; 
    if (m < 0)
    {
        m += 60;
        h--; 
        if(h < 0) h += 24;
    }
    printf("%d %d %d", h, m, s); 
}