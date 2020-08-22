// https://leetcode-cn.com/problems/intersection-of-two-arrays-ii/

class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> hm;
        vector<int> ans;
        if(nums1.size() > nums2.size()){// 检查数组的大小并对较小的数组进行哈希映射
            for(auto n: nums2) hm[n]++;
            for(auto n: nums1){
                if(hm.isEmpty()) return ans;
                if(hm[n]-- > 0){
                    ans.push_back(n);
                }
            }
        }
        else{
            for(auto n: nums1) hm[n]++;
            for(auto n: nums2){
                if(hm.isEmpty()) return ans;
                if(hm[n]-- > 0){
                    ans.push_back(n);
                }
            }
        }
        return ans;
    }

    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());
        int i = 0, j = 0, k = 0;
        while(i < nums1.size() && j < nums2.size()){
            if(nums1[i] == nums2[j]){
                nums1[k++] = nums1[i++];
                j++;
            }
            else if(nums1[i] > nums2[j]){
                j++;
            }
            else{
                i++;
            }
        }
        return vector<int>(begin(nums1), begin(nums1) + k);
    }

/* 如果给定的数组已经排好序呢？你将如何优化你的算法？
用上面的第二种办法，使用两个指针进行遍历。
*/

/*"如果 nums2 的元素存储在磁盘上，磁盘内存是有限的，并且你不能一次加载所有的元素到内存中，你该怎么办？"
如果内存十分小，不足以将数组全部载入内存，那么必然也不能使用哈希这类费空间的算法，
只能选用空间复杂度最小的算法，即"排序双指针"。但是排序不能用快排，一般说排序算法都是针对于内部排序，
一旦涉及到跟磁盘打交道（外部排序），则需要特殊的考虑。归并排序是天然适合外部排序的算法，
可以将分割后的子数组写到单个文件中，归并时将小文件合并为更大的文件。当两个数组均排序完成生成两个大文件后，
即可使用双指针遍历两个文件，如此可以使空间复杂度最低。
*/

};