tam = int(input("Tamanho da lista: "))
valores = []
for c in range(tam):
    num = int(input("Escreva os valores: "))
    valores.append(num)
rem = int(input("Posição a ser removida: "))
for c, v in enumerate(valores):
    if c == rem:
        valores.remove(v)
print(f"Novo vetor: {valores}")
print(f"Novo tamanho do vetor: {len(valores)}")
