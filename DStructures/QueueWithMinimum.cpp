#include <iostream>
#include <fstream>
#include <cmath>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <cstdlib>
#include <cstdio>
#include <string>
#include <cstring>
#include <cassert>
#include <utility>
#include <iomanip>

using namespace std;

const int MAXN = 205000;

int n, m;
deque < pair <int, int> > d;
int a[MAXN];

void enqueue(int x) {
    int num = 1;
    while (!d.empty() && d.back().first > x) {
        num += d.back().second;
        d.pop_back();
    }
    d.push_back(make_pair(x, num));
}

void dequeue() {
    if (d.front().second == 1) {
        d.pop_front();
    }
    else {
        d.front().second--;
    }
}

int getMin() {
    return d.front().first;
}

int main() {
    //assert(freopen("input.txt","r",stdin));
    //assert(freopen("output.txt","w",stdout));

    scanf("%d %d", &n, &m);

    for (int i = 1; i <= n; i++)
        scanf("%d", &a[i]);

    for (int i = 1; i <= m; i++) {
        enqueue(a[i]);  
    }

    printf("%d\n", getMin());

    for (int i = m + 1; i <= n; i++) {
        dequeue();
        enqueue(a[i]);
        printf("%d\n", getMin());
    }

    return 0;
}
