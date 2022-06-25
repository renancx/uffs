ALT=float(input('Qual a altura do usuário? '))
PESO=float(input('Qual o peso do usuário? '))
IMC= PESO/(ALT**2)
if IMC<18.5:
   print("IMC:", IMC ,("(Abaixo do Peso)"))
if 24.9>IMC>18.5:
   print("IMC:", IMC ,("(Peso normal)"))
if 29.9>IMC>24.9:
   print("IMC:", IMC ,("(Sobrepeso)"))
if IMC>29.9:
   print("IMC:", IMC ,("(Obeso)"))