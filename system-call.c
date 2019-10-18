/*
  __                       .__              .__   
_/  |_  ___________  _____ |__| ____ _____  |  |  
\   __\/ __ \_  __ \/     \|  |/    \\__  \ |  |  
 |  | \  ___/|  | \/  Y Y  \  |   |  \/ __ \|  |__
 |__|  \___  >__|  |__|_|  /__|___|  (____  /____/
           \/            \/        \/     \/      
         _nnnn_                      
        dGGGGMMb     ,"""""""""""""".
       @p~qp~~qMb    | Linux Rules! |
       M|@||@) M|   _;..............'
       @,----.JM| -'
      JS^\__/  qKL
     dZP        qKRb
    dZP          qKKb
   fZP            SMMb
   HZM            MMMM
   FqM            MMMM
 __| ".        |\dS"qML
 |    `.       | `' \Zq
_)      \.___.,|     .'
\____   )MMMMMM|   .'
     `-'       `--' hjm


*/

//<stdlib.h> library has system() library function. 
#include<stdlib.h> 
// por printf y scanf 
#include <stdio.h>


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
				system("gnome-calculator");
				break; 
		   case 2  :
			  system("clear");
			  break;
 		   case 3  :
			  system("ifconfig");
			  break;
		   case 4  :
				system("gedit");
				break;
			   
		   default : 
			printf("Ingrese una opción válida  \n");	
		   
		}// fin switch

		// si es proceso hijo,
		// que ejecute en proceso aparte

		//si es hijo, cerrar proceso
		if (pid == 0) break; // salir del while, luego salir del programa.

	} // fin while 
    return 0;
}

