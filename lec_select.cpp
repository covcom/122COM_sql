#include <iostream>
using namespace std;

#include "libsqlite.hpp"                    // sqlite library

int main()
{
    sqlite::sqlite db( "firefly.sqlite" );    // open database

    auto cur = db.get_statement();            // create query
    cur->set_sql( "SELECT * FROM staff;" );
    cur->prepare();                            // run query

    while( cur->step() )                    // loop over results
        cout << cur->get_int(0) << " " << cur->get_text(1) << endl;
}