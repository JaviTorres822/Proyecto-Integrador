#include <stdio.h>
#include <string.h>
#define MAXFILA 20
#define MAXCOL 30
#define MAXCC 10


void ingresarCadenas(char* mensaje,char nombres[][MAXCOL], int cantidad){
    int i;
    for(i = 0; i < cantidad; i++){
        printf("%s: ",mensaje);
        fflush(stdin);
        scanf("%s",nombres[i]);
  
    }

}
int leerEnteroPositivo(char* mensaje){
  int valor;
  do{
    printf("%s: ",mensaje);
    scanf("%d",&valor);
  }while(valor <= 0);
  return valor;

}
void imprimirCadenas(char* mensaje, char nombres[][MAXCOL], int cantidad){
    int i;
    for(i = 0; i < cantidad; i++){
        printf("%s %d\n",mensaje, i+1);
        printf("%s\n",nombres[i]);
   
    }

}
int leerEnteroEntre(char* mensaje, int minimo, int maximo){
  int valor;
  do{
    printf("%s",mensaje);
    scanf("%d",&valor);

  }while(valor < minimo || valor > maximo);
  return valor;
}
float leerFlotantePositivo(char* mensaje){
    float valor;
  do{
    printf("%s: ",mensaje);
    scanf("%f",&valor);
  }while(valor <= 0);
  return valor;

}
void ingresarMatrizPrecios(char* mensaje, char empresas[][MAXCOL], char productos[][MAXCOL], float valores[][MAXCOL], int productos1, int empresas1){
    int i,j;
    float valor;

    for(i = 0; i < productos1; i++){
        printf("\nProducto %s",productos[i]);
        for(j = 0; j < empresas1; j++){

              printf("\nEmpresa %s\n",empresas[j]);
                valor = leerFlotantePositivo(mensaje);
                valores[i][j] = valor;
        
  
    }
}
}


void imprimirMatrizPrecios(char empresas[][MAXCOL],char productos[][MAXCOL],float valores[][MAXCOL], int productos1, int empresas1){
    int i,j;
    float valor;
    for(i = 0; i < empresas1; i++){
        printf("\nEmpresa %s",empresas[i]);
        for(j = 0; j < productos1; j++)
              printf("\n%s\tprecio %.2f",productos[j],valores[j][i]);
              
   }
}


void ingresarCompras(int compras[],char productos[][MAXCOL], int numProducto){
  int i;
  int cantidad;
  for(i=0; i < numProducto;i++){
    
    printf("cantidad de %s",productos[i]);
   //lea las cantidades, recuerde que debe estar validado
   cantidad = leerEnteroPositivo("");
   compras[i] = cantidad;


  }
}

void ingresarDescuento(float descuentos[],char empresas[][MAXCOL],int canEmpresas){
  int i;
  float descuento;
  for(i=0; i < canEmpresas;i++){
    printf("\nPorcentaje descuento empresa %s",empresas[i]);
    descuento = leerFlotantePositivo("");
    descuentos[i]=descuento;


  }
}
void calcularPrecioProforma(float precios[][MAXCOL], int compras[], float preciosTotales[], float descuentos[],int cantEmpresas,int cantProductos){
    float total;
    for(int col = 0; col <cantEmpresas; col++){
      total = 0;
      for(int fil = 0; fil < cantProductos; fil++){
        total += precios[fil][col]*compras[fil];

      }
      preciosTotales[col] = total;
    }

    //calcular los totales de venta 
    for(int i =0; i < cantEmpresas;i++){
      if(preciosTotales[i] >1200)
        preciosTotales[i] = preciosTotales[i]-preciosTotales[i]*descuentos[i]/100;
    }

    //calcular los descuentos

}
int mejorEmpresaPrecio(float preciosTotales[], int cantEmpresas){
  float mejor = preciosTotales[0];
  int indiceMejor = 0;
  for(int i =0; i < cantEmpresas;i++){
    if(preciosTotales[i] < mejor){
      mejor = preciosTotales[i];
      indiceMejor = i;
    }

  }
return indiceMejor;
}

void mostrarValoresPagoEmpresa(char empresas[][MAXCOL],float preciosTotales[],int cantidadEmpresas){
    for(int i=0; i<cantidadEmpresas;i++){
        printf("\nEmpresa %s,  valor a pagar %.2f ",empresas[i],preciosTotales[i]);

    }
}

void ingreseStockEmpresas( int stockEmp[MAXFILA][MAXCOL], int cantEmpresas,int cantProductos, char empresas[][MAXCOL],char productos[][MAXCOL] ){
       int i,j;
       int cant;

    for(i = 0; i < cantProductos; i++){
        printf("\n ingrese la cantidad de %s existentes en el inventario",productos[i]);
        for(j = 0; j < cantEmpresas; j++){
             printf(" de la Empresa %s\n",empresas[j]);
                cant= leerEnteroPositivo("");
                stockEmp[i][j] = cant;
       }
    }
}

void imprimirStockEmpresas( int stockEmp[MAXFILA][MAXCOL], int cantEmpresas,int cantProductos, char empresas[][MAXCOL],char productos[][MAXCOL] ){
    int i,j;
    for(i = 0; i < cantEmpresas; i++){
    printf("\nEmpresa %s",empresas[i]);
        for(j = 0; j < cantProductos; j++){
            printf("\n%s\t cantidad de unidades existentes %d",productos[j],stockEmp[j][i]);
        }
    }
}

void restarCompraDelStock(int stockEmp[MAXFILA][MAXCOL], int stockCompras[MAXFILA][MAXCOL], int compras[], int cantEmpresas,int cantProductos, char empresas[][MAXCOL],char productos[][MAXCOL]){
    int i,j;
    for(i = 0; i < cantEmpresas; i++){
        printf("\n de la empresa %s",empresas[i]);
        for(j = 0; j < cantProductos; j++){
            stockCompras[i][j]=stockEmp[i][j]-compras[i];
            printf("\n Quedan %d productos de tipo %s\n",  stockCompras[j][i], productos[j]);
        }
    }
}



void editarProducto(char productos[][MAXCOL], int cantidadProductos) {
    int indice;
    printf("\nIngrese el índice del producto a editar (entre 0 y %d): ", cantidadProductos - 1);
    scanf("%d", &indice);

    if (indice >= 0 && indice < cantidadProductos) {
        printf("Ingrese el nuevo nombre del producto: ");
        scanf("%s", productos[indice]);
        printf("Producto editado exitosamente.\n");
    } else {
        printf("Índice inválido.\n");
    }
}

void eliminarProducto(char productos[][MAXCOL], float precios[][MAXCOL], int *cantidadProductos, int cantidadEmpresas) {
    int indice;
    printf("\nIngrese el índice del producto a eliminar (entre 0 y %d): ", *cantidadProductos - 1);
    scanf("%d", &indice);

    if (indice >= 0 && indice < *cantidadProductos) {
        // Desplazamos los productos y precios hacia atrás para eliminar el producto
        for (int i = indice; i < *cantidadProductos - 1; i++) {
            strcpy(productos[i], productos[i + 1]);
            for (int j = 0; j < cantidadEmpresas; j++) {
                precios[i][j] = precios[i + 1][j];
            }
        }
        (*cantidadProductos)--;
        printf("Producto eliminado exitosamente.\n");
    } else {
        printf("Índice inválido.\n");
    }
}