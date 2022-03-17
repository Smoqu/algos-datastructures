def binary_search(l: list, value: int):
    length = len(l)

    start = 0
    end = length - 1

    while (start <= end):
        middle = (start+end)//2

        if l[middle] == value:
            return True

        if l[middle] < value:
            start = middle + 1
        else:
            end = middle - 1

    return False


def binary_search_r(l: list, value: int):
    length = len(l)
    middle = length // 2

    if l[middle] == value:
        return True
    if length == 1:
        return False

    if l[middle] > value:
        return binary_search_r(l[:middle], value)
    elif l[middle] < value:
        return binary_search_r(l[middle:], value)


l = [1, 2, 56, 89, 256, 300, 700]
print(binary_search_r(l, 89))
print(binary_search_r(l, 6))
print(binary_search(l, 89))
print(binary_search(l, 6))
