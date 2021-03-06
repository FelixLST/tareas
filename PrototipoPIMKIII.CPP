#include <iostream>
#include <fstream>
#include <string.h>

using namespace std;
int Menu();
void Moda(int NumPregun,int Contador[10]); //Regresa la moda de la preguntra dada
void ModaImp(int NumPregun,int Contador[10]); //Regresa la moda de la preguntra dada para imprimir en archivo
void ContadorF(int NumPregun,int Contador[10],char Respuestas[][73]); //Cuenta las respuestra de la pregunta dada y da la frecuencia de cada una
void FrecuenciaRelativaYAcum(int NumPregun,int Contador[10]); //Regresa la fecuencia relativa y acumulada de los resultados de la pregunta dada
void FrecuenciaRelativaYAcumImp(int NumPregun,int Contador[10]); //Regresa la fecuencia relativa y acumulada de los resultados de la pregunta dada para imprimir en archivo
void LectorPrincipal(char Respuestas[][73]); //Lee todo el archivo de exel-Felix
void ImpresorExelDatos(int Contador[10], char Respuestas[][73]);// Crea un archivo con los datos del resumen-Felix


int main()
{
    ifstream arch("c:\\datos\\PIBaseDeDatos.txt",ios::in);
    int op;
	do
	{
		int NumPregun=0,res=0;
        char Respuestas[365][73];
        int Contador[10]={0};
		op=Menu();
		if(op==1)
		{
			cout << "De que Pregunta desea saber la moda?\n";
			cin >> NumPregun;
			ContadorF(NumPregun,Contador,Respuestas);
			Moda(NumPregun,Contador);
			cout << endl;
			cout << "Desea guardar las respuestas en un archivo de exel?,precione 1 para si y 2 para no\n";
			cin >> res;
			if(res==1)
			{
				 ModaImp(NumPregun,Contador);
			}
		}
		else if(op==2)
		{
			cout << "De que pregunta desea saber la frecuencia,relativa y acumulada \n";
			cin >> NumPregun;
			FrecuenciaRelativaYAcum(NumPregun,Contador);
			cout << endl;
			cout << "Desea guardar las respuestas en un archivo de exel?,precione 1 para si y 2 para no\n";
			cin >> res;
			if(res==1)
			{
				FrecuenciaRelativaYAcumImp(NumPregun,Contador);
			}
		}
		else if(op==3)
			{
				ImpresorExelDatos(Contador,Respuestas);
				cout << "los archivos se an guardado en un archivo con el nombre ResultadoDeEncuenstas en formato .csv\n ";
			}
	}while(op!=0);
}
int Menu()
{
	int op;
	cout << "Bienvenido a la calculadora Estadistica MKIII\n";
	cout << "Selecione una de las opciones de la acciones a relaisar tecleando un numero su elecion y precione 0 para salir(Recuerde tener el archivo guardado en la carpeta datos del disco duro C:)\n";
	cout << "Para Obtener la moda de alguna pregunta preicone 1\n";
	cout << "Para Obtener las frecuenncias,relativas y acumuladas de las respuestas de una preguntra precione 2\n";
	cout << "Para imprimir un resumen total de todo precione 3\n";
	cin >> op;

	return op;
}
void ImpresorExelDatos(int Contador[10], char Respuestas[][73])//Imprimi un resumen general en un archivo .csv
{



		ofstream arch("c:\\datos\\ResultadoDeEncuenstas.csv",ios::out);
		cout<<"Este es un resumen general de toda la encuesta\n";
		arch<<endl;
		arch<<endl;
		for(int c=0; c<20; c++)
		{
			arch<<"Los resultados de la pregunta " << c << " Son" << endl;
			arch<<"Moda" << endl;
			ModaImp(c,Contador);
			arch<<"Frecuencia relativa y acumulada "<<endl;
			FrecuenciaRelativaYAcumImp(c,Contador);
		}
		arch.close();
}

