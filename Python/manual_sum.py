def manual_sum(nums):
    m_sum=0
    if not nums:
        return None
    for num in nums:
        m_sum = m_sum+num
    return m_sum

nums=[234,34,3,5,5,6,7,8]
print(manual_sum(nums))