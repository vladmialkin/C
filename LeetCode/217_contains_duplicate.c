/*
Given an integer array nums, return true if any value appears at least twice in the array, and return false if every element is distinct.
*/
#include <stdio.h>
#include <assert.h>
#include <stdbool.h>

typedef struct{
    int keys[100000];
    int count;
} HashTable;

bool containsKey(HashTable* ht, int key){
    for (int i = 0; i < ht->count; ++i){
        if (ht->keys[i] == key)
            return true;
    }
    return false;
}

bool containsDuplicate(int* nums, int numSize){
    HashTable ht = {.count = 0};
    for(int i = 0; i < numSize; ++i){
        if(containsKey(&ht, nums[i]))
            return true;
        ht.keys[ht.count++] = nums[i];
        }
    return false;
} 

int main(){
    int nums1[4] = {1,2,3,1};
    int nums2[4] = {1,2,3,4};
    assert(containsDuplicate(nums1, 4) == true);
    assert(containsDuplicate(nums2, 4) == false);
}
