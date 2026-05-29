import os
import shutil
import customtkinter as ctk
from tkinter import filedialog

def escolher_pasta():
    caminho = filedialog.askdirectory()
    typepath.delete(0, "end")
    typepath.insert(0, caminho)

formatos = {
    "images": [
    ".jpg",
    ".jpeg",
    ".png",
    ".gif",
    ".bmp",
    ".tiff",
    ".tif",
    ".webp",
    ".svg",
    ".ico",
    ".heic",
    ".heif",
    ".raw",
    ".cr2",
    ".nef",
    ".arw",
    ".dng",
    ".psd",
    ".ai",
    ".eps",
    ".jfif",
],
    "audio": [
    ".mp3",
    ".wav",
    ".aac",
    ".flac",
    ".ogg",
    ".wma",
    ".m4a",
    ".alac",
    ".aiff",
    ".opus",
    ".amr",
    ".mid",
    ".midi",
    ".ra",
    ".ape",
    ".dsd",
    ".pcm",
],
    "pdf and texts": [
        ".pdf",
        ".xps",
        ".oxps",
        ".txt",
    ],

}

janela = ctk.CTk()
janela.title('Organizador')
janela.geometry('400x200')

def organizar():

    origem = typepath.get()

    if not os.path.exists(origem):
        botao_label.configure(text='Diretorio não encontrado!', text_color='red')
        janela.after(3000, lambda: botao_label.configure(text=""))
        return

    for arquivo in os.listdir(origem):
        caminho_arquivo = os.path.join(origem, arquivo)
        
        if os.path.isfile(caminho_arquivo):
            nome, extensao = os.path.splitext(arquivo)

            if extensao in formatos['images']:
                pasta_destino = os.path.join(origem, "images") #na pasta(origem) criar a pasta imagens
                os.makedirs(pasta_destino, exist_ok=True)

                destino_final = os.path.join(pasta_destino, arquivo)
                shutil.move(caminho_arquivo, destino_final)
            
            elif extensao in formatos['audio']:
                pasta_audio = os.path.join(origem, 'audio')
                os.makedirs(pasta_audio, exist_ok=True)

                caminho_destino = os.path.join(pasta_audio, arquivo)
                shutil.move(caminho_arquivo, caminho_destino)
            
            elif extensao in formatos['pdf and texts']:
                pasta_text = os.path.join(origem, 'pdf and texts')
                os.makedirs(pasta_text, exist_ok=True)

                caminho_destino2 = os.path.join(pasta_text, arquivo)
                shutil.move(caminho_arquivo, caminho_destino2)

            else:
                others_dir = os.path.join(origem, 'others')
                os.makedirs(others_dir, exist_ok=True)

                others_path = os.path.join(others_dir, arquivo)
                shutil.move(caminho_arquivo, others_path)
    
    botao_label.configure(text='Sua pasta foi organizada!', text_color='green')
    janela.after(3000, lambda: botao_label.configure(text=""))

typepath = ctk.CTkEntry(janela, placeholder_text="Digite o caminho até o diretorio", width=250)
typepath.pack(pady=5)

frame = ctk.CTkFrame(janela, fg_color="transparent")
frame.pack()
frame.pack_propagate(True)

botao = ctk.CTkButton(frame, text="Selecionar pasta", command=escolher_pasta)
botao.pack(pady=10)

botao2 = ctk.CTkButton(frame, text="Organizar pasta", command=organizar)
botao2.pack(pady=10)

botao_label = ctk.CTkLabel(frame, text="", text_color="red")
botao_label.pack(side="left", padx=5)

janela.mainloop()
