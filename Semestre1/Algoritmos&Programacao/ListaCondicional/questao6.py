a=int(input('Qual a hora de início do evento? '))
b=int(input('Qual a hora do fim do evento? '))
if b<a:
  print("O evento durou",(b+24)-a, "horas")
if b>a:
  print("O evento durou",b-a, "horas")
