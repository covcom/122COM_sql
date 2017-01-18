#include <iostream>
#include <string>
using namespace std;

#include "libsqlite.hpp"

int main()
{
    try
    {
        sqlite::sqlite db( "pokedex.sqlite" );
        
        cout << "Find all the pokemon related to ______" << endl;

        string userInput;
        getline( cin, userInput );

        auto cur = db.get_statement();
        cur->set_sql( "SELECT a.identifier "
                      "FROM pokemon_species AS a "
                      "LEFT JOIN pokemon_species AS b "
                      "  ON a.evolution_chain_id = b.evolution_chain_id "
                      "WHERE b.identifier = LOWER(\"" + userInput + "\");" );
        cur->prepare();
    
        while( cur->step() )
            cout << cur->get_text(0) << ", ";
        cout << endl;
    }
    catch( sqlite:: exception e )
    {
        cerr << e.what() << endl;
        return 1;
    }

    return 0;
}