#include <bits/stdc++.h>
using namespace std;

// use indexed array
// inspired from Pashka
template <typename T>
class SegmentTree {
public:
    size_t size;
    vector<T> tree;
    const T DEFAULT = T{};

    T merge(T a, T b) { return a + b; }

    void init(size_t n) {
        size = 1;
        while (size < n) size *= 2;
        tree.resize(2 * size - 1, DEFAULT);
    }

    // void build(vector<int> &a,ll x,ll lx,ll rx) {
    //     //base case
    //     if(rx-lx == 1) {
    //         if(lx < int(a.size())) {
    //             values[x] = single(a[lx]);
    //         }
    //         return;
    //     }

    //     ll m = (lx+rx)/2;
    //     build(a,2*x +1,lx,m);
    //     build(a,2*x +2,m,rx);
    //     values[x] = merge(values[2*x +1],values[2*x +2]);
    // }

    // void build(vector<int> &a) {
    //     build(a,0,0,size);
    // }

    void set(size_t idx, T val, size_t x, size_t lx, size_t rx) {
        if (rx - lx == 1) {
            tree[x] = val;
            return;
        }
        size_t m = (lx + rx) / 2;
        if (idx < m) set(idx, val, 2 * x + 1, lx, m);
        else set(idx, val, 2 * x + 2, m, rx);
        tree[x] = merge(tree[2 * x + 1], tree[2 * x + 2]);
    }

    void set(size_t idx, T val) { set(idx, val, 0, 0, size); }

    T calc(size_t l, size_t r, size_t x, size_t lx, size_t rx) {
        if (lx >= r or l >= rx) return DEFAULT;
        if (lx >= l and rx <= r) return tree[x];

        size_t m = (lx + rx) / 2;
        T s1 = calc(l, r, 2 * x + 1, lx, m);
        T s2 = calc(l, r, 2 * x + 2, m, rx);
        return merge(s1, s2);
    }

    T query(size_t l, size_t r) { return calc(l, r + 1, 0, 0, size); }
};