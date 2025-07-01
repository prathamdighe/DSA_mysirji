def manual_min(nums): 
    if not nums:
        return None
    current_min=nums[0]
    for num in nums:
        if current_min>num:
            current_min=num
    return current_min

nums=[10,34,35,3,2123,5,43,6]

print(manual_min(nums))