# Python3 program for getting the minimum difference of sum of two subsets

def findMinRec(arr, i, sumCalculated, sumTotal):

    if (i == 0):
        return abs((sumTotal - sumCalculated) - sumCalculated)

    return min(findMinRec(arr, i - 1, sumCalculated+ arr[i - 1],sumTotal),
            findMinRec(arr, i - 1, sumCalculated, sumTotal))


def findMin(arr):
    sumTotal = sum(arr)
    
    return findMinRec(arr, len(arr), 0, sumTotal)

if __name__ == "__main__":
    arr = [7, 10, 12, 9, 5]  #Here, two subsets are [10, 12] and [7, 9, 5] so, the minimum difference is 1
    
    print("The minimum difference between two sets is", findMin(arr))

# Coded by Souvik Ghosh