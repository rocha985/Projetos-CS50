from cs50 import get_int

while True:
    height = get_int("Height: ")
    if 1 <= height <= 8:
        break

for line in range(height):
    for space in range(height - line - 1):
        print(" ", end="")
    for _ in range(line + 1):
        print("#", end="")
    print()
