def manual_count(nums,target):
    count=0 
    """ A place to store the result"""
    for num in nums:
        if target == num:
            count=count+1
    
    return count

        
            
            
nums=[1,4,3,4,5,6,7]
target=4

print(manual_count(nums,target))
