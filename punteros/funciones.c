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

        for (int i = 0; i < 10; i++)
        {    
            int CondicionParaBuscar= 0;
            do{
                CondicionParaBuscar = 1;
                if((reserva[i][0]) == -1){
                    buscarPorNombreConPuntero(peliculas, indicePelicula );
                    printf("indice pelicula encontrada : %d\n", *indicePelicula);
                    reserva[i][0] = *indicePelicula;

                    // voy a pedir el nombre del cliente (remplazar en reservas i,1)
                    printf("Ingrese el nombre del cliente:");
                    scanf("%s",nombreCliente);

                    for (int i = 0; i < 5; i++){
                            if (strcmp(clientes[i][0], nombreCliente) == 0) {
                                *indiceCliente = i ;
                            }

                    }
                        //cuantos tickets quiere normales , ninos , 3ra edad(remplazar la cantidad de tickets en reservas i,2)
                        do{
                            printf("Que tipo de tickets desea:\n1.Tickets normales\n2.Tickets niños\nTickets 3ra edad\n>>");
                            scanf("%d",&opcionTicket2);
                            switch (opcionTicket2)
                            {
                            case 1:
                                printf("Cuantos Tickets normales desea\n>>");
                                scanf("%d",&ticketsNormales);
                                break;
                            case 2:
                                printf("Cuantos Tickets Para Niños Desea\n>>");
                                scanf("%d",&ticketsNinos);
                                break;
                            case 3:
                                printf("Cuantos Tickets Para 3ra Edad Desea\n>>");
                                scanf("%d",&ticketsterceraEdad);
                                break;
                            default:
                                break;
                            }
                            printf("Desea Mas Tickets 1.si 2.no\n>>");
                            scanf("%d",&opcionTicket);
                        }while (opcionTicket == 1);
                        totalTickets = ticketsNinos + ticketsNormales +  ticketsterceraEdad;
                        reserva[i][2]=totalTickets;
                        //calcular el precio de los tickets (remplazar en reserva i,3)
                        precioAcumulado = (ticketsNormales * precio[0]) + (ticketsNinos * precio[1]) + (ticketsterceraEdad * precio[2]);
                        reserva[i][3]=precioAcumulado;
                        break;
                    
                }
            }while(CondicionParaBuscar=1);
    
        }
}

void verCompras(int reserva[0][4]){
    for (int i = 0; i < 10; i++)
    {
        if ((reserva[i][0])!= -1)
        printf("%s\t\t%s\n",reserva[i][0],reserva[i][1],reserva[i][2],reserva[i][3]);
    }  
} 

