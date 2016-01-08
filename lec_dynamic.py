import sqlite3 as sql

con = sql.connect('firefly.sqlite')
cur = con.cursor()

question = input('Who is the...')

cur.execute('''SELECT forename, surname FROM staff 
               WHERE job = ?;''', (question,))

for row in cur:
    print('%s %s' % row)	