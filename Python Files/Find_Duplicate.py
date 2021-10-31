
import sys
def duplicateNumber(arr, size) :
    for i in range(size - 1) :
        for j in range((i + 1), size) :
            if arr[i] == arr[j] :
                return arr[i] 
def takeInput() :
    n = int(input()) 
    if n == 0 :
        return list(), 0
    arr = list(map(int, input().strip().split())) 
    return arr, n
t = int(input()) 
while t > 0 :
    arr, n = takeInput()
    print(duplicateNumber(arr, n))
    
    t -= 1
