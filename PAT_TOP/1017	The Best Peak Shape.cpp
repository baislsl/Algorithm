#include <iostream>
#include <climits>

using namespace std;

int my_greater(int a, int b) {
    return a - b;
}

int my_less(int a, int b) {
    return b - a;
}

void dp(int *a, int begin, int end, int d, int cmp(int, int), int *data) {
    for (int i = begin; cmp(i, end) < 0; i += d) {
        int last = INT_MIN;
        int j = i - d;
        data[i] = 0;
        while (cmp(j, begin) >= 0) {
            if (a[j] > last && a[j] < a[i]) {
                last = a[j];
                data[i] = max(data[j] + 1, data[i]);
            }
            j -= d;
        }
    }
}

int main() {
    // freopen("/home/baislsl/c_c++/ads_pro4/ini.txt", "r", stdin);
    int n;
    cin >> n;
    //cout << n;
    int *a = new int[n],
        *left = new int[n],
        *right = new int[n];

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    dp(a, 0, n, 1, my_greater, left);
    dp(a, n - 1, -1, -1, my_less, right);

    int max = 0, l = 0, r = 0, index = -1;
    bool OK = true;
    for (int i = 0; i < n; i++) {
        // cout << left[i] << ": " << right[i] << endl;
        if (left[i] != 0 && right[i] != 0) {
            if ((left[i] + right[i] > max) ||
                ((left[i] + right[i] == max) && abs(left[i] - right[i]) < abs(l - r))) {
                OK = true;
                max = left[i] + right[i];
                l = left[i];
                r = right[i];
                index = i;
            }else if(((left[i] + right[i] == max) && abs(left[i] - right[i]) == abs(l - r))){
                OK = false;
            }
        }
    }

    if (index == -1) {
        cout << "No peak shape\n";
    } else {
        cout << max + 1 << " " << index + 1 << " " << a[index] << endl;
    }
//    if(OK) cout << "true";
//    else cout << "false";

    delete[] a;
    delete[] left;
    delete[] right;


}
