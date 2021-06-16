/ *
 * MATRIZ DE CONFUSION
 * /

# incluir  " DatosPrueba.h "
# incluir  " DatosMatriz.h "

int vdP = 0 ;            // variables para valores matriz
int vdN = 0 ;
int fsP = 0 ;
int fsN = 0 ;

 configuración vacía () {
  De serie. comenzar ( 9600 );
  algConfusionKNN ();
}

 bucle vacío () {
 
}

void  algConfusionKNN () {
// variables para calcular parametros de la matriz
flotar exactitud;
precisión de flotación ;
flotador aux2;
flotador aux;
// recorrer matriz de datos y matriz de valores clasificados
    para ( int i = 0 ; i < 100 ; i ++) {
      // comparar etiquetas de resultados obtenidos mediante la clasificacion
      if (datosPrueba [i] [ 2 ] == matrizKNN [i] [ 2 ] && datosPrueba [i] [ 2 ] == 1 ) {
        vdP ++; // verdaderos positivos
      }
      if (datosPrueba [i] [ 2 ] == matrizKNN [i] [ 2 ] && datosPrueba [i] [ 2 ] == 2 ) {
        vdN ++; // verdaderos negativos
      }
      if (datosPrueba [i] [ 2 ]! = matrizKNN [i] [ 2 ] == 2 ) {
        fsP ++; // falsos positivos
      }
      if (datosPrueba [i] [ 2 ]! = matrizKNN [i] [ 2 ] == 1 ) {
        fsN ++; // falsos negativos       
      }  
    }
  // impresion de datos en serial
  De serie. println ( " Matriz de Confusion KNN " );
  De serie. println ( Cadena (vdP) + Cadena ( "  " ) + Cadena (fsP)); // matriz | vp | fp |
  De serie. println ( Cadena (fsN) + Cadena ( "  " ) + Cadena (vdN)); //        | fn | vn |
  exactitud = (vdP + fsP + fsN + vdN); // calculo esactitud
  aux = (vdP + vdN) / exactitud;
  precisión = vdP / (vdP + fsP); // caclculo precsisoin
  De serie. println ( String ( " Exactitud: " ) + String (aux * 100 ) + String ( " % " ));
  De serie. println ( String ( " Precisión: " ) + String (precisión * 100 ) + String ( " % " ));
  vdP = 0 ; fsP = 0 ; fsN = 0 ; vdN = 0 ;
  exactitud = 0 , aux = 0 ;
  precisión = 0 ; // reinicio de variables
  // recorrido matriz de prueba y matriz bayes
 para ( int i = 0 ; i < 100 ; i ++) {
      // evaluar etiquetas de clasificacion
      if (datosPrueba [i] [ 2 ] == matrizBY [i] [ 2 ] && datosPrueba [i] [ 2 ] == 1 ) {
        vdP ++; // verdaderos positivos
      }
      if (datosPrueba [i] [ 2 ] == matrizBY [i] [ 2 ] && datosPrueba [i] [ 2 ] == 2 ) {
        vdN ++; // verdaderos negativos
      }
      if (datosPrueba [i] [ 2 ]! = matrizBY [i] [ 2 ] == 2 ) {
        fsP ++; // falsos positivos
      }
      if (datosPrueba [i] [ 2 ]! = matrizBY [i] [ 2 ] == 1 ) {
        fsN ++; // falsos negativos   
      }  
    }
  // impresion
  De serie. println ( " Matriz de Confusion BAYES " );
  De serie. println ( Cadena (vdP) + Cadena ( "  " ) + Cadena (fsP));
  De serie. println ( Cadena (fsN) + Cadena ( "  " ) + Cadena (vdN));
  exactitud = (vdP + fsP + fsN + vdN); // caclulo exactitud
  aux = (vdP + vdN) / exactitud;
  De serie. println ( String ( " Exactitud: " ) + String (aux * 100 ) + String ( " % " ));
  precisión = vdP / (vdP + fsP); // caclulo precciison
  De serie. println ( String ( " Precisión: " ) + String (precisión * 100 ) + String ( " % " ));
vdP = 0 ; fsP = 0 ; fsN = 0 ; vdN = 0 ;
exactitud = 0 ;
aux = 0 , precisión = 0 ; // reinicio variables
}
