#include <iostream>
#include <string>
using namespace std;

#include "libsqlite.hpp"

int main()
{
    string sqliteFile = "pokedex.sqlite";

    try
    {
        sqlite::sqlite db( sqliteFile );
        auto cur = db.get_statement(); 

        cout << "Which generation do you want to ask about? ";
        
        int gen;
        cin >> gen;

        cur->set_sql( "select count(*) "
                      "from pokemon_species "
                      "where generation_id = ?" );
        cur->prepare();
        cur->bind( 1, gen );
        cur->step();

        int count = cur->get_int(0);

        cout << "There are " << count << " generation " << gen << " pokemon." << endl;
    }
    catch( sqlite::exception e )      // catch all sql issues
    {
        std::cerr << e.what() << std::endl;
        return 1;
    }

    return 0;
}