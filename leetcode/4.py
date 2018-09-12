class Solution:
    def findMedianSortedArrays(self, nums1, nums2):
        """
        :type nums1: List[int]
        :type nums2: List[int]
        :rtype: float
        """
        self.len1 = len(nums1)
        self.len2 = len(nums2)
        ans = (nums1[self.len1 / 2] + nums2[self.len2 / 2]) / 2.0
        return ans
