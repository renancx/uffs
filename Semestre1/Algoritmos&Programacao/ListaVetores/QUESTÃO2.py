listaA = []
listaB = []
cont = 0
for c in range(10):
    val = int(input("Valores: "))
    listaA.append(val)
    if c >= 5:
        listaB.append(val)
num = []
for c in range(5):
    soma = listaA[c] + listaB[c]
    num.append(soma)
print(f"SOMA = {num}")
