import random
import string
import pyperclip

alfa = list(string.ascii_lowercase)
spec = list(string.punctuation)
digi = list(string.digits)
senha = ""

finalPass = []

addChar = lambda lista:random.choice(lista)   #meu primeiro uso da função lambda

def sizes():
    sizeNum = int(input("Quantos numeros a sua senha deve conter: "))
    sizeSpecial = int(input("Quantos caracteres especiais a sua senha deve conter: "))
    while True:
        sizePass = int(input("O quão extensa a sua senha deve ser (em quantidade de caracteres): "))
        if sizePass >= sizeNum + sizeSpecial:
            break
        else:
            print("\nNão é possível fazer uma senha de {} caracteres se você quer {} números e caracteres especiais. Apenas não é possível!".format(sizePass, sizeNum + sizeSpecial))

    return [sizeNum,sizeSpecial,sizePass]

while True:
    try:
        tamanhos = sizes()
    except ValueError:
        print("\nEntendi que você quer letras na sua senha...\nMas eu perguntei a QUANTIDADE delas!")
    else:
        break

if capON := input("Letras Maiúsculas? (y/n): ").lower() == 'y':
    capON = True
else:
    capON = False

for j in range(tamanhos[0]): finalPass.append(addChar(digi))
for j in range(tamanhos[1]): finalPass.append(addChar(spec))

tamanhos[2] -= len(finalPass) + 1

while tamanhos[2] >= 0:
   finalPass.append(addChar(list(string.ascii_letters))) if capON else finalPass.append(addChar(alfa))
   tamanhos[2] -= 1

random.shuffle(finalPass)  #Ultima embaralhada, agora com as letras
print("A sua senha gerada é [automaticamente copiada para a área de transferência]: ", end="")
for i in finalPass:
    print(i,end="")   #Impressão da Senha
    senha += i

pyperclip.copy(senha)
input("")



