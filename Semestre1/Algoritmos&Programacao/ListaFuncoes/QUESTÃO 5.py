def perfeito(num):
    soma = 0
    for val in range(1, num):
        if num % val == 0:
            soma += val
    if soma == num:
        print("1, é perfeito")
    else:
        print("0, não é perfeito")


num = int(input("Digite o número: "))
perfeito(num)
