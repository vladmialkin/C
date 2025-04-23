/*
Given an integer array nums, return true if any value appears at least twice in the array, and return false if every element is distinct.
*/
#include <stdio.h>
#include <assert.h>
#include <stdbool.h>

bool containsDuplicate(int* nums, int numSize){
    for(int i = 0; i < numSize - 1; ++i){
        for(int j = 1; j < numSize; ++j){
            if (nums[i] == nums[j] && i != j)
                return true;
            continue;
        }
    }
    return false;
} 

int main(){
    int nums1[4] = {1,2,3,1};
    int nums2[4] = {1,2,3,4};
    assert(containsDuplicate(nums1, 4) == true);
    assert(containsDuplicate(nums2, 4) == false);
}
