import random
import time

start = time.time()

ans = random.randint(1,100)
times = 0

while 1 :
    guess = input("Please input an integer number in range 1 ~ 100: ")
    if ans < int(guess):
        print("The number is to big")
        times += 1
    elif ans > int(guess):
        print("The number is to small")
        times += 1
    else :
        print("You guess right!\n")
        times += 1
        end = time.time()
        break

print("The time you spend is " + str(round(end-start,2)) + "\n")
print("The times you guess is " + str(times))

