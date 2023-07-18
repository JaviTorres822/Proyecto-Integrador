#include <stdio.h>
#include <string.h>
#include "funciones.h"

#define MAXFILA 20
#define MAXCOL 30
#define MAXCC 10

FILE* datosclientes;

void ingresarClientes(char nombreCliente[], char cedula[]);

int main(void) {
 
  char empresas[MAXFILA][MAXCOL];
  char productos[MAXFILA][MAXCOL];
  float precios[MAXFILA][MAXCOL];
  int compras[MAXFILA];
  float descuentos[MAXFILA];
  float preciosTotales[MAXFILA] = {0};
  int stockEmpresas[MAXFILA][MAXCOL];
  char nombreCliente[MAXCOL];
  char cedula[MAXCC];
  int cantidadEmpresas;
  int cantidadProductos;
  int opcion;
  int n = 0;
  
  printf("-------------BIENVENIDOS AL COTIZADOR PICHUELOSTEC-------------------\n"); 
  do {
    printf("Elija la opcion deseada: \n1.- Ingresar datos y productos \n2.- Editar producto \n3.- Eliminar producto \n4.- Imprimir cotizacion\n");
    scanf("%d", &opcion);
    switch(opcion) {
      case 1: {
        ingresarClientes(nombreCliente, cedula);

        cantidadEmpresas = leerEnteroEntre("Ingrese cantidad de empresas ofertantes", 1, MAXFILA);
        cantidadProductos = leerEnteroEntre("Ingrese cantidad de productos", 1, MAXFILA);
        ingresarCadenas("Ingrese nombre empresas", empresas, cantidadEmpresas);
        ingresarCadenas("Ingrese nombre productos", productos, cantidadProductos);
        ingresarMatrizPrecios("ingrese valor", empresas, productos, precios, cantidadProductos, cantidadEmpresas);
        imprimirMatrizPrecios(empresas, productos, precios, cantidadProductos, cantidadEmpresas);
        ingresarDescuento(descuentos, empresas, cantidadEmpresas);
        ingresarCompras(compras, productos, cantidadProductos);
        printf("\nSi desea volver al menu principal ingrese 0 caso contrario ingrese cualquier otro numero entero");
        scanf("%d", &n);
        break;
      }
      
      case 2: {
        editarProducto(productos, cantidadProductos);
        printf("\nSi desea volver al menu principal ingrese 0, caso contrario ingrese cualquier otro número entero: \n");
        scanf("%d", &n);
        break;
      }
      
      case 3: {
        eliminarProducto(productos, precios, &cantidadProductos, cantidadEmpresas);
        printf("\nSi desea volver al menu principal ingrese 0, caso contrario ingrese cualquier otro número entero: \n");
        scanf("%d", &n);
        break;
      }
      
      case 4: {
        calcularPrecioProforma(precios, compras, preciosTotales, descuentos, cantidadEmpresas, cantidadProductos);
        mostrarValoresPagoEmpresa(empresas, preciosTotales, cantidadEmpresas);
        // Invoque a la función mejorEmpresaPrecio()
        int indiceMejor = mejorEmpresaPrecio(preciosTotales, cantidadEmpresas);
        // Imprima el nombre de la mejor empresa
        printf("\nLa mejor empresa es %s\n", empresas[indiceMejor]);
        // Imprima el valor a pagar
        printf("El valor a pagar es %.2f\n", preciosTotales[indiceMejor]);
        printf("\nSi desea volver al menu principal ingrese 0, caso contrario ingrese cualquier otro número entero: \n");
        scanf("%d", &n);
        break;
      }
 
      default: {
        printf("ERROR. Ingrese una opción válida.\n");
      }
    }
  } while(n == 0);
}


void ingresarClientes(char nombreCliente[], char cedula[]) {
    datosclientes = fopen("datosclientes.txt", "a");
    if (datosclientes == NULL) {
        printf("No se pudo abrir el archivo.\n");
    } else {
        printf("Ingrese su nombre: ");
        scanf("%s", nombreCliente);
        fprintf(datosclientes, "%s\n", nombreCliente);
      
        printf("Ingrese la cedula (10 caracteres): ");
        scanf("%s", cedula);
        if (strlen(cedula) != 10) {
            printf("Cedula invalida. Debe tener 10 caracteres.\n");
        } else {
            fprintf(datosclientes, "%s\n", cedula);
        }
    }
    fclose(datosclientes);
}