def merge(l: list, r: list) -> list:
    result = []
    ll = 0
    lr = 0

    while ll < len(l) and lr < len(r):
        if l[ll] < r[lr]:
            result.append(l[ll])
            ll += 1
        else:
            result.append(r[lr])
            lr += 1

    result += l[ll:]
    result += r[lr:]

    return result


def mergesort(a: list):
    print(a)
    length = len(a)
    middle = length // 2

    if length == 1:
        return a

    left = mergesort(a[:middle])
    right = mergesort(a[middle:])

    return merge(left, right)


print(mergesort([-1, -128, 256, 2, 5, 1, 0, 7]))
