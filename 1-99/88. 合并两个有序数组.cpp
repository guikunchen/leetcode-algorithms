#include<iostream>
#include<vector>
#include<set>
using namespace std;

// https://leetcode-cn.com/problems/merge-sorted-array/


class Solution {
public:

    // 如果把nums1 copy一份，然后用双指针放到nums1里，这样时间n+m，空间m

    // 因为是数组，所以可以双指针从尾巴添加，时间n+m，空间1。
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n){
        int indexEnd = m + n - 1;
        while(n > 0){
            if(m > 0 && nums1[m - 1] > nums2[n - 1]){
                nums1[indexEnd--] = nums1[--m];
            }
            else{
                nums1[indexEnd--] = nums2[--n];
            }
        }
    }

    // 自己想的，利用有序，可以使用二分查找+插入排序，时间m(n + m)（挪动的时候太费时间了），空间1
    int search(std::vector<int> &array, int size, int v){
        int begin = 0, end = size;
        while(begin < end){
            int mid = (begin + end) >> 1;
            if(v >= array[mid]){
                begin = mid + 1;
            }
            else{
                end = mid;
            }
        }
        return begin;
    }

    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n){
        for(int begin = 0; begin < n; begin++){
            int index = search(nums1, m++, nums2[begin]);
            for(int i = m - 1; i > index; --i){
                nums1[i] = nums1[i - 1];
            }
            nums1[index] = nums2[begin];
        }
    }

    // 一开始理解错题目了，以为合并两个无序数组
    // 先把第二个数组元素copy过去，再堆排序
    void siftDown(std::vector<int> &array, int size, int index){// 下滤
        int cur = array[index];
        int half = size >> 1;// 第一个叶子节点的索引 == 非叶子节点的数量
        while(index < half){// 保证index不是叶子节点，即小于第一个叶子节点的索引
            // 1.同时两个子节点  2.只有左子节点
            // 默认为左子节点的索引
            int childIndex = (index << 1) + 1;
            int child = array[childIndex];
            // 找到右子节点判断存在且更大
            int rightIndex = childIndex + 1;
            if(rightIndex < size && array[rightIndex] > child){
                child = array[childIndex = rightIndex];
            }
            
            if(cur >= child) break;

            array[index] = child;

            index = childIndex;
        }
        array[index] = cur;
    }

    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int heapSize = m + n;
        for(int i = m; i < heapSize; i++) nums1[i] = nums2[i - m];
        for (int i = (heapSize >> 1) - 1; i >= 0; --i){
            siftDown(nums1, heapSize, i);
        }
        while(heapSize > 1){
            swap(nums1[0], nums1[--heapSize]);
            siftDown(nums1, heapSize, 0);
        }
    }
};