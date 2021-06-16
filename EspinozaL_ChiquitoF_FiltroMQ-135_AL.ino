/ *
* Filtro MQ_135 AIRE LIMPIO
* /

# define  tam_sig  100        // tamaño de la señal de entrada
extern  double mq_135 [tam_sig]; // llamar a la señal
int senal;               // variable donde se guarda el resultado del filtro
doble promOri;          // variable donde se guarda promedio de la señal original
doble promFilt;         // variable donde se guarda promedio de la señal filtrada
doble salida [tam_sig];  // vector de salida
vector doble [ 5 ];       // vector que almacenar los datos de filtrado
void  mediana_filtro ( doble * sen_in, doble * salida_sen, int sen_tam, int filtro); // definir función
void  plot_signal ( vacío ); // metodo para imprimir la señal
 configuración vacía () {
  De serie. comenzar ( 9600 );  // Comunicación Serial
}
 bucle vacío () {
  gauss_filtro (( doble *) & mq_135 [ 0 ], ( doble *) & salida [ 0 ], ( int ) tam_sig, 5 ); // llamar al metodo gauss
  plot_signal (); // metodo para imprimir la señal
  SNR (); // Metodo SNR (ratio de ruido de la señal)
  retraso ( 150 );  // temporizador
}
// Filtro gaussiano
void  gauss_filtro ( doble * sig_in, doble * salida, int sig_tam, int filtrado) { // metodo gausssiano
int i, j, k; // variables
  for (k = 0 ; k <sig_tam; k ++) { // ciclo para el metodo de gauss
    vector [ 0 ] = sig_in [k + 0 ]; // remplazo de la señal a la posicion del vector uno
    vector [ 1 ] = sig_in [k + 1 ]; // remplazo de la señal a la posicion del vector dos
    vector [ 2 ] = sig_in [k + 2 ]; // remplazo de la señal a la posicion del vector tres
    vector [ 3 ] = sig_in [k + 3 ]; // remplazo de la señal a la posicion del vector cuatro
    vector [ 4 ] = sig_in [k + 4 ]; // remplazo de la señal a la posicion del vector cinco
    i = 0 ; // inicio de variable
    while (i <= 3 ) { // en la tercera posicion
      i ++; // aumento de valor
      j = i + 1 ; // valor de i + 1
      while (j <= 4 ) {
        j ++;
        if (vector [j] <vector [i]) { // si la posicion del vector es menor
          senal = vector [j]; // reemplaza el valor de la posicion del vector en la variable senal
            vector [j] = vector [i]; // si el vector es igual
            vector [i] = senal; // remplaza el valor de senal en vector [posicion]
        }
      }
    }
    salida [k] = vector [ 1 ]; // salida del resultado
  }
  }
void  plot_signal ( void ) { // metodo para imprimir la señal
  int i; // variable
  for (i = 0 ; i <tam_sig; i ++) { // ciclo repetitivo para recorrer la señal
      De serie. imprimir (mq_135 [i]); // posicion del dato
      De serie. imprimir ( " , " );
      De serie. imprimir ((salida [i])); // salida del resultado señal metodo gauss
      De serie. println ( " , " );
    retraso ( 100 ); // temporizador
  }
}
// Metodo SNR
anular  SNR () {
  int i; // variable
  for (i = 0 ; i < 100 ; i ++) { // ciclo reccorre segun el numero de datos de la señal
    promOri = promOri + mq_135 [i]; // guarda los valores del promedio en cada punto
    }
   doble promOri1 = promOri / 100 ; // lo divide para el numero de datos de la señal
   para (i = 0 ; i < 100 ; i ++) {
    promFilt = promFilt + salida [i];
    }
   doble promFilt2 = promFilt / 100 ; // divide para el numero de datos de la señal filtrada
   doble vout = (promOri1 * 5 ) / 1023 ; // voltaje de salida
   vfilt doble = (promFilt2 * 5 ) / 1023 ; // voltaje de filtrado
   snr doble = 20 * log (vfilt / vout);
  De serie. println ( " " );
  De serie. println ( String ( " Promedio señal ingresada: " ) + String (promOri1));
  De serie. println ( String ( " Promedio señal filtrada: " ) + String (promFilt2));   
  De serie. println ( String ( " Voltaje de salida señal ingresada: " ) + String (vout));
  De serie. println ( String ( " Voltaje de salida señal filtrada: " ) + String (vfilt));
  De serie. println ( String ( " SNR: " ) + String (snr) + String ( " decibeles " ));   
  }
