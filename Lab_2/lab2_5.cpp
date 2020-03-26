#include <iostream>

 int a[30000000];

using namespace std;

void kth(int* a, int l, int r, int k) {
    int i = l, j = r, v = a[(l + r) / 2];
    while (i <= j) {
        while(a[i] < v) i++;
        while(a[j] > v) j--;
        if (i <= j) {
            swap(a[i], a[j]);
            i++;
            j--;
        }
    }
    if ((j > l) && (k <= j)) kth(a, l, j, k);
    if ((i < r) && (k >= j)) kth(a, i, r, k);
    return;
}

int main() {
    freopen("kth.in", "r", stdin);
    freopen("kth.out", "w", stdout);
    int n, k, A, B, C;
    cin >> n >> k >> A >> B >> C >> a[0];
    if (n > 1) {
        cin >> a[1];
        for (int i = 2; i < n; i++) {
            a[i] = A * a[i - 2] + B * a[i - 1] + C;
        }
    }
    kth(a, 0, n - 1, k - 1);
    cout << a[k - 1] << '\n';
    return 0;
}