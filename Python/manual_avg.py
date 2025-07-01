def manual_avg(nums):
    l_count=len(nums) 
    """we can also create a manual count fuction"""
    m_sum=0
    if not nums:
        return None
    for num in nums:
        m_sum = m_sum+num
    return (m_sum/l_count)

nums=[5,6,7,8]
print(manual_avg(nums))