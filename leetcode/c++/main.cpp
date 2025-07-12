//#include "../../modules/PrimeTable.hpp"
//#include "../../modules/common.hpp"
#include "common.hpp"
#include "PrimeTable.hpp"

void qsortImpl(vector<int> &arr, int l, int r) {
    if (r - l <= 0) return;

    int mid = arr[l];
    int i = l + 1, j = l + 1;
    for (; i <= r; i++) {
        if (arr[i] <= mid) {
            swap(arr[i], arr[j++]);
        }
    }
    swap(arr[l], arr[j - 1]);
    qsortImpl(arr, l, j - 2);
    qsortImpl(arr, j, r);
}

void qsort(vector<int> &v) {
    qsortImpl(v, 0, v.size() - 1);
}

int main() {
    vector<int> v{2, 30, 5, 7, 1, -5};
    qsort(v);
    _print(v);
}
