import subprocess
import time

def checar_vs_code():
    saida = subprocess.check_output('tasklist').decode()
    if 'Code.exe' in saida:
        return True
    else:
        return False

def contar_vs_code():
    tempo_total = 0

    while True:

        if checar_vs_code():
            inicio = time.time()
            print('startvs')

            while checar_vs_code():
                time.sleep(1)

            fim = time.time()
            tempo_total += fim - inicio
            print('endvs')

        time.sleep(2)

        if tempo_total > 20:
            break

    return tempo_total

print(contar_vs_code())