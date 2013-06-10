#include <vector>
using namespace std;

class IntegerSet 
{
public:
   static const int setSize = 101;

 
   IntegerSet() 
      : set( setSize )
   { 
   } 

   IntegerSet( int [], int ); 
   IntegerSet unionOfSets( const IntegerSet& ) const;
   IntegerSet intersectionOfSets( const IntegerSet& ) const;
   void inputSet(); 
   void insertElement( int );
   void deleteElement( int );
   void printSet() const;
   bool isEqualTo( const IntegerSet& ) const;
private:
   vector< bool > set; 

   
   int validEntry( int x ) const 
   { 
      return ( x >= 0 && x < setSize );
   }
};