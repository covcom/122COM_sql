import sqlite3 as sql

con = sql.connect('firefly.sqlite')
cur = con.cursor()

cur.execute('''INSERT INTO staff (forename, surname)
               VALUES (?,?)''', ('River', 'Tam'))
con.commit()
con.close()