//<stdlib.h> library has system() library function. 
#include<stdlib.h> 
// por printf y scanf 
#include <stdio.h>
#define SALIR 0
#define COMPILAR 

void mostrar_menu()
{
	printf("Indique el nro de opción: \n");
	printf("1 - Calculadora \n");
	printf("2 - Limpiar la consola \n");
	printf("3 - IP de mis interfaces de red \n");
	printf("4 - Editor de texto plano \n");
	printf("0 - Salir\n");
}


int main(void)
{

	printf("Levantando otros programas\n");
	int opcion = 1;

	while(opcion != SALIR)
	{
		
		mostrar_menu();
		scanf("%d",&opcion);
		
		printf("Ud. eligió %d \n",opcion);	

		switch(opcion) {

		   case SALIR  :
			   break; 
			
		   case 1  :
			  system("gnome-calculator");
			  break; 
		   case 2  :
			  system("clear");
			  break;
 		   case 3  :
			  system("ifconfig");
			  break;
		   /* you can have any number of case statements */
		   default : 
			printf("Ingrese una opción válida  \n");	
		   
		}
	} // fin while 
    return 0;
}

