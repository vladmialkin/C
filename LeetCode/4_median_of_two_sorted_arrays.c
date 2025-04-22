/*Given two sorted arrays nums1 and nums2 of size m and n respectively, return the median of the two sorted arrays.
 *
 * The overall run time complexity should be O(log (m+n)).
 */

#include <stdio.h>

double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size) {
	int total = nums1Size + nums2Size;
	int new_nums[total];
	int i = 0, j = 0, k = 0;
	int ind;
	double median = 0.0;
	
	while(i < nums1Size && j < nums2Size){
		if (nums1[i] < nums2[j])
			new_nums[k++] = nums1[i++];
		else
			new_nums[k++] = nums2[j++];
	}

	while(i < nums1Size)
		new_nums[k++] = nums1[i++];
	while(j < nums2Size)
		new_nums[k++] = nums2[j++];
	if (total % 2 == 0){
		ind = total / 2;
		median = (new_nums[ind - 1] + new_nums[ind]) / 2.0;
	}
	else
		median = new_nums[total / 2];
	return median;
}

int main(){
	int nums1[3] = {1, 2, 5};
	int nums2[5] = {3, 6, 8, 9, 10};

	double median = 0.0;
	median = findMedianSortedArrays(nums1, 3, nums2, 5);
	printf("%lf \n", median);
}
