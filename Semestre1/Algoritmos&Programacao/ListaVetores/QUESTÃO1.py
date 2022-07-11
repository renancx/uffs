listaA = []
listaB = []
for c in range(10):
    A = int(input("Escreva os valores: "))
    listaA.append(A)
for c in range(10):
    B = int(input("Escreva os valores: "))
    listaB.append(B)
x = int(input("Valor: "))
for p, v in enumerate(listaA):
    if v == x:
        posi = p
        print("Posição: ", p)
for p, v in enumerate(listaB):
    if p == posi:
        print("Elemento: ", v)
