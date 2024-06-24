#include <stdio.h>
#include "funciones.h"
#include <string.h>

void ingresarCliente(char clientes[][2][40]){
   
    for (int i = 0; i < 5; i++)
    {
        if(strcmp(clientes[i][0],"")==0){
            printf("Ingrese nombre del nuevo cliente: ");
            scanf("%s",clientes[i][0]);
            printf("Ingrese cedula del nuevo cliente: ");
            scanf("%s",clientes[i][1]);
            break;
        }
    } 
    imprimirClientes(clientes);
}

void imprimirClientes(char clientes[][2][40]){
    for (int i = 0; i < 5; i++)
    {
        printf("%s\t\t%s\n",clientes[i][0],clientes[i][1]);
    }   
}
void buscarPorNombreConPuntero(char peliculas [][4][40],int *indicePelicula){
    char nombre[40];
    printf ("ingrese el nombre de la pelicula que desea buscar:\n");
    scanf("%s",nombre);
    for (int i = 0; i < 10; i++) {
        if (strcmp(peliculas[i][1], nombre) == 0) {
            *indicePelicula = i ;
            printf("%s\t\t%s\t\t%s\t\t%s\n",peliculas[i][0],peliculas[i][1],peliculas[i][2],peliculas[i][3]);
        }
    }
}

void buscarporGenero(char peliculas [][4][40]){
    char nombre[41];
    printf ("ingrese la categoria de la pelicula que desea buscar:\n");
    scanf("%40s",nombre);
    for (int i = 0; i < 10; i++) {
        if (strcmp(peliculas[i][3], nombre) == 0) {
            printf("%s\t\t%s\t\t%s\t\t%s\n",peliculas[i][0],peliculas[i][1],peliculas[i][2],peliculas[i][3]);
        }
    }
}

void listarPeliculas(char peliculas [][4][40]){
    for (int i = 0; i < 10; i++)
    {
    printf("%s\t\t%s\t\t%s\t\t%s\n",peliculas[i][0],peliculas[i][1],peliculas[i][2],peliculas[i][3]);
    }   
}
void comprarTicket(char peliculas[][4][40],int precio[3],char clientes[5][2][40],int reserva[][4],int *indicePelicula,int *indiceCliente){
            printf ("si ingresa:\n");
    char nombrePelicula[40];
    char nombreCliente[40];
    int opcionTicket2 = 0;
    int ticketsNormales = 0;
    int ticketsNinos = 0;
    int ticketsterceraEdad = 0;
    int opcionTicket = 0;
    int totalTickets = 0;
    int precioAcumulado = 0;
    int opcionPrograma = 0;
    int numeroDeTickets;
    //remplazar numeros magicos
    int IndiceDelPrimerEspacioSinData = -1;

    for (int i = 0; i < 10; i++) {
        if (reserva[i][1] == -1) {
            IndiceDelPrimerEspacioSinData = i ;
        }
    }

        
    char nombre[40];
    printf ("ingrese el nombre de la pelicula que desea buscar:\n");
    scanf("%s",nombre);
    *indicePelicula = -1 ;
    *indiceCliente = -1;
    for (int i = 0; i < 10; i++) {
        if (strcmp(peliculas[i][1], nombre) == 0) {
            *indicePelicula = i ;
            reserva[IndiceDelPrimerEspacioSinData][0] = *indicePelicula;
            printf("%s\t\t%s\t\t%s\t\t%s\n",peliculas[i][0],peliculas[i][1],peliculas[i][2],peliculas[i][3]);
            break;
        }
    }
    if (*indicePelicula == -1){
        printf("no se encontro %s\n",nombre);
    }else 
    {

        printf("Ingrese el nombre del cliente:");
        scanf("%s",nombreCliente);

        for (int i = 0; i < 5; i++){

            if (strcmp(clientes[i][0], nombreCliente) == 0) {
                *indiceCliente = i ;
                reserva[IndiceDelPrimerEspacioSinData][1] = *indiceCliente;
            }
        }

        if (*indiceCliente == -1){
            printf("no se encontro %s\n",nombreCliente);
        }else 
        {
            //si no hay lo buscado entonces puntero igual a -1 imprir no se encontro o respetir
            do{
                printf("Que tipo de tickets desea:\n1.Tickets normales\n2.Tickets niños\nTickets 3ra edad\n>>");
                scanf("%d",&opcionTicket2);
                switch (opcionTicket2){
                    case 1:
                        printf("Cuantos Tickets normales desea\n>>");
                        scanf("%d",&numeroDeTickets);
                        ticketsNormales += numeroDeTickets;
                    break;

                    case 2:
                        printf("Cuantos Tickets Para Niños Desea\n>>");
                        scanf("%d",&numeroDeTickets);
                        ticketsNinos += numeroDeTickets;
                    break;
                    case 3:
                        printf("Cuantos Tickets Para 3ra Edad Desea\n>>");
                        scanf("%d",&numeroDeTickets);
                        ticketsterceraEdad += numeroDeTickets;
                    break;
                    default:
                    break;
                }


                printf("Desea Mas Tickets 1.si 2.no\n>>");
                scanf("%d",&opcionTicket);
            }while (opcionTicket == 1);
            totalTickets = ticketsNinos + ticketsNormales +  ticketsterceraEdad;
            reserva[IndiceDelPrimerEspacioSinData][2]=totalTickets;

            precioAcumulado = (ticketsNormales * precio[0]) + (ticketsNinos * precio[1]) + (ticketsterceraEdad * precio[2]);
            reserva[IndiceDelPrimerEspacioSinData][3]=precioAcumulado;
        }
    }
                    
}


void verCompras(int reserva[0][4], char peliculas [][4][40] , char clientes[][2][40]){
int indicePelicula = 0 ;
int indiceClientes = 0 ;
    for (int i = 0; i < 10; i++)
    {
        if ((reserva[i][0])!= -1){
            indicePelicula = reserva[i][0];
            indiceClientes = reserva[i][1];
            printf("%s\t\t%s\t\t%s\t\t%s\n",peliculas[indicePelicula][0],peliculas[indicePelicula][1],peliculas[indicePelicula][2],peliculas[indicePelicula][3]);
            printf("%s\t\t%s\n",clientes[indiceClientes][0],clientes[indiceClientes][1]);
            printf("Tikets reservados: %d\n",reserva[i][2]);
            printf("Precio tikets (centavos): %d\n",reserva[i][3]);
            printf("%s\t\t%s\t\t%d\t\t%d\n",peliculas[indicePelicula][0] ,clientes[indiceClientes][0],reserva[i][2],reserva[i][3]);
        }
    }  
} 

//borrar comprociones printf