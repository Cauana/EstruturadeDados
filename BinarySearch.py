
def searchInsert( nums, target):
        inicio = 0
        fim = len(nums)-1

        while inicio <= fim:
            meio = (inicio +fim) // 2
            if target == nums[meio]:
                return meio
            elif target < nums[meio]:
                    fim = meio -1
            else:
                inicio = meio + 1
        return inicio
                    



lst =[2,4,5,6,7,8]
print(searchInsert(lst, 3))
