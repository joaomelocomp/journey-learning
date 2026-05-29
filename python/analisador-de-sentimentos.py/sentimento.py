from textblob import TextBlob

relato = input('how was your day? ')
analise = TextBlob(relato)
polaridade = analise.sentiment.polarity

if polaridade <= -0.5:
    print("y've such a bad day ;(")
elif -0.5 < polaridade < 0.5:
    print("nice day at all")
else:
    print("such a nice day! be happy :0")