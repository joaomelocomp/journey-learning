from flask import Flask

app = Flask(__name__)

@app.route('/soma/<x>/<y>')
def soma(x, y):

    return str(int(x) + int(y))

if __name__=='__main__':
    app.run(debug=True)