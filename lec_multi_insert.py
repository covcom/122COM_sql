import sqlite3 as sql

con = sql.connect('firefly.sqlite')
cur = con.cursor()

people = [('Simon','Tam','Doctor'), ('River','Tam',None)]

cur.executemany('''INSERT INTO staff (forename, surname, job)
                   VALUES (?,?,?)''', people)

cur.commit()
con.close()