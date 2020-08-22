// https://leetcode-cn.com/problems/find-k-pairs-with-smallest-sums/
/*给定两个以升序排列的整形数组 nums1 和 nums2, 以及一个整数 k。

定义一对值 (u,v)，其中第一个元素来自 nums1，第二个元素来自 nums2。

找到和最小的 k 对数字 (u1,v1), (u2,v2) ... (uk,vk)。*/
class Solution
{
public:
    //找到和最小的 k 对数字
    //Solution1 找到全部组合n*m,然后排序。
    //Solution2 利用堆，在不枚举出全部数对的情况下
    //原问题转换成在n1个升序队列中，查找最小的前K对数字
    //Time  O(KlogN)
    vector<vector<int>> kSmallestPairs(vector<int> &nums1, vector<int> &nums2, int k)
    {
        int rows = nums1.size();
        int cols = nums2.size();
        vector<vector<int>> topK; //输出结果
        if (rows == 0 || cols == 0)
            return topK;

        // auto cmp = [&nums1, &nums2](pair<int, int> &a, pair<int, int> &b) {
        //     return (nums1[a.first] + nums2[b.second]) > (nums1[a.first] + nums2[b.second]);
        // }; //(3,(0,0)) （9,(1,0)）  构造小顶堆

        auto cmp = [&nums1, &nums2](const pair<int, int> &a, const pair<int, int> &b) { return nums1[a.first] + nums2[a.second] > nums1[b.first] + nums2[b.second]; };

        priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(cmp)> priorityQueue(cmp);

        //假设nums1每个元素和 有序数组nums1相加后，产生n个有序数组.
        //{3,5.7}
        //{9.11.13}
        //{13,15,17}
        //然后组成n×m升序矩阵。

        //插入n个有序数组中的一个元素
        for (int i = 0; i < rows; i++) {
            priorityQueue.emplace(i, 0);
        }

        //找到和最小的 k 对数字 
        while (k > 0 && !priorityQueue.empty())
        {
            k--; //每次比较获取最小的一个元素，类比合并2个有序链表。
            pair<int, int> temp = priorityQueue.top();// 存的是nums1和nums2的index
            priorityQueue.pop(); //获取一个记录
            //cout << nums1[temp.first] << ":" << nums2[temp.second] << endl;
            if (temp.second + 1 < cols) {
                //cout << nums1[temp.first] << " insert " << nums2[temp.second + 1] << endl;
                priorityQueue.emplace(temp.first, temp.second + 1); //列+1
            }

            vector<int> item;
            item.push_back(nums1[temp.first]);
            item.push_back(nums2[temp.second]);

            topK.push_back(item);
        }

        return topK;
    }
};