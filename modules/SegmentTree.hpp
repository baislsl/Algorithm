//
// Created by baislsl on 2025/7/7.
//

#ifndef SEGMENTTREE_HPP
#define SEGMENTTREE_HPP


#include <bits/stdc++.h>
using namespace std;

template<typename T>
class SegmentTree {
private:
    int n;
    vector<T> tree;
    function<T(const T &, const T &)> merge;
    T identity;

    void build(const vector<T> &data, int node, int l, int r) {
        if (l == r) {
            tree[node] = data[l];
            return;
        }
        int mid = (l + r) / 2;
        build(data, 2 * node, l, mid);
        build(data, 2 * node + 1, mid + 1, r);
        tree[node] = merge(tree[2 * node], tree[2 * node + 1]);
    }

    void updatePoint(int node, int l, int r, int idx, T val) {
        if (l == r) {
            tree[node] = val;
            return;
        }
        int mid = (l + r) / 2;
        if (idx <= mid)
            updatePoint(2 * node, l, mid, idx, val);
        else
            updatePoint(2 * node + 1, mid + 1, r, idx, val);
        tree[node] = merge(tree[2 * node], tree[2 * node + 1]);
    }

    T queryRange(int node, int l, int r, int ql, int qr) {
        if (qr < l || ql > r) return identity;
        if (ql <= l && r <= qr) return tree[node];
        int mid = (l + r) / 2;
        return merge(
            queryRange(2 * node, l, mid, ql, qr),
            queryRange(2 * node + 1, mid + 1, r, ql, qr)
        );
    }

public:
    SegmentTree(const vector<T> &data,
                function<T(const T &, const T &)> mergeFunc,
                T identityVal)
        : merge(mergeFunc), identity(identityVal) {
        n = data.size();
        tree.resize(4 * n);
        build(data, 1, 0, n - 1);
    }

    void update(int idx, T val) {
        updatePoint(1, 0, n - 1, idx, val);
    }

    // [l, r]
    T query(int l, int r) {
        return queryRange(1, 0, n - 1, l, r);
    }
};

#endif //SEGMENTTREE_HPP

/*
int main() {
    vector<int> data = {1, 3, 5, 7, 9, 11};

    SegmentTree<int> seg(data, [](int a, int b) { return max(a, b); }, INT_MIN);

    cout << "最大值 [1, 4]: " << seg.query(1, 4) << endl;

    seg.update(2, 10);  // 把 index=2 的值改为 10

    cout << "更新后最大值 [1, 4]: " << seg.query(1, 4) << endl;

    return 0;
}

最大值 [1, 4]: 9
更新后最大值 [1, 4]: 10

int main() {
    vector<int> data = {1, 2, 3, 4, 5};

    SegmentTree<int> seg(data, [](int a, int b) { return a + b; }, 0);

    cout << "区间和 [0, 4]: " << seg.query(0, 4) << endl;

    seg.update(0, 10);

    cout << "更新后区间和 [0, 4]: " << seg.query(0, 4) << endl;

    return 0;
}

区间和 [0, 4]: 15
更新后区间和 [0, 4]: 24

int main() {
    vector<int> data = {8, 6, 7, 3, 9};

    SegmentTree<int> seg(data, [](int a, int b) { return min(a, b); }, INT_MAX);

    cout << "最小值 [1, 3]: " << seg.query(1, 3) << endl;

    seg.update(2, 1);

    cout << "更新后最小值 [1, 3]: " << seg.query(1, 3) << endl;

    return 0;
}

最小值 [1, 3]: 3
更新后最小值 [1, 3]: 1

 */
