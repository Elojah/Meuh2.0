def is_rectangle(r):
    for i in range(0, len(r)):
        for j in range(0, len(r[i])):
            if r[i][j]:
                print('x', end="")
            else:
                print('_', end="")
        print("")
    return (True)


def test():
    rectangles = [
        [1, 1, 3, 3],
        [3, 1, 4, 2],
        [3, 2, 4, 4],
        [1, 3, 2, 4],
        [2, 3, 3, 4]
    ]
    merged_rectangles = [
        [False, False, False, False, False],
        [False, False, False, False, False],
        [False, False, False, False, False],
        [False, False, False, False, False],
        [False, False, False, False, False],
    ]
    for r in rectangles:
        for i in range(r[0], r[2]):
            for j in range(r[1], r[3]):
                if merged_rectangles[i][j]:
                    return False
                merged_rectangles[i][j] = 1
    return (is_rectangle(merged_rectangles))


if __name__ == "__main__":
    if not test():
        print("Rectangles overlap")
