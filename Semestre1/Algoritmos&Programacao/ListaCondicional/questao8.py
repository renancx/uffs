a=int(input('Qual a posição do competidor? '))
if 0<a<=5:
  print("Top 5")
if 5<a<=10:
  print("Top 10")
if 10<a<=20:
  print("Top 20")
if 20<a<=30:
  print("Top 30")
if a>30:
  print("Top 100")