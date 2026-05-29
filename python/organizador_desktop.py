import os
import shutil
import customtkinter as ctk

janela = ctk.CTk()
janela.title("Organizador")
janela.geometry('100x100')

user = os.environ.get("USERNAME")

desktop = "c:\\Users\\melo\\Desktop"
destino = "C:\\Users\\melo\\Desktop\\Arquivos e Programas 4.0\\tava no desktop"

fixados = [
    'Adobe After Effects 2023.lnk', 
    'Adobe Premiere Pro 2023.lnk', 
    'Arquivos e Programas 4.0', 
    'desktop.ini', 
    'Discord.lnk', 
    'Opera GX Browser.lnk', 
    'PSCS6.lnk', 
    'Visual Studio Code.lnk'
]

def botao():
    for arquivos in os.listdir(desktop):
        if arquivos not in fixados:
            origem = os.path.join(desktop, arquivos)
            destino_final = os.path.join(destino, arquivos)

            shutil.move(origem, destino_final)

apertar = ctk.CTkButton(janela, text="Organizar Desktop", command=botao)
apertar.pack(pady=35)

janela.mainloop()
