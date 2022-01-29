//Definción de las librerías
#include "stdio.h"
#include "stdlib.h"
#include <ctype.h>

//Definición de las variables
typedef struct _Nodo{
	
	char *nombre;
	char numero_de_cuenta[9];
	struct _Nodo *siguiente;
	
}FIFO;

FIFO *principio = NULL;

FIFO *final = NULL;

int contador = 0;

//Definición de las funciones
void Inciso_a(void);
void Ingresar_datos(FIFO *);
void Inciso_b(void);
void Inciso_c(void);
int Inciso_d(void);
void Otro_caso(void);

//Función principal del programa
int main(void){
	
	char opcion, respuesta;
	
	do{
		
		system("cls");
		
		printf("\t\t\tBASE DE DATOS.\n\n");
		printf("Elige una de las siguientes opciones: ");
		printf("\na)Ingresar elementos.");
		printf("\nb)Mostrar elementos.");
		printf("\nc)Eliminar elementos.");
		printf("\nd)Salir.");
		
		printf("\n\nOpci%cn: ",162);
		fflush(stdin);
		scanf("%c",&opcion);
		
		opcion = tolower(opcion);
		
		switch(opcion){
			
			case 'a':{
				
				Inciso_a();
				
				break;
			}
			case 'b':{
				
				Inciso_b();
				
				break;
			}
			case 'c':{
				
				Inciso_c();
				
				break;
			}
			case 'd':{
				
				Inciso_d();
				
				break;
			}
			default:{
				
				Otro_caso();
				
				break;
			}
		}
		
		printf("\n\n\n\nPara salir del programa oprima una 'N', en caso contrario \noprima cualquier tecla.\n");
		fflush(stdin);
		scanf("%c",&respuesta);
		
		respuesta = toupper(respuesta);
		
	}while(respuesta != 'N');

	return 0;

}

//La función del inciso (a), permite ingresar los datos a la FIFO
void Inciso_a(void){
	
	system("cls");
	
	if(contador == 5){
		
		printf("\n\n\n\t***************************************************************\n");
		printf("\t*                                                             *\n");
		printf("\t*    Lo sentimos pero la base de datos se encuentra llena.    *\n");
		printf("\t*                                                             *\n");
		printf("\t***************************************************************\n");
		
	}else{
		
		FIFO *nodo_auxiliar = NULL;
		char cuenta = 0;
		int Maximo;
		
		nodo_auxiliar = (FIFO *)malloc(sizeof(FIFO));
		
		printf("\t\tINGRESAR ELEMENTOS\n\n");
		printf("Nombre: ");
		nodo_auxiliar->nombre = (char *)malloc(sizeof(char)*100);
		fflush(stdin);
		scanf("%[^\n]",nodo_auxiliar->nombre);
		
		printf("N%cmero de cuenta: ",163);
		fflush(stdin);
		while((cuenta = getchar()) != '\n' && (Maximo < 9)){
			
			if((cuenta == '0') || (cuenta == '1') || (cuenta == '2') || (cuenta == '3') || (cuenta == '4') || (cuenta == '5') || (cuenta == '6') || (cuenta == '7') || (cuenta == '8') || (cuenta == '9')){
				
				nodo_auxiliar->numero_de_cuenta[Maximo++] = cuenta;
			
			}else{
				
				continue;
				
			}
		}
		
		nodo_auxiliar->numero_de_cuenta[Maximo] = '\0';
		
		printf("\n\n\nLos elementos ingresados fueron: ");
		printf("\n\nNombre: %s\n",nodo_auxiliar->nombre);
		printf("N%cmero de cuenta: %s\n",163,nodo_auxiliar->numero_de_cuenta);
		
		Ingresar_datos(nodo_auxiliar);
		
		contador = contador + 1;
		
	}
	
}

//Esta función se encarga de ingresar los elementos en la FIFO
void Ingresar_datos(FIFO *nodo_auxiliar){
	
	nodo_auxiliar->siguiente = NULL;
	
	if(final == NULL){
		
		principio = nodo_auxiliar;
		final = nodo_auxiliar;
		
	}else{
		
		final->siguiente = nodo_auxiliar;
		final = nodo_auxiliar;
		
	}
	
}

//La función del inciso (b), muestra en pantalla los datos ingresados hasta el momento
//en la FIFO
void Inciso_b(void){
	
	system("cls");
	
	printf("\t\t\tBASE DE DATOS\n\n");
	
	if(final == NULL){
		
		printf("\n\n\n\n\t*********************************************************\n");
		printf("\t*                                                       *\n");
		printf("\t*       No hay datos dentro de la base de datos.        *\n");
		printf("\t*                                                       *\n");
		printf("\t*********************************************************\n");
		
	}else{
		
		FIFO *Mostrar = NULL;
		
		Mostrar = principio;
		
		printf("**********************************************************************\n");
		printf("N%cmero de cuenta\t|\tNombre\n",163);
		printf("**********************************************************************\n");
		
		while(Mostrar != NULL){
			
			printf("%s\t\t|%s\n",Mostrar->numero_de_cuenta,Mostrar->nombre);
			printf("**********************************************************************\n");
			Mostrar = Mostrar->siguiente;
			
		}
	}
	
}

//La función del inciso (c), muestra los datos de la COLA en la pantalla
void Inciso_c(void){
	
	system("cls");
	
	if(final == NULL){
		
		printf("\n\n\n\t\t*******************************************\n");
		printf("\t\t*                                         *\n");
		printf("\t\t*   La base de datos no tiene elementos.  *\n");
		printf("\t\t*                                         *\n");
		printf("\t\t*******************************************\n");
		
	}else{
		
		FIFO *Eliminar = NULL;
		
		Eliminar = principio->siguiente;
		principio = Eliminar;
		
		if(principio == NULL){
			
			final = NULL;
			
		}
		
		printf("\n\n\n\t\t*******************************************\n");
		printf("\t\t*                                         *\n");
		printf("\t\t*    Elemento eliminado exitosamente.     *\n");
		printf("\t\t*                                         *\n");
		printf("\t\t*******************************************\n");
		
	}
	
}

//Esta función es llamada para salir del programa
int Inciso_d(void){
	
	exit(-1);
	
}

//Esta función le dice al usuario si se ha equivocado y que si quiere volverlo a intentar
void Otro_caso(void){
	
	system("cls");
	
	printf("\n\n\n\t\t*************************************\n");
	printf("\t\t*                                   *\n");
	printf("\t\t*        Opci%cn inv%clida.           *\n",162,160);
	printf("\t\t*       Vuelve a intentarlo.        *\n");
	printf("\t\t*                                   *\n");
	printf("\t\t*************************************\n");
	
}
