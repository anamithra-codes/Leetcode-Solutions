/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* searchRange(int* nums, int numsSize, int target, int* returnSize) {
    *returnSize = 2;
    int* result = (int*)malloc(2 * sizeof(int));
    result[0] = -1;
    result[1] = -1;

    if (numsSize == 0) return result;
    int l = 0, r = numsSize - 1;
    while (l <= r) {
        int mid = l + (r - l) / 2;
        if (nums[mid] >= target) {
            if (nums[mid] == target) result[0] = mid;
            r = mid - 1; // Squeeze toward the left
        } else {
            l = mid + 1;
        }
    }

    int left = 0, right = numsSize - 1; // Reset pointers
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (nums[mid] <= target) {
            if (nums[mid] == target) result[1] = mid;
            left = mid + 1; // Squeeze toward the right
        } else {
            right = mid - 1;
        }
    }

    return result;
}