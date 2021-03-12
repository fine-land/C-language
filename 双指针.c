//给你一个数组 nums 和一个值 val，你需要 原地 移除所有数值等于 val 的元素，并返回移除后数组的新长度。
//
//不要使用额外的数组空间，你必须仅使用 O(1) 额外空间并 原地 修改输入数组。
//
//元素的顺序可以改变。你不需要考虑数组中超出新长度后面的元素。
//
//
//
//来源：力扣（LeetCode）
//链接：https ://leetcode-cn.com/problems/remove-element
//著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

//快慢双指针，满指针用来复写，快指针检查是否等于val
int removeElement(int* nums, int numsSize, int val) {
    int* cur = nums;
    int count = 0;
    int i = 0;
    for (int i = 0; i < numsSize; i++) {
        if (cur[i] != val) {
            *nums = cur[i];
            nums++;
            count++;
        }
    }
    return count;
}
//缺点是需要检查越界问题，cur_point的值会超越numsSize-1.
int removeElement(int* nums, int numsSize, int val) {
    int* cur_point = nums;
    int* back = nums;
    int count = 0;
    int i = 0;
    for (i = 0; i < numsSize; i++) {
        if (*cur_point != val) {
            *nums = *cur_point;
            nums++;
            count++;
        }
        if (cur_point != &back[numsSize - 1]) {
            cur_point++;
        }
    }
    return count;
}
