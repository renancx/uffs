valores = []
cont = ""
while True:
    num = int(input("Digite um valor: "))
    valores.append(num)
    cont = str(input("Quer continuar? (S/N)")).strip().upper()[0]
    if cont == "N":
        break
menor = valores[0]
maior = valores[0]
for c in valores:
    if c < menor:
        menor = c
    if c > maior:
        maior = c
print(f"Valor Máximo: {maior}")
print(f"Valor Mínimo: {menor}")