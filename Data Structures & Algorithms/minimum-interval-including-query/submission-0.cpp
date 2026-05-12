class Seg {

public:

    vector<int> seg, lazy;

    Seg(int n) {

        seg.assign(4 * n, INT_MAX);

        lazy.assign(4 * n, INT_MAX);
    }

    void lazyUp(int ind, int l, int r) {

        if (lazy[ind] != INT_MAX) {

            seg[ind] = min(seg[ind], lazy[ind]);

            if (l != r) {

                lazy[2 * ind + 1] =
                    min(lazy[2 * ind + 1],
                        lazy[ind]);

                lazy[2 * ind + 2] =
                    min(lazy[2 * ind + 2],
                        lazy[ind]);
            }

            lazy[ind] = INT_MAX;
        }
    }

    void update(int ind, int l, int r,
                int ql, int qr, int val) {

        lazyUp(ind, l, r);

        // no overlap
        if (l > qr || r < ql)
            return;

        // complete overlap
        if (l >= ql && r <= qr) {

            lazy[ind] =
                min(lazy[ind], val);

            lazyUp(ind, l, r);

            return;
        }

        int mid = (l + r) >> 1;

        update(2 * ind + 1,
               l, mid,
               ql, qr, val);

        update(2 * ind + 2,
               mid + 1, r,
               ql, qr, val);

        seg[ind] =
            min(seg[2 * ind + 1],
                seg[2 * ind + 2]);
    }

    int query(int ind, int l, int r,
              int pos) {

        lazyUp(ind, l, r);

        if (l == r)
            return seg[ind];

        int mid = (l + r) >> 1;

        if (pos <= mid) {

            return query(2 * ind + 1,
                         l, mid,
                         pos);
        }

        return query(2 * ind + 2,
                     mid + 1, r,
                     pos);
    }
};

class Solution {
public:

    vector<int> minInterval(
        vector<vector<int>>& intervals,
        vector<int>& queries) {

        int mx = 10000;

        Seg st(mx + 1);

        for (auto &v : intervals) {

            int l = v[0];
            int r = v[1];

            int len = r - l + 1;

            st.update(0, 1, mx,
                      l, r, len);
        }

        vector<int> ans;

        for (auto q : queries) {

            int val =
                st.query(0, 1, mx, q);

            if (val == INT_MAX)
                ans.push_back(-1);

            else
                ans.push_back(val);
        }

        return ans;
    }
};