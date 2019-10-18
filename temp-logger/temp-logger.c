//<stdlib.h> library has system() library function. 
// tambien por atof
#include<stdlib.h> 
// por printf y scanf 
#include <stdio.h>
// para obtener fecha y hora
#include<time.h>
#include<string.h>

#define SALIR 0
#define COMPILAR 

struct Datos {

	char tiempo[20];
	float temperatura;

};


void mostrar_menu()
{
	printf("Indique el nro de opción: \n");
	printf("1 - Logger Temp \n");
	printf("0 - Salir\n");
}

/*pasaje por referencia de una cadena*/

void leer_fecha_hora(char* fh)
{
 	char buff[20];
	time_t now = time(NULL);
	strftime(buff, 20, "%Y-%m-%d %H:%M:%S", localtime(&now));
//	printf("\n otros tiempos: %s \n", buff);
	strcpy(fh,buff);
//	return buff;
}

/* Regresa temperatura CPU en float*/
float leer_temperatura()
{
	FILE *fp;
	float temp = 0;
    char path[1035];

  /* Open , abrimos el comando para leer su salida */
  fp = popen("cat /sys/class/thermal/thermal_zone0/temp | awk '{ print ($1 / 1000) }'", "r");
  if (fp == NULL) {
    printf("Falla al intento de correr el comando \n" );
    exit(1);
  }

  /* Lee la salida, una linea a la vez, mostramos por pantalla */
  while (fgets(path, sizeof(path)-1, fp) != NULL) {
    printf("%s", path);
	temp = atof(path); // convertir string a float 
  }

  /* close, cerramos la tubería al proceso */
  pclose(fp);
  return temp;
}


int main(void)
{
	struct Datos d ;
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
				d.temperatura = leer_temperatura();
			    leer_fecha_hora(d.tiempo);
				printf("%f \n",d.temperatura);
				printf("%s \n",d.tiempo);
			  break; 
		   case 2  :
			  system("clear");
			  break;
 		   case 3  :
			  system("ifconfig");
			  break;
		   
		   default : 
			printf("Ingrese una opción válida  \n");	
		   
		}
	} // fin while 
    return 0;
}

