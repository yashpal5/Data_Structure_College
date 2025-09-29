# Q1 Fibonacci series up to n terms
n = int(input("Enter the number of terms: "))

t1, t2 = 0, 1
print("Fibonacci Series:", t1, ",", t2, end="")

for i in range(3, n+1):
    next_term = t1 + t2
    print(",", next_term, end="")
    t1, t2 = t2, next_term


# Q2 reverse a string through recursion
def reverse_string(s):
    # Base condition: If the string has length 0 or 1, return it as is
    if len(s) <= 1:
        return s
    # Recursive case: last character + reverse of remaining string
    return s[-1] + reverse_string(s[:-1])

string = "hello"
print("Original String:", string)
print("Reversed String:", reverse_string(string))


# Q3 delete operation on an array
n = int(input("Enter number of elements: "))

arr = []
print("Enter the elements:")
for i in range(n):
    arr.append(int(input()))

print("Original array:", arr)

pos = int(input("Enter position to delete: "))

if pos < 0 or pos >= len(arr):
    print("Invalid position!")
else:
    arr.pop(pos)
    print("Array after deletion:", arr)
    

