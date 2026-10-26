import requests
from bs4 import BeautifulSoup
from selenium import webdriver
import undetected_chromedriver as uc
from selenium.webdriver.common.by import By
from selenium.webdriver.common.keys import Keys
import time, random

def etapa_um():
    abrir = uc.Chrome(version_main=155)
    time.sleep(random.uniform(1.0, 3.0))

    try:
        abrir.get("https://www.mercadolivre.com.br")

        pesquisa = abrir.find_element(By.CLASS_NAME, "nav-search-input")

        time.sleep(random.uniform(1.0, 3.0))

        pesquisa.send_keys("Rash Guard Jiu Jitsu" + Keys.ENTER)

        link_novo = abrir.current_url

        time.sleep(5)
        return link_novo
    finally:
        abrir.quit()

def etapa_dois():
    link = etapa_um()
    pagina = requests.get(link)

    conteudo = BeautifulSoup(pagina.text, "html.parser")

    precos = conteudo.find(class_="poly-component__price")

    print(precos)

etapa_dois()