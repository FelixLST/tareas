#include <iostream>
#include <string.h>

using namespace std;

int Buscar(char Texto[200], char palabra[20]);

int main()
{
	int pos;
	char palabra[20],Texto[200]={"The study accepted for publication in the Astrophysical Journal looked at star HD135344B which is located 350 light years from Earth The system has caught the astronomers attention because it sports striking spiral features likely caused by forming gas giant planets ike Jupiter In 2015 observations were performed to better characterize the system and astronomers spotted this shadow The following year to get a better understanding the team used the SPHERE instrument  "};
	cout << "Este programa busca una palabra en el sig texto\n";
	cout << Texto;
	cout << " ingrese la pabra a buscar\n";
	cin >> palabra;

	pos=Buscar(Texto,palabra);

	if(pos==-1)
	{
		cout << "La palabra buscada no existe\n";
	}
	else
	{
		cout << "La palabra comiensa en la posicion " << pos << endl;
	}
}
int Buscar(char Texto[200], char palabra[20])
{
	int j=0;
    for(int i = 0; i < strlen(Texto); i++)
    {
        if(palabra[j] == Texto[i])
        {
            ++j;
            if(j == strlen(palabra))
                return (2 + i-j);
        }
 
        else j = 0;
    }
    return -1;
}
