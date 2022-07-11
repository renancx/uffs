valores = []
tam = int(input("Tamanho da lista: "))
for c in range(tam):
    num = int(input("Escreva os valores: "))
    valores.append(num)
par = []
impar = []
for c in valores:
    if c % 2 == 0:
        par.append(c)
    else:
        impar.append(c)
print(f"Pares: {par}")
print(f"Ìmpares: {impar}")
