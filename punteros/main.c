#include <stdio.h>
#include "funciones.h"

int main (int argc, char *argv[]) {
    int peliculaSeleccionada = -1;
    int *peliculaPuntero;

    peliculaPuntero = &peliculaSeleccionada;

    int clienteSeleccionado = -1;
    int *clientepuntero;

    clientepuntero = &clienteSeleccionado;


    
    char peliculas[10][4][40]={
                                {"","","",""},
                                {"","","",""},
                                {"","","",""},
                                {"1","Avatar","10:20","Fantasia"},
                                {"","","",""},
                                {"","","",""},
                                {"","","",""},
                                {"","","",""},
                                {"","","",""},
                                {"","","",""}};
    int precio[3]={700,350,300};//normal , ninos y 3ra edad
    char clientes[5][2][40]={{"",""},
                             {"Luis","123456788"},
                             {"",""},
                             {"",""},
                             {"",""}};

    int reserva[10][4]={{-1,-1,-1,-1},//pelicula 0, cliente 1, 3 tickets, precio 4 
                         {-1,-1,-1,-1},
                         {-1,-1,-1,-1},
                         {-1,-1,-1,-1},
                         {-1,-1,-1,-1},
                         {-1,-1,-1,-1},
                         {-1,-1,-1,-1},
                         {-1,-1,-1,-1},
                         {-1,-1,-1,-1},
                         {-1,-1,-1,-1}};


    int opcion1=0,opcion2=0,opcion3=0;
    do
    {
        printf("Escoja una opcion:\n1.Ingresar Cliente\n2.Ver Peliculas\n3.Buscar Pelicula\n4.Comprar Ticket\n5.Ver Compras\n>>");
        scanf("%d",&opcion2);
        switch (opcion2)
        {
        case 1:
            ingresarCliente(clientes);
            break;
        case 2:
            listarPeliculas(peliculas);
            break;
        case 3:
            printf("1.Por nombre\n2.Por Genero\n>>");
            scanf("%d",&opcion3);
            switch (opcion3)
            {
            case 1:
                buscarporNombre(peliculas);
                //printf("%d antes\n",peliculaSeleccionada);
                //buscarPorNombreConPuntero(peliculas,peliculaPuntero);
                //printf("%d despues\n",peliculaSeleccionada);
                break;
            case 2:
                buscarporGenero(peliculas);
                break;
            default:
                break;
            }
            break;
        case 4:
            comprarTicket(peliculas,precio,clientes,reserva,peliculaPuntero,clientepuntero);
            break;
        case 5:
            verCompras(reserva);
            break;
        default:

            break;
        }
        printf("Desea escoger una nueva opcion: 1.Si/2.No\n>>");
        scanf("%d",&opcion1);
    } while (opcion1==1);
    


    return 0;
}