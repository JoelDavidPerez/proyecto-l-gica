#include <iostream>
#include <stdlib.h>
#include <conio.h>
#include <iomanip>
#include <time.h>

using namespace std;

int determinarPica(int numeroIngresado, int posicion, int numero[])
{
	int devuelve = 0;
	for(int i=0;i<4;i++)
	{
		if(numeroIngresado==numero[i] && posicion!=(i+1))//determina el número que sea igual y que la posición sea igual
		{
			devuelve=1;
			break;
		}
	}
	return devuelve;
}

struct Usuario
{
	string Nombre;
	int intentos = 0;
}datos;

int main()
{
	//añadir los carácteres especiales 
	setlocale(LC_ALL, "");
	//variables
	char opcion;
	int opcion2,opcion3,opcion4;
		
	do 
	{
		system("cls");
		cout<<" PICAS Y FIJAS\n\n presiona 1 y enter para continuar... ";
		cin>>opcion2;
		while(opcion2 == 1){
			system("cls");
			cout<<" QUIEN ERES?\n\n DIGITA TU NOMBRE DE USUARIO\n\n > ";
			cin.ignore();
			getline(cin,datos.Nombre);
			cout<<"\n\n presiona 2 y enter para continuar... ";
			
			cin>>opcion3;
			
			while(opcion3 = 2){
				system("cls");
				cout<<" \n\n INSTRUCCIONES: \n\n"<<endl;
			cout<<" En cada intento, el jugador dice 4 dígitos (no repetidos)\n"<<endl;
			cout<<" y el programa le da pistas de cuántos aciertos tuvo, sin\n"<<endl;
			cout<<" indicarle cuales fueron, de la siguiente forma:\n\n"<<endl;
			cout<<" Si algún dígito que dice el jugador se encuentra dentro del número\n"<<endl;
			cout<<" a adivinar, pero no está en la posición correcta, se llama PICA.\n\n"<<endl;
			cout<<" Si el dígito se encuentra en la posición adecuada, se llama FIJA.\n\n"<<endl;
			cout<<" Así, las pistas serán la cantidad de PICAS y la cantidad de FIJAS que se tienen.\n\n";
			cout<<" El juego termina cuando el jugador tiene 4 FIJAS.";
			cout<<"\n\n\n presiona 3 y enter para continuar...";
			cin>>opcion4;
				
				while(opcion4 == 3){
					system("cls");
					int termino=0;
					int num, n1, n2, n3, n4, contadorPicas, contadorFijas,j,temp;
					int numero[4];
					int intentos=0;
					int intentosReinicioFor=0;

                    //numero aleatorio
					srand(time(NULL));
					for(int i=1; i<10; i++){
						numero[i]=i;
					}
					for(int i=1;i<4;i++)
					{
						j=(rand()%10);
						temp=numero[i];
						numero[i]=numero[j];
						numero[j]=temp;
					}
					for(int i=1;i<5;i++)
					{
						cout<<numero[i];
					}

					while(termino==0){
							cout<<"\n\n Ingresa el numero: ";
							cout<<"\n ";
							cin>>num;
							while(num>9999)
							{
								cout<<"\n\n Ingresa de nuevo el número, de 4 cifras\n\n";
								cout<<"\n\n Ingresa el numero:";
								cout<<"\n ";
								cin>>num;
							}
							while(num<1000 && num!=-1)
							{
								cout<<"\n\n Ingresa un valor correcto de 4 cifras\n\n ";
								cout<<"\n\n Ingresa el numero: ";
								cout<<"\n ";
								cin>> num;
							}

							while(num<-1)
							{
								cout<<"\n\n Ingresa un valor correcto. Tiene que ser positivo y de 4 cifras\n\n";
							    cout<<"\n\n Ingresa el numero:";
							    cout<<"\n ";
								cin>>num;
							}
							n1=(num/1000);
							n2=((num%1000)/100);
							n3=(((num%1000)%100)/10);
							n4=((num%1000)%100)%10;

							contadorPicas=0;
							contadorFijas=0;

							if(n1==numero[1] && n2==numero[2] && n3==numero[3] && n4==numero[4]){
								cout<<"\n\n\n 4 FIJAS, GANASTE.";
								cout<<"\n\n presiona enter para continuar...";
								termino=1;
							}
							else if(num==-1)
							{
						cout<<"\n\n\n";
									cout<<"\n\ te rendiste :c ";
									cout<<"\n\ El número era: ";
									for(int i=1;i<5;i++)
									{
										cout<<numero[i];
									}
									cout<<"\n\n\t\t\t\t   presiona enter para continuar...";
									termino=1;
							}
							else{
								contadorPicas=contadorPicas + determinarPica(n1, 1, numero);
								contadorPicas=contadorPicas + determinarPica(n2, 2, numero);
								contadorPicas=contadorPicas + determinarPica(n3, 3, numero);
								contadorPicas=contadorPicas + determinarPica(n4, 4, numero);

								if(n1==numero[1]){
									contadorFijas=contadorFijas+1;
								}
								if(n2==numero[2]){
									contadorFijas=contadorFijas+1;
								}
								if(n3==numero[3]){
									contadorFijas=contadorFijas+1;
								}
								if(n4==numero[4]){
									contadorFijas=contadorFijas+1;
								}
								intentos++;
								intentosReinicioFor++;
								cout<<"\n "<<contadorPicas<<" picas,"<<contadorFijas<<" fijas "<<"\t\t   ";
								cout<<"intentos: "<<intentos<<"\n\n";
							}

							for(int intentosFor=0;intentosReinicioFor==1;intentosFor++)
							{
								cout<<"\n\n\n quieres rendirte? \n\n\n ";
								cin>>num;
									if(num==-1)
									{
									cout<<"\n\n\n";
									cout<<"\n\ te rendiste :c ";
									cout<<"\n\ El número era: ";
									for(int i=1;i<5;i++)
									{
										cout<<numero[i];
									}
									cout<<"\n\n presiona enter para continuar...";
									termino=1;
									}
								intentosReinicioFor=0;
								intentosFor=0;
							}
					}
					_getch();
				}
				break;
			}
			break;
		}	
		//Pregunta para volver a iniciar el proceso	
		system("cls");
        cout<<" Desear volver al inicio? s/n";
		
		opcion = getch();			
	}while (opcion == 'Y' || opcion == 'y' || opcion == 'S' || opcion == 's');
	system("cls");
	cout<<"\n GRACIAS POR JUGAR\n\n esperamos volver a verte pronto"<<endl;
	return 0;
}

