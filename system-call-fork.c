//<stdlib.h> library has system() library function. 
#include<stdlib.h> 
// por printf y scanf 
#include <stdio.h>
// por pid_t
#include  <sys/types.h>


void mostrar_menu()
{
	printf("Indique el nro de opción: \n");
	printf("1 - Calculadora \n");
	printf("2 - Limpiar la consola \n");
	printf("3 - IP de mis interfaces de red \n");
	printf("4 - Editor de texto plano \n");
	printf("0 - Salir\n");
}

int obtener_opcion()
{
		char o[10]; int opcion;

		scanf("%c",o);
		
		opcion = atoi(o);

		printf("Ud. eligió %d \n",opcion);	
}


int main(void)
{

	printf("Levantando otros programas\n");
	int opcion = 1;
	pid_t  pid;

	while(opcion != 0)
	{
		
		mostrar_menu();
		int opcion = obtener_opcion();

		scanf("%d",&opcion);
		
		printf("Ud. eligió %d \n",opcion);	

		switch(opcion) {

		   case 0  :
				return 0; break; 
			
		   case 1  :
				pid = fork();
				if (pid == 0) 
					system("gnome-calculator");
				break; 
		   case 2  :
			  system("clear");
			  break;
 		   case 3  :
			  system("ifconfig");
			  break;
		   case 4  :
				pid = fork();
				if (pid == 0) 
					system("gedit");
				break;
			   
		   default : 
			printf("Ingrese una opción válida  \n");	
		   
		}

		// si es proceso hijo,
		// que ejecute en proceso aparte

		//si es hijo, cerrar proceso
		if (pid == 0) break; // salir del while, luego salir del programa.

	} // fin while 
    return 0;
}

