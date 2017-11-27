#include <stdio.h>
using namespace std;
 
long fibonacci( long n ); 
 
int main()
{
   long resultado; 
   long numero;     
  cout << "Hasta que numero quiere la secuancia?\n";
  cin >> numero;
  resultado = fibonacci( numero );
  cout << "El resultado es.." << Resultado << endl;
   
   return 0; 
 
}
 
long fibonacci( long n )
{
   if ( n == 0 || n == 1 ) 
   {
      return n;
   }
   else 
   { 
      return fibonacci( n - 1 ) + fibonacci( n - 2 );
   } 
   
}
