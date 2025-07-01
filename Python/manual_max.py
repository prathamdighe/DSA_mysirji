def manual_max(nums):
    if not nums:
        return None
    current_max=nums[0]
    for num in nums:
        if current_max<=num:
            current_max=num
    
    return current_max

nums=[1,3,4,6,76,1,2,4]
print(manual_max(nums))