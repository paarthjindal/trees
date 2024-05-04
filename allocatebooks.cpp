#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool isPossible(const vector<int> &A, int B, int mid) {
    int students = 1;
    int pages = 0;
    for (int i = 0; i < A.size(); i++) {
        
        if (pages + A[i] > mid) {
            students++;
            pages = A[i];
        } else {
            pages += A[i];
        }
    }
    return students <= B;
}

int allocateBooks(const vector<int> &A, int B) {
    int total_pages = 0;
    int max_pages = 0;
    for (int i = 0; i < A.size(); i++) {
        total_pages += A[i];
        max_pages = max(max_pages, A[i]);
    }

    int left = max_pages; // Minimum possible value
    int right = total_pages; // Maximum possible value
    int result = -1;

    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (isPossible(A, B, mid)) {
            result = mid;
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }

    return result;
}

int main() {
    vector<int> A1 = {12, 34, 67, 90};
    int B1 = 2;
    cout << allocateBooks(A1, B1) << endl; // Output: 113

    vector<int> A2 = {5, 17, 100, 11};
    int B2 = 4;
    cout << allocateBooks(A2, B2) << endl; // Output: 100

    return 0;
}