void LectorPrincipal(char Respuestas[][73])//Leer todo el archivo asilado (incluido en el pack)
{
	ifstream arch("c:\\datos\\PIBaseDeDatos.txt",ios::in);
	for(int c=0; c<73; c++)
	{
		for(int k=0; k<365; k++)
		{
			arch>>Respuestas[k][c];
		}
	}
	arch.close();

}
void ContadorF(int NumPregun,int Contador[10],char Respuestas[][73])//Llenar el vector para poder manipularlo mas adelante con exepciones y posiciones
{
	if(NumPregun==1)
	{
		for(int i=0; i<8; i++)
		{
			for(int k=0; k<365; k++)
			{
				Contador[(Respuestas[k][i])-97]++;
			}
		}
	}
	else if(NumPregun==3)
	{
		for(int p=9; p<12; p++)
		{
			for(int t=0;t<365;t++)
			{
				Contador[(Respuestas[t][p])-97]++;
			}
		}
	}
	else if(NumPregun==4)
	{
		for(int z=13; z<17; z++)
		{
			for(int g=0; g<365;z++)
			{
				Contador[(Respuestas[g][z])-97]++;
			}
		}
	}
	else if(NumPregun==6)
	{
		for(int i=15; i<21; i++)
		{
			for(int k=0; k<365;k++)
			{
				Contador[(Respuestas[k][i])-97]++;
			}
		}
	}
	else if(NumPregun==7)
	{
		for(int i=22; i<31; i++)
		{
			for(int k=0; k<365;k++)
			{
				Contador[(Respuestas[k][i])-49]++;
			}
		}
	}
	else if(NumPregun==11)
	{
		for(int i=35; i<42;i++)
		{
			for(int k=0; k<365;k++)
			{
				Contador[(Respuestas[k][i])-97]++;
			}
		}
	}
	else if(NumPregun==12)
	{
		for(int i=43; i<47; i++)
		{
			for (int k=0; i <365;i++)
			{
				Contador[(Respuestas[k][i])-97]++;
			}
		}
	}
	else  if(NumPregun==13)
	{
		for(int i=47; i<50;i++)
		{
			for(int k=0; k<365;k++)
			{
				Contador[(Respuestas[k][i])-49]++;
			}
		}
	}
	else if(NumPregun==14)
	{
		for(int i=50; i<56;i++)
		{
			for(int k=0;k<365;k++)
			{
				Contador[(Respuestas[k][i])-97]++;
			}
		}
	}
	else if(NumPregun==15)
	{
		for(int i=56; i<58;i++)
		{
			for(int k=0;k<365;k++)
			{
				Contador[(Respuestas[k][i])-97]++;
			}
		}
	}
	else if(NumPregun==17)
	{
		for(int i=60;i<69;i++)
		{
			for(int k=0;k<365;k++)
			{
				Contador[(Respuestas[k][i])-49]++;
			}
		}
	}
	else if(NumPregun==20)
	{
		for(int i=0; i<365;i++)
		{
			Contador[(Respuestas[i][73])-49]++;
		}
	}
	else if(NumPregun==2)
	{
		for(int i=0; i<365;i++)
		{
			Contador[(Respuestas[i][8])-97]++;
		}
	}
	else if(NumPregun==5)
	{
		for(int i=0; i<365;i++)
		{
			Contador[(Respuestas[i][17])-97]++;
		}
	}
	else if(NumPregun==8)
	{
		for(int i=0; i<365;i++)
		{
			Contador[(Respuestas[i][31])-97]++;
		}
	}
	else if(NumPregun==9)
	{
		for(int i=0; i<365;i++)
		{
			Contador[(Respuestas[i][32])-97]++;
		}
	}
	else if(NumPregun==10)
	{
		for(int i=0; i<365;i++)
		{
			Contador[(Respuestas[i][33])-97]++;
		}
	}
	else if(NumPregun==16)
	{
		for(int i=0; i<365;i++)
		{
			Contador[(Respuestas[i][58])-97]++;
		}
	}
	else if(NumPregun==18)
	{
		for(int i=0; i<365;i++)
		{
			Contador[(Respuestas[i][69])-97]++;
		}
	}
	else if(NumPregun==19)
	{
		for(int i=0; i<365;i++)
		{
			Contador[(Respuestas[i][70])-97]++;
		}
	}
}
void Moda(int NumPregun,int Contador[10])//obterner la moda
{
	int Moda=Contador[0],Indi=0;
	char Letra;
	if(NumPregun==7||NumPregun==13||NumPregun==17||NumPregun==20)//Excepciones para caundo son numeros y no letras
	{
		 Letra=49;
	}
	else
	{
		 Letra=97;
	}
	for(int i=1;i<8;i++)
	{
		if(Contador[i]>Moda)
		{
			Moda=Contador[i];
			Indi=i;
		}
		Letra+=Indi;
	}

	cout<< "La moda de la pregunta " << NumPregun << " Es " << Letra << endl;
}
void ModaImp(int NumPregun,int Contador[10])//Obterner la moda otra ves pero esta vercion la imprime en un archivo de .csv
{
	ofstream arch("c:\\datos\\ResultadoDeEncuenstas.csv",ios::out);
	int Moda=Contador[0],Indi=0;
	char Letra;
	if(NumPregun==7||NumPregun==13||NumPregun==17||NumPregun==20)//Condicion para cambia de letra a numero
	{
		 Letra=49;//Inicia desde el caracter ascii '1'
	}
	else
	{
		 Letra=97;//Inicia desde el caracter ascii 'a'
	}
	for(int i=1;i<8;i++)
	{
		if(Contador[i]>Moda)
		{
			Moda=Contador[i];
			Indi=i;
		}
		Letra+=Indi;
	}
	arch<<endl;
	arch<<endl;
	arch<< "La moda de la pregunta " << NumPregun << " Es "<< Letra << endl;
	arch.close();
}
void FrecuenciaRelativaYAcum(int NumPregun,int Contador[10])//Obtener las frecuencias de los resultados y porcentajes asi como acumulados
{
	char letra=97;
	float acum=0;
	cout << "La pregunta tubo estas frecuencias\n";
	for(int i=0;i<8;i++)
	{
		cout << letra << "=" << Contador[i] << endl;
		letra++;
	}
	cout << "Y estas son las frecuencias relativas\n";
	letra=97;//Reiniciar la letra para contar otra ves dede a
	for(int i=0;i<8;i++)
	{
		cout << letra << "=" <<Contador[i]/8 << endl;
		letra++;
	}
	letra=97;//Reiniciar la letra para contar otra ves dede a
	cout << "Estas son las frecuencias acumuladas\n";
	for(int i=0; i<8; i++)
	{
		acum+=Contador[i]/8;
		cout << letra << "=" << acum << endl;
		letra++;
	}
}

void FrecuenciaRelativaYAcumImp(int NumPregun,int Contador[10])//La misma funcion pero esta saca los resultados al un archivo .csv
{
    float acum=0;
	ofstream arch("c:\\datos\\ResultadoDeEncuenstas.csv",ios::out);
	for(int i=0;i<5;i++)//Ciclo para saltar espacios en el achivo
	{
		arch<<endl;
	}
	char letra=97;
	 arch<< "La pregunta tubo estas frecuencias\n";
	for(int i=0;i<8;i++)
	{
		 arch<< letra << "=" << Contador[i] << endl;
		letra++;
	}
	arch << "Y estas son las frecuencias relativas\n";
	letra=97;//Reiniciar la letra para contar otra ves dede 'a'
	for(int i=0;i<8;i++)
	{
		arch << letra << "=" <<Contador[i]/8 << endl;
		letra++;
	}
	letra=97;//Reiniciar la letra para contar otra ves dede ?'a'
	cout << "Estas son las frecuencias acumuladas\n";
	for(int i=0; i<8; i++)
	{
		acum+=Contador[i]/8;
		arch << letra << "=" << acum << endl;
		letra++;
	}
arch.close();
}
