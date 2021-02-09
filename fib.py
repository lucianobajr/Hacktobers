from concurrent.futures import ThreadPoolExecutor, as_completed
import random
def fibonacci(n):
    first_value, second_value = 0, 1
    for i in range(0, n):
        first_value, second_value = second_value, first_value + second_value
    return ((n, first_value))


print("Input the  vector size of random numbers ") 
size = int(input(""))
numeros = []
for i in range(0,size): 
    aux = random.seed(10) 
    numeros.append(aux)


with ThreadPoolExecutor(max_workers=5) as executor:
    fibSubmit = {executor.submit(fibonacci, n,): n for n in numeros}

    for future in as_completed(fibSubmit):
        try:
            n, f = future.result()
        except Exception as exc:
            print("Erro! {0}".format(exc))
        else:
            print ("{0}: {1}".format(n, f))
