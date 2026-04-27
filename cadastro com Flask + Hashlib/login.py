from flask import Flask, render_template, request
import hashlib

app = Flask(__name__)

def codificar(texto):
    hash_obj = hashlib.sha256(texto.encode('utf-8'))
    return hash_obj.hexdigest()

@app.route('/', methods=['POST', 'GET'])
def index():
    if request.method == 'POST':
        nome  = request.form.get('nome')
        email = request.form.get('email')
        senha = request.form.get('senha')

        print(nome, email, codificar(senha))
        
    return render_template('index.html')

if __name__ == '__main__':
    app.run(debug=True)
