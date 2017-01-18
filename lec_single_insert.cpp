#include <iostream>
using namespace std;

#include "libsqlite.hpp"    

int main()
{
    sqlite::sqlite db( "firefly.sqlite" );    // open database

    auto cur = db.get_statement();            // create query
    cur->set_sql( "INSERT INTO staff (forename, surname) "
                  "VALUES (?,?);" );
    cur->prepare();

    cur->bind( 1, "River" );                // set placeholders
    cur->bind( 2, "Tam" );
    cur->step();                            // run query
}