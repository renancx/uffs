a=int(input("Qual a idade do eleitor? "))
if a<16:
  print("Não pode votar")
if 18<=a<70:
  print("Voto obrigatório")
if 16<=a<18:
  print("Voto facultativo")