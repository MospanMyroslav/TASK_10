#include <iostream> 
#include <iomanip> 
#include "IntegerSet.h" 
using namespace std;


IntegerSet::IntegerSet( int array[], int size )
   : set( setSize )
{
   for ( int i = 0; i < size; i++ )
      insertElement( array[ i ] );
} 


void IntegerSet::inputSet()
{
   int number;

   do 
   {
      cout << "Введите элемент (-1 to end): ";
      cin >> number;

      if ( validEntry( number ) )
         set[ number ] = true;
      else if ( number != -1 )
         cerr << "Недопустимый Элемент\n";
   } while ( number != -1 ); 

   cout << "Полная запись\n";
} 


void IntegerSet::printSet() const
{
   int x = 1;
   bool empty = true; 
   
   cout << '{';

   for ( int i = 0; i < setSize; i++ )
   {
      if ( set[ i ] ) 
      {
         cout << setw( 4 ) << i << ( x % 10 == 0 ? "\n" : "" );
         empty = false; 
         x++;
      } 
   } 

   if ( empty )
      cout << setw( 4 ) << "---"; 
		
   cout << setw( 4 ) << "}" << '\n';
} 
IntegerSet IntegerSet::unionOfSets( const IntegerSet &r ) const
{
   IntegerSet temp;

   
   for ( int i = 0; i < setSize; i++ )
      temp.set[ i ] = set[ i ] || r.set[ i ];

   return temp;
} 


IntegerSet IntegerSet::intersectionOfSets( const IntegerSet &r ) const
{
   IntegerSet temp;

  
   for ( int i = 0; i < setSize; i++ )
      temp.set[ i ] = set[ i ] && r.set[ i ];

   return temp;
} 


void IntegerSet::insertElement( int k )
{
   if ( validEntry( k ) )
      set[ k ] = true;
   else
      cerr << "Недопустимые попытки вставить!\n";
} 


void IntegerSet::deleteElement( int k )
{
   if ( validEntry( k ) )
      set[ k ] = false;
   else
      cerr << "Поврежденных попытка удалить!\n";
} 


bool IntegerSet::isEqualTo( const IntegerSet &r ) const
{
   for ( int i = 0; i < setSize; i++ )
      if ( set[ i ] != r.set[ i ] )
         return false; 

   return true; 
}