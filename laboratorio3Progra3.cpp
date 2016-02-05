#include <iostream>
#include <ctime>
#include <cstdlib>

using std::cout;
using std::cin;
using std::endl;

int partida(int);
void ordenar(int[], int,int);
void writeArray(int[], int);


int main(int argc, char*argv[]){
bool jugar = true;
bool menu = true;
int decision=0;
srand(time(NULL));
int numero = 0;
const int SIZE= 10;
int score[SIZE]={0,0,0,0,0,0,0,0,0,0};
char opcion;
int valoresMatriz[4][3];
int ataque1, ataque2, defensa1,defensa2,speed1,speed2,life1,life2;

while(menu==true){
	cout<<"Seleccione lo que desea hacer: "<<endl<<
	"1. Ejercicio 1"<<endl<<
	"2. Ejercicio 2 "<<endl<<
	"3. Salir"<<endl;
	cin>>decision;

	if(decision==1){

		while(jugar ==true){
			numero  = -500 + rand()%(501+500);
        		cout<<numero<<endl;
			cout<<"Adivine el numero secreto: "<<endl;

	
			ordenar(score,partida(numero), SIZE);
			writeArray(score,SIZE);

			cout<<"Desea seguir jugando? s/n"<<endl;
			cout<<"Al salir la tabla de scores se borra."<<endl;
			cin>>opcion;

			if(opcion=='s'){
				jugar=true;
	
			}else{
				jugar=false;
		
			}		
		}
	}else if(decision==2){
		for(int i = 0; i<4;i++){
			for(int j = 0; j<3;j++){
				if(j==0){
					valoresMatriz[i][j]=85+rand()%(116-85);
				}else if(j==1){
					valoresMatriz[i][j]=50+rand()%(76-50);
				}else if(j==2){
					valoresMatriz[i][j]=150+rand()%(201-150);	
				}
			}
		}			
	cout<<"Ataque           Defensa         Velocidad"<<endl;

        for(int i=0;i<4;i++){
                for(int j = 0;j<3;j++){
                        cout<<valoresMatriz[i][j]<<"                  ";
                }
		cout<<endl;
        }

	ataque1 = valoresMatriz[0+rand()%(4-0)][0];
	ataque2 = valoresMatriz[0+rand()%(4-0)][0];
	defensa1 = valoresMatriz[0+rand()%(4-0)][1];
	defensa2 = valoresMatriz[0+rand()%(4-0)][1];
	speed1 = valoresMatriz[0+rand()%(4-0)][2];
	speed2 = valoresMatriz[0+rand()%(4-0)][2];

	cout<<"Jugador 1: "<<"Ataque "<<ataque1<<" Defensa "<<defensa1<<" Velocidad "<<speed1<<"."<<endl;
	cout<<"Jugador 2: "<<"Ataque "<<ataque2<<" Defensa "<<defensa2<<" Velocidad "<<speed2<<"."<<endl;	
	
	life1=ataque1-defensa2;
	life2=ataque2-defensa1;

	if(life1>life2){
		cout<<"Jugador 1, gano por "<<life1-life2<<" puntos de diferencia, no gano por velocidad"<<endl;
	}else if(life1<life2){
		cout<<"Jugador 2, gano por "<<life2-life1<<" puntos de diferencia, no gano por velocidad"<<endl;
	}else if(life1==life2){
		if(speed1>speed2){
			life2=life2-speed1;
			cout<<"JUgador 1, gano por "<<life1-life2<<" puntos de diferencia, GANO POR VELOCIDAD"<<endl;
		}else if(speed1<speed2){
			life1=life1-speed2;
			cout<<"Jugador 2, gano por "<<life2-life1<<" puntos de diferencia, GANO POR VELOCIDAD"<<endl;
		}else if(speed1==speed2){
			cout<<"La partida ha terminado en empate, ambos jugadores con "<<life1<<" puntos"<<endl;
		}
	}	
	}else if(decision==3){
		exit(1);
	}
}
return 0;
}

int partida(int num){
bool seguir=true;
int intento= 0;
int contador=0;

while(seguir==true){
                cout<<"Ingrese un numero: "<<endl;
                cin>>intento;

		if(intento>num){
			cout<<"El numero es mayor. "<<endl;
			contador++;
		}else if(intento<num){
			cout<<"El numero es menor."<<endl;
			contador++;
		}else if(intento==num){
			cout<<"Felicidades, has adivinado!"<<endl;
			contador++;
			seguir=false;
		}
        }
return contador;
}

void ordenar(int numeros[],int x, int l){
	int parametro=x;
	int temporal;
	for(int i = l-1; i>=0;i--){
		if(numeros[i]<parametro&&parametro!=0){
			temporal = numeros[i];
			numeros[i]=parametro;
			parametro = temporal;	
		}else if(numeros[i]>parametro&&parametro!=0){
			numeros[i]=numeros[i];
			parametro=parametro;
		}
	}

		
	
}

void writeArray(int lista[], int m){
	cout<<"-------------------High Scores-----------------------"<<endl;
	for(int i = 0; i<m; i++){
		cout<<i+1<<".   "<<lista[i]<<endl;
	}
}


