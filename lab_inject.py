import sys
import sqlite3 as sql

def main():
	sqliteFile = 'pokedex.sqlite'

	try:
		con = sql.connect(sqliteFile)
		cur = con.cursor()

		print('Find all the pokemon related to ______')
		userInput = input('>')

		cur.execute('''SELECT a.identifier
						FROM pokemon_species AS a
						LEFT JOIN pokemon_species AS b
    						ON a.evolution_chain_id = b.evolution_chain_id
						WHERE b.identifier = LOWER("%s");''' % userInput )

		for name, in cur:
			print(name, end=', ')
		print()

	except TypeError:
		print('Couldn\'t find %s in database' % userInput)      

	except sql.Error as e:
		print("Error %s:" % e.args[0])

	finally:
		if con:
			con.close()

if __name__ == '__main__':
	sys.exit(main())