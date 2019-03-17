#include <iostream>
#include <algorithm>
#include <vector>
#include <cstdio>

#define int long long

using namespace std;

const int N = (int)(5e5) + 322;
const int inf = (int)(1e18);

struct Node {
    int mx = 0, sum = 0;
    int push = -inf;
    bool pushed = false;
} t[N];

int a[N], n, pref[N], b[N], k[N], s[N];


inline void Merge(Node &acc, Node &left, Node &right) {
    acc.mx = max(left.mx, right.mx);
    acc.sum = left.sum + right.sum;
}

inline void push(int x, int l, int r) {
    if (t[x].push != -inf) {
        t[x].mx = t[x].push;
        t[x].sum = (r - l + 1) * t[x].push;
        if (l != r) {
            t[x + x].push = t[x].push;
            t[x + x + 1].push = t[x].push;
        }
        t[x].push = -inf;
    }
}

void build(int x, int l, int r) {
    if (l == r) {
        t[x].mx = b[l];
        t[x].sum = b[l];
        return;
    }
    int mid = (l + r) >> 1;
    build(x + x, l, mid);
    build(x + x + 1, mid + 1, r);
    Merge(t[x], t[x + x], t[x + x + 1]);
}

void update(int val, int tl, int tr, int x = 1, int l = 1, int r = n) {
    push(x, l, r);
    if (tl > r || l > tr) return;
    if (tl <= l && r <= tr) {
        t[x].push = val;
        push(x, l, r);
        return;
    }
    int mid = (l + r) >> 1;
    update(val, tl, tr, x + x, l, mid);
    update(val, tl, tr, x + x + 1, mid + 1, r);
    Merge(t[x], t[x + x], t[x + x + 1]);
}

int getsum(int tl, int tr, int x = 1, int l = 1, int r = n) {
    if (l > tr || r < tl) return 0;
    push(x, l, r);
    if (tl <= l && r <= tr) return t[x].sum;
    int mid = (l + r) >> 1;
    return getsum(tl, tr, x + x, l, mid) + getsum(tl, tr, x + x + 1, mid + 1, r);
}

int getpos(int pos, int val, int x = 1, int l = 1, int r = n) {
    push(x, l, r);
    if (l == r) {
        if (val > t[x].mx) return l + 1;
        return l;
    }
    int mid = (l + r) >> 1;
    if (mid < pos) return getpos(pos, val, x + x + 1, mid + 1, r);
    push(x + x, l, mid);
    if (t[x + x].mx < val) return getpos(pos, val, x + x + 1, mid + 1, r);
    return getpos(pos, val, x + x, l, mid);
}

void add(int val, int pos) {
    int curVal = getsum(pos, pos);
    curVal += val;
    int id = getpos(pos + 1, curVal) - 1;
    //cout << pos << ' ' << id << ' ' << curVal << "update\n";
    update(curVal, pos, id);
}


int get(int l, int r) {
    return s[r] - s[l - 1];
}

int getAns(int l, int r) {
    return get(l, r) + getsum(l, r);
}

signed main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    for(int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    for(int i = 1; i < n; ++i) {
        cin >> k[i];
    }
    for(int i = 1; i <= n; ++i) {
        pref[i] = pref[i - 1] + k[i - 1];
        //cout << pref[i] << '!';
        b[i] = a[i] - pref[i];
        s[i] = pref[i] + s[i - 1];
        //cout << b[i] << ' ';// << pref[i] << ' ' << i << endl;
    }
    build(1, 1, n);
    int q; cin >> q;
    for(int i = 1; i <= q; ++i) {
        char type; cin >> type;
        if (type == '+') {
            int pos, val; cin >> pos >> val;
            add(val, pos);
        }else {
            int l, r; cin >> l >> r;
            cout << getAns(l, r) << "\n";
        }
    }

    return 0;
}
// 0 3 4
// 3 3 3
// 6 6 6

