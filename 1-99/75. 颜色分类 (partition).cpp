#include<iostream>
#include<vector>
#include<set>
using namespace std;
// https://leetcode-cn.com/problems/sort-colors/

// 第一种解法，直接手写快排，题目不让调用sort函数

// 第二种，最优解，执行一次partition就可以分为三块，0，1，2，时间n，空间1
// [0, zero) [zero, one) [two, size - 1]
class Solution {
public:
	void sortColors(vector<int>& nums) {
        if(nums.size() < 2) return;

        int zero = 0;
        int one = 0;
        int two = nums.size();
        while(one < two){
        	if(nums[one] == 0){// one扫描的最快，one的左边只有0和1，所以替换后
        		swap(nums[one], nums[zero]);
        		zero++;
        		one++;
        	}
        	else if(nums[one] == 1){
        		one++;
        	}
        	else{
        		two--;
        		swap(nums[one], nums[two]);
        	}
        }
    }

	int partition(vector<int>& nums, int begin, int end){
		int value = nums[begin];
		--end;
		while(begin < end){
			while(begin < end){
				if(nums[end] < value){
					nums[begin++] = nums[end];
					break;
				}
				else{
					end--;
				}
			}
			while(begin < end){
				if(nums[begin] > value){
					nums[end--] = nums[begin];
					break;
				}
				else{
					begin++;
				}
			}
		}
		nums[begin] = value;
		return begin;
	}

	void quickSort(vector<int>& nums, int begin, int end){
		if(begin >= end) return;
		int mid = partition(nums, begin, end);
        quickSort(nums, begin, mid);
        quickSort(nums, mid + 1, end);
	}

    void sortColors(vector<int>& nums) {
        if(nums.size() == 0) return;

        quickSort(nums, 0, nums.size());
    }
};