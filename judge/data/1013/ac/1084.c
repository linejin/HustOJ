#include <queue>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <cstring>
#include <iostream>
using namespace std;
vector<int> v[100];
int visited[100];
int smallerchk[100];
int biggerchk[100];
int main(){
    int N, M; cin >> N >> M;
    int mid = (N + 1) / 2;
    for (int i = 0; i < M; ++i){
        int big, small;
        cin >> big >> small;
        v[big].push_back(small);
    }
    for (int i = 1; i <= N; ++i){
        //각 번호 별로 자기부터 작은 것을 센다 
        //한칸 한칸 갈때마다 +1
        int cnt = 0;
        memset(visited, -1, sizeof(visited));
        queue<int> q;
        int start = i;
        q.push(start);
        while (!q.empty()){
            int here = q.front(); q.pop();
            //cout <<"here " <<here << endl;
            for (int j = 0; j < v[here].size(); ++j){
                int there = v[here][j];
                if (visited[there] == -1){
                    //각 노드입장에서 몇번 '자기가 작은 것으로'
                    //불려졌는지 센다, 여러번 세지면 안되니까 이 조건문 안에 있어야함
                    //1~N번을 시작으로 반복문 돌때 한번씩 세짐
                    biggerchk[there]++;
                    cnt++;
                    visited[there] = 1;
                    q.push(there);
                }
            }
        }
        //자기보다 작은노드의 수 기록
        smallerchk[i] = cnt;
        //cout << i << " " << cnt << endl;
    }

    int ans = 0;
    for (int i = 1; i <= N; ++i){
        //cout << biggerchk[i] << endl;
        if (biggerchk[i] >= mid || smallerchk[i] >= mid){
            ans++;
        }
    }
    cout << ans << endl;
    return 0;
}