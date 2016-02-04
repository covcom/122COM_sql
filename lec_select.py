import sqlite3 as sql

con = sql.connect('firefly.sqlite')
cur = con.cursor()

cur.execute('''SELECT * FROM staff;''')
for row in cur:
    print(row)
    
con.close()