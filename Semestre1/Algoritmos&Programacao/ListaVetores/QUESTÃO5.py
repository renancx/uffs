valores = []
tam = int(input("Tamanho da lista: "))
for c in range(tam):
    num = int(input("Escreva os valores: "))
    valores.append(num)
repetidos = []
soma = 0
skip = 0
for c in valores:
    quanti = valores.count(c)
    if c in repetidos:
        skip += 1
    elif quanti > 1:
        repetidos.append(c)
        soma += 1
print(f"Números de elementos duplicados: {soma}")
print(f"Números: {repetidos}")

