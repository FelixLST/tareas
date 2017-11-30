#include <iostream>
#include <fstream>
#include <string.h>

using namespace std;
void Menu();
void Moda(int NumPregun,int Contador[365]); //Regresa la moda de la preguntra dada
void ModaImp(int NumPregun,int Contador[365]); //Regresa la moda de la preguntra dada para imprimir en archivo
void Contador(int NumPregun,int Contador[365],char Respuestas[][365]); //Cuenta las respuestra de la pregunta dada y da la frecuencia de cada una
void FrecuenciaRelativaYAcum(int NumPregun,int Contador[365]); //Regresa la fecuencia relativa y acumulada de los resultados de la pregunta dada
void FrecuenciaRelativaYAcumImp(int NumPregun,int Contador[365]); //Regresa la fecuencia relativa y acumulada de los resultados de la pregunta dada para imprimir en archivo
void LectorPrincipal(Char Respuestas[][73],char IndiPregun[73], int r); //Lee todo el archivo de exel-Felix
void ImpresorExelDatos(int Contador[365], char Respuestas[][73]);// Crea un archivo con los datos del resumen-Felix


int main()
{
	ifstream arch("c:\\datos\\PIBaseDeDatos.xlsx",ios::in)
	int op,Numpregun;
	char Respuestas[365][73];
	int Contador[365]={0};
	do
	{
		op=Menu();
		if(op==1)
		{
			Contador(Numpregun,Contador,Respuestas);
			cout << "De que Pregunta desea saber la moda?\n";
			cin >> NumPregun;
			cout << "La moda de la pregunta " << NumPregun << " es " << Moda(NumPregun,Contador); << endl;
			cout << "Desea guardar las respuestas en un archivo de exel?,precione 1 para si y 2 para no\n";
			cin << res;
			if(res==1)
			{
				 ModaImp(NumPregun,Contador);
			}
		}
		else if(op==2);
		{
			cout << "De que pregunta desea saber la frecuencia,relativa y acumulada \n";
			cin >> Numpregun;
			cout << "Las frecuencias  de la pregunta " << Numpregun << " es " << FrecuenciaRelativaYAcum(NumPregun,Contador); << endl;
			cout << "Desea guardar las respuestas en un archivo de exel?,precione 1 para si y 2 para no\n";
			cin << res;
			if(res==1)
			{
				FrecuenciaRelativaYAcumImp(NumPregun,Contador);
			}
		}
		else if(op==3)
			{
				ImpresorExelDatos()
			}
		
		

			
			
		
		
	}while(op!=0);
}
void Menu();
{
	int op;
	cout << "Bienvenido a la calculadora Estadistica MKI\n";
	cout << "Selecione una de las opciones de la acciones a relaisar tecleando un numero su elecion y precione 0 para salir\n";
	cout << "Para Obtener la moda de alguna pregunta preicone 1\n";
	cout << "Para Obtener las frecuenncias,relativas y acumuladas de las respuestas de una preguntra precione 2\n";
	cout << "Para imprimir un resumen total de todo precione 3\n";
	cin >> op;

	return op;
}
void ImpresorExelDatos(int Contador[365], char Respuestas[][73])//poner una oopcion para imprimir todo el archivo y no solo 1 pregunta la cual sera poner en Numpregun el numero 21
{
	


		ifstream arch("c:\\datos\\ResultadoDeEncuenstas.xlsx",ios::out);
		arch<<"Este es un resumen general de toda la encuesta\n";
		arch.getline();
		arch.getline();
		for(int c=0; c<20; c++)
		{
			arch<<"Los resultados de la pregunta " << c << " Son" << endl;
			arch<<"Moda" << endl;
			ModaImp(c,Contador);
			arch<<"Frecuencia relativa y acumulada "<<endl;
			FrecuenciaRelativaYAcumImp(c,Contador);
		}
}

