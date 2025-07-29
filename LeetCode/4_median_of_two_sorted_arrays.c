/*Given two sorted arrays nums1 and nums2 of size m and n respectively, return the median of the two sorted arrays.
 *
 * The overall run time complexity should be O(log (m+n)).
 */

#include <stdio.h>

double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size) {
	int total = nums1Size + nums2Size;
	int i = 0, j = 0;
	int mid1, mid2;
	double median = 0.0;
	
	for(int k = 0; k < total / 2; ++k){
		mid1 = mid2;
		if (i < nums1Size && (j >= nums2Size || nums1[i] < nums2[j]))
			mid2 = nums1[i++];
		else
			mid2 = nums2[j++];
	}

	if (total % 2 == 0){
		median = (mid1 + mid2) / 2.0;
	}
	else
		median = mid2;
	return median;
}

int main(){
	int nums1[3] = {1, 2, 5};
	int nums2[4] = {3, 6, 8, 10};

	double median = 0.0;
	median = findMedianSortedArrays(nums1, 3, nums2, 4);
	printf("%lf \n", median);
}
