y=int(input('Valor decimal para ser convertido: '))
x=y
L=[]
while (y>0):
    a=int(float(y%2))
    L.append(a)
    y=(y-a)/2
string=""
for j in L[::-1]:
    string=string+str(j)
string.split()
if len(string)<4:
   for i in range (4-len(string)):
      string= "0"+ string
   a,b,c,d=(string)
else:
   a,b,c,d=(string)
if a=='0':          
  q1=0
elif a=='1':
  q1=1
if b!=a:
  q2=1
else:
  q2=0
if c!=b:
  q3=1
else:
  q3=0
if d!=c:
  q4=1
else:
  q4=0
print(q1, q2, q3, q4)