#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#define MAX_LETRAS 5
#define MAX_LETRAS2 6

char * palabra;

char * elegirPalabra(){
  
  char * input[MAX_LETRAS2];
  char letra;
  int cantPalabras = 1; 
  FILE *fp;
  fp = fopen("C:\\Users\\User\\Desktop\\Nueva carpeta (2)\\Palabras.txt", "r+");
  if (fp == NULL){
    printf("Error al abrir el archivo");
  }
  
  while((letra = fgetc(fp)) != EOF) {
     if(letra == '\n')
            cantPalabras++;
  }
  char palabras[cantPalabras][MAX_LETRAS2];
  //fscanf(fp, MAX_LETRAS2, input);
  
  //while(fgets(input, MAX_LETRAS2, fp)/*fscanf(fp, MAX_LETRAS2, input)*/){ // reads a line from the specified stream and stores it into the string pointed to
    //sscanf(input, "%s", palabras[palabrasLeidas]);
  //  palabrasLeidas++;
  //}
 
  for(int i = 0; i <= cantPalabras; i++){
    fgets(input[i], MAX_LETRAS2, fp);
    memcpy(palabras[i], input, MAX_LETRAS2);

  } 

  srand(time(0));
  int numero = rand() % (cantPalabras+1);
  
  char * palabra = input[numero];
  
  //char * palabra = input[rand()%palabrasLeidas];
  printf("%s", palabras[numero]);
  
  fclose(fp);
  return palabra;
 }

int gameLoop(){
  char palabra[6]; 
//  strcpy(palabra, elegirPalabra());
  char intento[6];
  char pista[6] = {'x', 'x', 'x', 'x', 'x', '\0'};
  int rondasRestantes = 5;
  int puntaje = 5000;

  do
  {
    printf("Ingrese una palabra de 5 letras: \n");
    scanf("%s", &intento);
  } while (strlen(intento) != MAX_LETRAS); // si la palabra no tiene 5 letras vuelve a pedirla

  if (strcmp(palabra, intento) == 0) {
    printf("Ganaste! La palabra era %s\n", palabra);
    puntaje = 10000;
    printf("Puntaje final: %d\n", puntaje);
  } else // if (strlen(intento) == MAX_LETRAS) // intento debe tener 5 letras.
  {
    while (rondasRestantes != 0 && pista != "VVVVV")
    {

      if (strcmp(palabra, intento) == 0) // si las palabra ingresada es igual al objetivo, se gana el juego
      {
        printf("Ganaste! La palabra era %s\n", palabra);
        puntaje += 2000;
        printf("Puntaje final: %d\n", puntaje);
        exit(0);
      }

      if (strcmp(palabra, intento) != 0) // si las palabras no son iguales, ejecuta lo siguiente:
      {

        printf("%s\n", intento);

        for (int i = 0; i < 5; i++)
        {
          if (intento[i] == palabra[i])
          {
            pista[i] = 'V'; // letra está en la posición correcta.
            puntaje += 100;
          }
          else
          {
            pista[i] = 'G'; // la letra no se encuentra en la palabra objetivo.
          }
        }

        for (int i = 0; i < 5; i++)
        {
          if (pista[i] == 'G')
          {
            for (int j = 0; j < 5; j++)
            {
              if (intento[i] == palabra[j] && intento[i] != palabra[i])
              {
                pista[i] = 'A';
                puntaje += 50;
              }
            }
          }
        }

        printf("%s\n", pista);
        puntaje -= 500;
        printf("Puntaje actual: %d \n", puntaje);
        rondasRestantes = rondasRestantes - 1;


        if (rondasRestantes == 0 && pista != "VVVVV") {
          printf("Has perdido. La palabra era: %s \n", palabra);
          puntaje = 0;
          printf("Puntaje: %d \n", puntaje);
        } else {
        printf("Quedan %d rondas, por favor ingrese otra palabra: \n", rondasRestantes);
        scanf("%s", intento); // pide otra palabra
        }

      }
    }
  }
  return 0;

}

int main()
{
  char palabra[MAX_LETRAS2];
  char intento[MAX_LETRAS2];
  char pista[MAX_LETRAS2] = {'x', 'x', 'x', 'x', 'x', '\0'}; // necesita el caracter null o se va a tomar como un array de char
  int rondasRestantes = 5;
  int cantidadDeJugadas;
  char finalizarJugada[3];
  char si[3] = {"SI"};
  
  elegirPalabra();

  do {
    printf("Ingrese la cantidad de veces que desea jugar: (Máximo 8) \n");
    printf(">");
    scanf("%d", &cantidadDeJugadas);
  } while (cantidadDeJugadas > 8);
  
  //char* arr[MAX_LETRAS2][cantidadDeJugadas + 1];
  
  
    for(int i = 1; i <= cantidadDeJugadas; i++) {
      printf("Partida número %d de %d \n", i, cantidadDeJugadas);
      gameLoop();
      
      //for(int j=0; j < cantidadDeJugadas; j++){
      //  strcpy(arr[MAX_LETRAS2][j], palabra);
      
      //} 
      if (cantidadDeJugadas != 1) {
        printf("Desea finalizar la partida? \nIngrese SI o NO \n");
        scanf("%s", &finalizarJugada);
      
      if(strcmp(finalizarJugada, si) == 0) {
        break;
      }
  } 
    }
  return 0;
}