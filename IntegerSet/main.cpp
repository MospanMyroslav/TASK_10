#include <iostream> 
#include <stdlib.h>
#include "IntegerSet.h" 
using namespace std;

int main()
{
   IntegerSet a;
   IntegerSet b;
   IntegerSet c;
   IntegerSet d;
   setlocale(LC_ALL,"Russian");
   cout << "Введіть набор A:\n";
   a.inputSet();
   cout << "\nВведіть набор B:\n";
   b.inputSet();
   c = a.unionOfSets( b );
   d = a.intersectionOfSets( b );
   cout << "\nСоюз A и B is:\n";
   c.printSet();
   cout << "Пересечения A и B: \n";
   d.printSet();

   if ( a.isEqualTo( b ) )
      cout << "Set A равна множеству B\n";
   else
      cout << "Set A не равно множеству B\n";

   cout << "\nВставка в 77 установка...\n";
   a.insertElement( 77 );
   cout << "Установить сейчас A:\n";
   a.printSet();

   cout << "\nУдаление 77 от установить...\n";
   a.deleteElement( 77 );
   cout << "Установить сейчас A:\n";
   a.printSet();

   const int arraySize = 10;
   int intArray[ arraySize ] = { 25, 67, 2, 9, 99, 105, 45, -5, 100, 1 };
   IntegerSet e( intArray, arraySize );

   cout << "\nУстановить сейчас E:\n";
   e.printSet();

   cout << endl;
   system("pause");
}