from selenium import webdriver
from selenium.webdriver.common.by import By

def abrir_redes():
    abrir = webdriver.Chrome()

    abrir.get("https://br.linkedin.com")
    abrir.switch_to.new_window('tab')
    abrir.get("https://www.google.com/url?sa=t&rct=j&q=&esrc=s&source=web&cd=&cad=rja&uact=8&ved=2ahUKEwihyvasnqCUAxWtLLkGHQrhGKYQFnoECAsQAQ&url=https%3A%2F%2Fdocs.google.com%2F%3Fhl%3Dpt-BR&usg=AOvVaw2bnOdk693A7k50KTe1yVDN&opi=89978449")
    abrir.switch_to.new_window('tab')
    abrir.get("https://chatgpt.com")

    barra = abrir.find_element(By.TAG_NAME, "textarea")
    barra.send_keys("Vagas em T.I. no dia de hoje!")

    input('Pressione qualquer botão para fechar. ')

    abrir.quit()

abrir_redes()
