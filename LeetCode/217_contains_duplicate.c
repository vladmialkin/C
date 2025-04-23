/*
Given an integer array nums, return true if any value appears at least twice in the array, and return false if every element is distinct.
*/
#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <stdbool.h>

int compare(const void *a, const void *b){
    return (*(int*)a - *(int*)b);
}

bool containsDuplicate(int* nums, int numSize){
    qsort(nums, numSize, sizeof(int), compare);
    for(int i = 0; i < numSize - 1; ++i){
        if(nums[i] == nums[i+1])
            return true;
        }
    return false;
} 

int main(){
    int nums1[4] = {1,2,3,1};
    int nums2[4] = {1,2,3,4};
    assert(containsDuplicate(nums1, 4) == true);
    assert(containsDuplicate(nums2, 4) == false);
}
