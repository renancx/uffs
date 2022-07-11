def a():
  b = []
  i = 0
  while i < 5:
    b.append(input('Digite o número '))
    i += 1

  b.sort()
  print(*b, sep=', ')

a()