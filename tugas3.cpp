#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int lowerBound(vector<int>& arr, int left, int right, int target) {
    int result = right + 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (arr[mid] >= target) {
            result = mid;
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }

    return result;
}

int upperBound(vector<int>& arr, int left, int right, int target) {
    int result = right + 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (arr[mid] > target) {
            result = mid;
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }

    return result;
}

int main() {
    int N, X;

    cout << "Masukkan N dan X: ";
    cin >> N >> X;

    vector<int> arr(N);

    cout << "Masukkan " << N << " elemen array: ";
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }

    sort(arr.begin(), arr.end());

    cout << "\nArray setelah diurutkan: ";
    for (int i = 0; i < N; i++) {
        cout << arr[i] << " ";
    }

    long long jumlahPasangan = 0;

    cout << "\n\nPasangan yang ditemukan:\n";

    for (int i = 0; i < N; i++) {
        int target = X - arr[i];

        int kiri = lowerBound(arr, i + 1, N - 1, target);
        int kanan = upperBound(arr, i + 1, N - 1, target);

        for (int j = kiri; j < kanan; j++) {
            cout << arr[i] << " + " << arr[j] << " = " << X << endl;
        }

        jumlahPasangan += kanan - kiri;
    }

    cout << "\nTotal pasangan: " << jumlahPasangan << endl;

    return 0;
}