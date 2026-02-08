bool isvalid(int arr[], int n, int k, int maxAllowedVal) {
    int cur = 0;
    int stu = 1;
    for (int i = 0; i < n; i++) {
        if (arr[i] > maxAllowedVal) return false;

        if (cur + arr[i] <= maxAllowedVal) {
            cur += arr[i];
        } else {
            stu++;
            cur = arr[i];
        }
    }
    return (stu <= k);
}

int findPages(int arr[], int n, int k) {
    if (k > n) return -1;

    int st = 0;
    int end = 0;
    int ans = -1;

    for (int i = 0; i < n; i++) {
        //if (arr[i] > st) st = arr[i];   // max element
        end += arr[i];                  // total sum
    }

    while (st <= end) {
        int mid = st + (end - st) / 2;

        if (isvalid(arr, n, k, mid)) {
            ans = mid;
            end = mid - 1;
        } else {
            st = mid + 1;
        }
    }
    return ans;
}