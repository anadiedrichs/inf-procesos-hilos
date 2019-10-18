//<stdlib.h> library has system() library function. 
// tambien por atof
#include<stdlib.h> 
// por printf y scanf 
#include <stdio.h>
// para obtener fecha y hora
#include<time.h>
#include<string.h>

#define SALIR 0

/***/
// C program for implementation of ftoa() 
#include<stdio.h> 
#include<math.h> 
#include <pthread.h>
/***/
struct Datos {

	char tiempo[20];
	float temperatura;

};

/*
Muestra opciones al usuario
*/
void mostrar_menu()
{
	printf("Indique el nro de opción: \n");
	printf("1 - Logger Temp \n");
	printf("2 - Simula Temp \n");
	printf("0 - Salir\n");
}

/* 

Obtener fecha y hora actual
pasaje por referencia de una cadena

*/

void leer_fecha_hora(char* fh)
{
 	char buff[20];
	time_t now = time(NULL);
	strftime(buff, 20, "%Y-%m-%d %H:%M:%S", localtime(&now));
//	printf("\n otros tiempos: %s \n", buff);
	strcpy(fh,buff);
//	return buff;
}

/* 
Regresa temperatura CPU en float
*/
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
/***********************sensor simulado ******************************/
/*
genera números aleatorios entre 0 y 10, se lo suma a 25 y regresa el valor
*/
float simula_temperatura(){
	float random_number_f = 	rand() % 1000 ; // genero numero aleatorio entre 0 y 1000
	random_number_f = random_number_f / 100.0f;

	return( 25 + random_number_f);
}

void sensor_cpu()
{

}
void sensor_simulado()
{
	// timer ??
	// obtiene valor temperatura
    float temp = simula_temperatura();
	// obtiene estampa de tiempo
	char* t ;
	leer_fecha_hora(t);
	// guarda valores
	
}

void guarda_en_csv_caracteres(char * fpath,struct Datos* d){

}

void guarda_estructura(char * fpath,struct Datos* d)
{

}

void enviar_datos(){}

struct Datos d ;

int main(void)
{

   int i, n;
   time_t t;
   float temp;
  
   /* Intializes random number generator */
	srand((unsigned) time(&t));
 
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

			 temp = simula_temperatura();
			 char* field1, field2, field3,field4;
			  
 			  
  			 char comando[550]; 
	
// curl --silent --request POST --header "X-THINGSPEAKAPIKEY: W9RJ5HX0W51QKLCX" --data "field1=26.2&field2=36.2&field3=17.8&field4=35.2" "http://api.thingspeak.com/update"

			sprintf(comando,"curl --silent --request POST --header \"X-THINGSPEAKAPIKEY: W9RJ5HX0W51QKLCX\" --data \"field1=%.2f&field2=%.2f&field3=%.2f&field4=%.2f\"  \"http://api.thingspeak.com/update\"", d.temperatura, temp, temp,temp); 

			system(comando);

	// The string "sum of 10 and 20 is 30" is stored 
	// into buffer instead of printing on stdout 
			printf("%s", comando); 

			  break;
		   
		   default : 
			printf("\nIngrese una opción válida  \n");	
		   
		}// fin switch
	} // fin while 
    return 0;
}

