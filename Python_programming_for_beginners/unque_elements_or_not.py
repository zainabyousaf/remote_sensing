'''are all the elements in an array unique?'''
def isUnique(a):
    """it test uniqueness
    >>> isUnique([1,1])
    'list is not unique'
    >>> isUnique([1,2])
    'unique elements'
    """
    for i in range(len(a)-1):
        for j in range(i+1,len(a)):
            if a[i] == a[j]:
                return ("list is not unique")
    return "unique elements"
