import sys
import sqlite3 as sql

def main():
	sqliteFile = 'firefly.sqlite'

	try:
		con = sql.connect(sqliteFile)
		cur = con.cursor()

	except sql.Error as e:
		print("Error %s:" % e.args[0])

	finally:
		con.close()

if __name__ == '__main__':
	sys.exit(main())