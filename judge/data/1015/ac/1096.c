#include<algorithm>
#include<cstdio>
using namespace std;
int main() {
    int n, k, s;
    scanf("%d %d %d", &n, &k, &s);

    pair<int, int> p[30001] = { {0,0} };
    for (int i = 1; i <= n; i++) {
        scanf("%d %d", &p[i].first, &p[i].second);
        p[i].first = s - p[i].first;
        if (p[i].first == 0) 
            p[i].second = 0;
    }

    sort(p, p + n + 1);

    int idx = -1;
    for (int i = 0; i <= n; i++) 
        if (p[i].first == 0)
            idx = i;

    int ans = 0;
    int i = 0;
    while(i < idx)
    {
        ans += (-p[i].first) * 2;
        int bus = 0;
        int j = 0;
        for (j = i; j < idx; j++) {
            bus += p[j].second;
            if (bus > k) {
                p[j].second = bus - k;
                break;
            }
        }
        i = j;
    }

    i = n;
    while(i > idx) {
        ans += ((p[i].first) * 2);
        int bus = 0;
        int j = 0;
        for (j = i; j > idx; j--) {
            bus += p[j].second;
            if (bus > k) {
                p[j].second = bus - k;
                break;
            }
        }
        i = j;
    }
    printf("%d", ans);
}
