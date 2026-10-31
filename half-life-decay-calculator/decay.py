#Programa feito sem o uso de qualquer IA!!!

def main():
    m0 = float(input("Digite a massa inicial estimada (g):  "))
    m_current = float(input("Digite a massa final (g): "))
    half_life = float(input("Digite a meia-vida (anos): "))

    if m_current <= 0 or m0 <= 0 or m_current > m0:
        print("Input inválido: a massa atual deve ser menor ou igual à massa inicial estimada, e positiva.")
        return

    iterations = 0
    mass = m0

    while mass > m_current:
        mass = mass / 2
        iterations += 1

    lower = (iterations - 1) * half_life
    upper = iterations * half_life

    print(f"\nEstimo que a idade procurada está entre {lower:.0f} e {upper:.0f} anos.")

# Executa o programa diretamente
main()
