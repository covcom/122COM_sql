#include <iostream>
using namespace std;

#include "libsqlite.hpp"

int main()
{
    try
    {
        sqlite::sqlite db( "firefly.sqlite" );

        auto cur = db.get_statement();

    }
    catch( sqlite::exception e )
    {
        cerr << e.what() << endl;
        return 1;
    }

    return 0;
}