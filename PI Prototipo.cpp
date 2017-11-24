#include <iostream>
#include <fstream>

using namespace std;
void Menu();
int Moda(int NumPregun,int Contador[365]); //Regresa la moda de la preguntra dada
int ModaImp(int NumPregun,int Contador[365]); //Regresa la moda de la preguntra dada
int Contador(int NumPregun,int Contador[365]); //Cuenta las respuestra de la pregunta dada y da la frecuencia de cada una
int FrecuenciaRelativaYAcum(int NumPregun,int Contador[365]); //Regresa la fecuencia relativa y acumulada de los resultados de la pregunta dada
int FrecuenciaRelativaYAcumImp(int NumPregun,int Contador[365]); //Regresa la fecuencia relativa y acumulada de los resultados de la pregunta dada
void LectorPrincipal(Char Respuestas[][73],char IndiPregun[73], int r); //Lee todo el archivo de exel-Felix
void ImpresorExelDatos(int NumPregun,char IndiPregun[73], char Respuestas[][73],int r);// Crea un archivo con los datos del resumen-Felix
void LectorPregunta(int NumPregun,char RespuestaColum[365]);//Lee solo los datos de la preungta dada
void ResumenGeneral(int Contador[365],Char IndiPregun[73], char Respuestas[][73],int r);//Imprime en pantalla los datos de todo el archivo (Todas las modas, todas las fecuencias,etc)

int main()
{
	ifstream archi("c:\\datos\\PIBaseDeDatos.xlsx",ios::in)
	int op,Numpregun;
	char IndiPregun[73];
	char Respuestas[365][73];
	char RespuestaColum[365][10];
	int Contador[365];
	do
	{
		op=Menu();
		if(op==1)
		{
			cout << "De que Pregunta desea saber la moda?\n";
			cin >> NumPregun;
			cout << "La moda de la pregunta " << NumPregun << " es " << Moda(NumPregun,Contador); << endl;
		}
		else if(op==2);
		{
			cout << "De que pregunta desea saber la frecuencia \n";
			cin >> Numpregun;
			cout << "Las frecuencias  de la pregunta " << Numpregun << " es " << Contador(NumPregun,Contador); << endl;
		}
		else if(op==3);
		{
			cout << "De que pregunta desea saber la Frecuencia relativa y  acumulada\n";
			cin >> Numpregun;
			cout << "La fecuencia relativa acumulada de la pregunta " << Numpregun << "es" << FrecuenciaRelativaYAcum(NumPregun,Contador); << endl;
		}
		else if(op==4);
		{
			cout << " Si desea guardar los datos en un archivo de exel precione 1 si no lo desea preicone 2\n";
			cin >> Numpregun;
			if(Numpregun==1)
			{
				ResumenGeneral(Contador,IndiPregun,Respuestas,365);
				ImpresorExelDatos(NumPregun,IndiPregun,Respuestas,365);
				cout << "Se an guardado los resultados en un archivo de exel llamado *ResultadoDeEncuenstas* en la carpeta Encuestas PI en el disco duro\n";

			}
			else
				ResumenGeneral(Contador,IndiPregun,Respuestas,365);

		}
		
	}while(op!=0);
}
void Menu();
{
	int op;
	cout << "Bienvenido a la calculadora Estadistica MKI\n";
	cout << "Selecione una de las opciones de la acciones a relaisar tecleando un numero su elecion y precione 0 para salir\n";
	cout << "Para Obtener la moda de alguna pregunta preicone 1\n";
	cout << "Para Obtener las frecuenncias de las respuestas de una preguntra precione 2\n";
	cout << "Para obtener la frecuencia relativa acumulada de las respuestas precione 3\n";
	cout << "Para obtener el resumen general de toda la encuesta precione 4\n";
	cin >> op;
	return op;
}
void ImpresorExelDatos(int NumPregun,char IndiPregun[73], char Respuestas[][73],int r,int Contador[365])//poner una oopcion para imprimir todo el archivo y no solo 1 pregunta.
{
	ifstream archi("c:\\datos\\ResultadoDeEncuenstas.xlsx",ios::out);
		for(int i=0; i<73; i++)
	{
		arch<<IndiPregun[i];
	}
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
	ifstream archi("c:\\datos\\PIBaseDeDatos.xlsx",ios::in);
	for(int i=0; i<73; i++)
	{
		archi.getline()>>IndiPregun[i];
	}
	for(int c=0; c<73; c++)
	{
		for(int k=0; k<r; k++)
		{
			archi>>Respuestas[K][C];
		}
	}

}
