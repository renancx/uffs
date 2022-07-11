def primogemeo():
    primos = []
    for c in range(1, 1001):
        soma = 0
        for i in range(1, c):
            if c % i == 0:
                soma += i
        if soma <= 2:
            primos.append(c)
    gemeos = []
    for c in primos:
        a = (6 * c + 1)
        b = (6 * c - 1)
        if a - b == 2:
            gemeos.append(b)
            gemeos.append(a)
    del gemeos[78:]
    print(f"Os números primos gêmeos são: {gemeos}")


primogemeo()