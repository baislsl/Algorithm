#include "common.hpp"

using namespace std;

class Solution {
    using ll = long long;

public:
    long long maximizeXorAndXor(const vector<int> &ns) {
        int n = ns.size();
        vector<unsigned int> ad(1 << n, 0), xr(1 << n, 0), xrs(1 << n, 0);
        ad[0] = INT_MAX;
        int bit = 0;
        for (int code = 1; code < (1 << n); code++) {
            if (code == (1 << (bit + 1))) bit++;
            assert(code >> bit == 1);
            ad[code] = ad[code ^ (1 << bit)] & ns[bit];
            xr[code] = xr[code ^ (1 << bit)] ^ ns[bit];
            for (int first = code; first >> bit; first = (first - 1) & code) {
                xrs[code] = max(xrs[code], xr[code - first] + xr[first]);
            }
        }

        ll ans = xrs[(1 << n) - 1];
        for (int code = 1; code < (1 << n); code++) {
            ans = max<ll>(ans, ad[code] + (long)xrs[(1 << n) - code - 1]);
        }
        return ans;
    }
};

int main() {
    int cc = -1;
    auto v = cc >> 3;
    Solution s;
    _print(s.maximizeXorAndXor({2, 3}));
    _print(s.maximizeXorAndXor({2, 3, 6, 7}));
    _print(s.maximizeXorAndXor({
        364132842, 799748385, 63921894, 386410730, 207552354, 611932722, 247034943, 623359122, 17011513, 297157134,
        420455057, 12422494, 478926093, 542119289, 773242843, 114392429, 595673332, 60395451
    }));
}
