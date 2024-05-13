from cs50 import get_float

while True:
    cash = get_float("change: ")
    cents = round(cash * 100)
    if cents >= 1:
        break

quarters = 0
while cents >= 25:
    quarters += 1
    cents -= 25

dimes = 0
while cents >= 10:
    dimes += 1
    cents -= 10

nickels = 0
while cents >= 5:
    nickels += 1
    cents -= 5

pennies = 0
while cents >= 1:
    pennies += 1
    cents -= 1


print(quarters + dimes + nickels + pennies)
