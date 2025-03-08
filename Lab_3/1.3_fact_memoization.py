import time

table = {}

def factorial(num):
    if num == 0 or num == 1:
        return 1
    else:
        if num not in table:
            table[num] = num*factorial(num-1)
        return table[num]
    
num = int(input("Enter the value: "))
t1 = time.time()
result = factorial(num)
t2 = time.time()
print(f"The {num}th term is {result}")
print(f"Time taken : {t2-t1} second.s")