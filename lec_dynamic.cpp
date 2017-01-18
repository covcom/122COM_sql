#include <iostream>
#include <string>
#include "libsqlite.hpp"
using namespace std;

int main()
{
    sqlite::sqlite db( "firefly.sqlite" );

    string question;
    cout << "Who is the...";
    cin >> question;

    auto s = db.get_statement();
    s->set_sql( "SELECT forename, surname FROM staff "
                 "WHERE job = ?;" );
    s->prepare();
    s->bind( 1, question );

    while( s->step() )
    {
        string forename = s->get_text(0);
        string surname = s->get_text(1);
        cout << forename << " " << surname << endl;
    }

    return 0;
}