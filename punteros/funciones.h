void ingresarCliente(char clientes[][2][40]);
void imprimirClientes(char clientes[][2][40]);
void listarPeliculas(char peliculas [][4][40]);
void buscarporGenero(char peliculas [][4][40]);
void buscarporNombre(char peliculas [][4][40]);
void comprarTicket(char peliculas[][4][40],int precio[3],char clientes[5][2][40],int reserva[][4],int *indicePelicula,int *indiceCliente);


void buscarPorNombreConPuntero(char peliculas [][4][40],int *indicePelicula);