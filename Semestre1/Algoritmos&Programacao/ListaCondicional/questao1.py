a = int(input("Numero de horas trabalhadas: "))
b = float(input("Valor da hora trabalhada: "))
c = (a*b)
if a>200: 
  print(f"O salario foi de R${c*105/100}")
if a<=200:
  print(f"O salario foi de R${c*105/100}")