void LectorPrincipal(Char Respuestas[][73],char IndiPregun[73], int r)
{
	ifstream arch("c:\\datos\\PIBaseDeDatos.xlsx",ios::in);
	getline();
	for(int c=0; c<73; c++)
	{
		arch.cin();
		for(int k=0; k<r; k++)
		{
			arch>>Respuestas[k][c];
		}
	}

}
void Contador(int NumPregun,int Contador[365],char Respuestas[][365])
{
	if(Numpregun==1)
	{
		for(int i=0; i<8; i++)
		{
			for(int k=0; k<365; k++)
			{
				Contador[Respuestas[i][k]-97]++;
			}
		}
	}
	else if(Numpregun==3)
	{
		for(int p=9; p<12; p++)
		{
			for(int t=0;t<365;t++)
			{
				Contador[Respuestas[p][t]-97]++;
			}
		}
	}
	else if(Numpregun==4)
	{
		for(int z=13; z<17; z++)
		{
			for(int g=0; g<365;z++)
			{
				Contador[Respuestas[z][g]-97]++;
			}
		}
	}
	else if(Numpregun==6)
	{
		for(int i=15; i<21; i++)
		{
			for(int k=0; k<365;k++)
			{
				Contador[Respuestas[i][k]-97]++;
			}
		}
	}
	else if(Numpregun==7)
	{
		for(int i=22; i<31; i++)
		{
			for(int k=0; k<365;k++)
			{
				Contador[Respuestas[i][k]-49]++;
			}
		}
	}
	else if(Numpregun==11)
	{
		for(int i=35; i<42;i++)
		{
			for(int k=0; k<365;k++)
			{
				Contador[Respuestas[i][k]-97]++;
			}
		}
	}
	else if(Numpregun==12)
	{
		for(int i=43; i<47;i++)
		{
			for (int k=0; i <365;i++)
			{
				Contador[Respuestas[i][k]-97]++;
			}
		}
	}
	else  if(Numpregun==13)
	{
		for(int i=47; i<50;i++)
		{
			for(int k=0; k<365;k++)
			{
				Contador[Respuestas[i][k]-49]++;
			}
		}
	}
	else if(Numpregun==14)
	{
		for(int i=50; i<56;i++)
		{
			for(int k=0;k<365;k++)
			{
				Contador[Respuestas[i][k]-97]++;
			}
		}
	}
	else if(Numpregun==15)
	{
		for(int i=56; i<58;i++)
		{
			for(int k=0;k<365;k++)
			{
				Contador[Respuestas[i][k]-97]++;
			}
		}
	}
	else if(Numpregun==17)
	{
		for(int i=60;i<69;i++)
		{
			for(k=0;k<365;k++)
			{
				Contador[Respuestas[i][k]-49]++;
			}
		}
	}
	else if(Numpregun==20)
	{
		for(int i=0; i<365;i++)
		{
			Contador[Respuestas[73][i]-49]++;
		}
	}
	else if(Numpregun==2)
	{
		for(int i=0; i<365;i++)
		{
			Contador[Respuestas[8][i]-97]++;
		}
	}
	else if(Numpregun==5)
	{
		for(int i=0; i<365;i++)
		{
			Contador[Respuestas[17][i]-97]++;
		}
	}
	else if(Numpregun==8)
	{
		for(int i=0; i<365;i++)
		{
			Contador[Respuestas[31][i]-97]++;
		}
	}
	else if(Numpregun==9)
	{
		for(int i=0; i<365;i++)
		{
			Contador[Respuestas[32][i]-97]++;
		}
	}
	else if(Numpregun==10)
	{
		for(int i=0; i<365;i++)
		{
			Contador[Respuestas[33][i]-97]++;
		}
	}
	else if(Numpregun==16)
	{
		for(int i=0; i<365;i++)
		{
			Contador[Respuestas[58][i]-97]++;
		}
	}
	else if(Numpregun==18)
	{
		for(int i=0; i<365;i++)
		{
			Contador[Respuestas[69][i]-97]++;
		}
	}
	else if(Numpregun==19)
	{
		for(int i=0; i<365;i++)
		{
			Contador[Respuestas[70][i]-97]++;
		}
	}
}
void Moda(int NumPregun,int Contador[365])
{
	int Moda=Contador[0],Indi=0;
	char Letra;
	if(NumPregun==7||Numpregun==13||Numpregun==17||Numpregun==20)
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
	
	cout<< "La moda de la pregunta " << Numpregun << " Es " Letra << endl;
}
void ModaImp(int NumPregun,int Contador[365])
{
	ifstream arch("c:\\datos\\ResultadoDeEncuenstas.xlsx",ios::out);
	int Moda=Contador[0],Indi=0;
	char Letra;
	if(NumPregun==7||Numpregun==13||Numpregun==17||Numpregun==20)
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
	getline();
	getline();
	arch<< "La moda de la pregunta " << Numpregun << " Es " Letra << endl;
	arch.close();
}
void FrecuenciaRelativaYAcum(int NumPregun,int Contador[365]);
{
	char letra=97;
	int acum=0;
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

void FrecuenciaRelativaYAcumImp(int NumPregun,int Contador[365]);
{
	ifstream arch("c:\\datos\\ResultadoDeEncuenstas.xlsx",ios::out);
	for(int i=0;i<5;i++)//Ciclo para saltar espacios en el achivo
	{
		arch.getline();
	}
	char letra=97;
	 arch<< "La pregunta tubo estas frecuencias\n";
	for(int i=0;i<8;i++)
	{
		 arch<< letra << "=" << Contador[i] << endl;
		letra++;
	}
	arch << "Y estas son las frecuencias relativas\n";
	letra=97;//Reiniciar la letra para contar otra ves dede a
	for(int i=0;i<8;i++)
	{
		arch << letra << "=" <<Contador[i]/8 << endl;
		letra++;
	}
	letra=97;//Reiniciar la letra para contar otra ves dede a
	cout << "Estas son las frecuencias acumuladas\n";
	for(int i=0; i<8; i++)
	{
		acum+=Contador[i]/8;
		arch << letra << "=" << acum << endl;
		letra++;
	}
arch.close();
}
