void sort(int* nums, int numsSize){
    for(int i = 0; i < numsSize-1; i++){
        for(int j = i; j < numsSize; j++){
            if(*(nums+i) > *(nums+j)){
                int tmp = *(nums+i);
                *(nums+i) = *(nums+j);
                *(nums+j) = tmp;
            }
        }
    }
}

int findPairs(int* nums, int numsSize, int k){  
    if(numsSize < 2) return 0;
    if(k < 0) return 0;
    
    int count = 0;
    sort(nums, numsSize);
    
    for(int i = 0; i < numsSize-1; i++){
        for(int j = i + 1; j < numsSize; j++){
            if(j != numsSize-1 && nums[j] == nums[j+1]) continue;
            if(abs(nums[i]-nums[j])==k) count++;
        }
        for(int l = i+1; l < numsSize-1; l++){
            if(nums[i] == nums[l]) i++;
            else break;
        }
    }
    
    return count;
}
