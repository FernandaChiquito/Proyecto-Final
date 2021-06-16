# incluye  < MsTimer2.h >  
# incluye  < avr / power.h > 
# incluye  < avr / sleep.h >  
# incluye < avr / wdt.h >

int mq135 = 0 ;
int mq7 = 0 ;
int aireLimpio = 8 ;
int aireConta = 9 ;

int tiempo = 300 ;
int cont = 0 ;

 configuración vacía () {
  De serie. comenzar ( 9600 );
  MsTimer2 :: set ( 1000 , reloj);
  power_adc_disable ();
  MsTimer2 :: inicio ();
  pinMode (aireLimpio, SALIDA);
  pinMode (aireConta, SALIDA);
  De serie. println ( " Recolección de datos " );
  digitalWrite (aireLimpio, BAJO);
  digitalWrite (aireConta, BAJO);
}

 bucle vacío () {
  retraso ( 500 );
  mq135 = analogRead (A0);
  mq7 = analogRead (A1);
 
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
void  reloj () {  
   cont ++; // cuenta cada segundo
   if (cont == tiempo) {
       power_adc_enable ();
       retraso ( 10 );
       De serie. println ( Cadena (mq135) + Cadena ( " , " ) + Cadena (mq7));  
       cont = 0 ;
    }
}
