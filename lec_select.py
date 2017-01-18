import sqlite3 as sql                         # sqlite module

con = sql.connect( 'firefly.sqlite' )        # open database
cur = con.cursor()                        

cur.execute( '''SELECT * FROM staff;''' )    # run query
for row in cur:                                # loop over results
    print( row )
    
con.close()                                    # close database