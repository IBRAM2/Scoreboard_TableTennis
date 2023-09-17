import random, os

corpus = """
Julio
Alex
Lamberto
Emmanuel
Daniela
Ernesto
Hector
Villa
Ivan
Luis
Ulises
Eric
Ismael
"""

corpus = [sentence for sentence in corpus.split('\n') if sentence != '']
corpus = list(set(corpus))
random.shuffle(corpus)

# Add a random name different from the last one if the number of names is odd
if len(corpus) % 2 != 0:
    last = corpus[-1]
    new = random.choice(corpus)
    while new == last:
        new = random.choice(corpus)
    corpus.append(random.choice(corpus))   

path = 'playoffs/bracket.drawio'
path_full = 'playoffs/bracket_full.drawio'

if os.path.exists(path_full):
    os.remove(path_full)
    
with open(path, 'r') as original_file:
    with open(path_full, 'w') as copy_file:
        copy_file.write(original_file.read())

# Set the bracket
with open('playoffs/bracket_full.drawio', 'r+') as f:
    contenido = f.read()
    
    for player in corpus:
        contenido = contenido.replace('???', player, 1)
    
    f.seek(0)
    f.write(contenido)