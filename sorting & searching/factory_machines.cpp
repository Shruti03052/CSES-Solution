#include <bits/stdc++.h>
using namespace std;

bool isPossible(long long time, const vector<int>& arr, long long t) {
    long long cnt = 0;
    for (int i = 0; i < arr.size(); i++) {
        cnt += time / arr[i];
        if (cnt >= t) {
            return true;
        }
    }
    return false;
}

long long min_time(int n, long long t, const vector<int>& arr) {
    long long ans = -1;
    long long low = *min_element(arr.begin(), arr.end());
    long long high = (*max_element(arr.begin(), arr.end())) * t;
    
    while (low <= high) {
        long long mid = low + (high - low) / 2;
        if (isPossible(mid, arr, t)) {
            ans = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    
    return ans;
}

int main() {
    long long n, t;
    cin >> n >> t;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    cout << min_time(n, t, arr) << endl;
    return 0;
}
