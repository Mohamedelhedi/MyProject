#include <iostream>
#include <string.h>

using namespace std ;

class book
{
private :
    int book_id;
    string title;
    string author;
    int quantity ;
public :

    string get_title()
    {
      return title ;
    }
    string get_author()
    {
        return author;
    }
    void retirer_exemplaire()
    {
        quantity -- ;
    }

    void retour_exemplaire ()
    {
        quantity ++ ;
    }
    bool est_disponible()
    {
        return (quantity>0) ;
    }



} ;
