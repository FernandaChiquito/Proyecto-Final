/ *
 * Programa Recoleccion de datos
 * Proyecto Final
 * Nombre: Lizbeth Espinoza
 * /

int mq135 = 0 ;
int mq7 = 0 ;
int aireLimpio = 8 ;
int aireConta = 9 ;

 configuración vacía () {
  pinMode (aireLimpio, SALIDA);
  pinMode (aireConta, SALIDA);
  De serie. comenzar ( 9600 );
  De serie. println ( " Recolección de datos " );
  digitalWrite (aireLimpio, BAJO);
  digitalWrite (aireConta, BAJO);
}

 bucle vacío () {
  retraso ( 500 );
  mq135 = analogRead (A0);
  mq7 = analogRead (A1);
  De serie. println ( Cadena (mq135) + Cadena ( " , " ) + Cadena (mq7));
  retraso ( 500 );
  si (mq135> 60 && mq135 < 200 ) {
    digitalWrite (aireLimpio, ALTO);
    digitalWrite (aireConta, BAJO);
    }
   si (mq135> 200 ) {
    digitalWrite (aireLimpio, BAJO);
    digitalWrite (aireConta, ALTO);
    }
    si (mq7> 130 && mq7 < 300 ) {
    digitalWrite (aireLimpio, ALTO);
    digitalWrite (aireConta, BAJO);
    }
    si (mq135> 300 ) {
    digitalWrite (aireLimpio, BAJO);
    digitalWrite (aireConta, ALTO);
    }
}
