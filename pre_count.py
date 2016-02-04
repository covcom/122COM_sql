import sys
import sqlite3 as sql

def main():
    sqliteFile = 'pokedex.sqlite'

    try:
        con = sql.connect(sqliteFile)
        cur = con.cursor()

        print('Which generation do you want to ask about?')
        gen = int(input('>'))

        cur.execute('''select count(*) 
                       from pokemon_species
                       where generation_id = ?''', (gen,))
        count = int(cur.fetchone()[0])

        print('There are %d generation %d pokemon.' % (count,gen))

    except ValueError:
        print('Generation must be an integer')

    except sql.Error as e:
        print("Error %s:" % e.args[0])

    finally:
        con.close()

if __name__ == '__main__':
    sys.exit(main())