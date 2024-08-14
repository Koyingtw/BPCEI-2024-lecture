bool check(int mid) {

}
// 可以的答案裡面找最小的
int l = ..., r = ...;
while (l < r) {
    int mid = (l + r) / 2;
    if (check(mid)) {
        r = mid;
    }
    else {
        l = mid + 1;
    }
}
// 可以的答案裡面找最大的
int l = ..., r = ...;
while (l < r) {
    int mid = (l + r + 1) / 2;
    if (check(mid)) {
        l = mid;
    }
    else {
        r = mid - 1;
    }
}