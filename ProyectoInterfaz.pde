procesamiento de importación.serie . * ;
 Puerto serial ;
int al = 170 ;
int r;
int r2, r3, r4;
int aux = 0 ;
flotar x, y;
int resultado;
PImage aireLImg;
PImage aireSImg;
 configuración vacía () {
Puerto  = nueva  serie ( este , " COM4 " , 9600 );
aireLImg = loadImage ( " airelimpio.png " ); // carga de imagenes
aireSImg = loadImage ( " airesucio.png " );
  tamaño ( 1200 , 800 );
  fondo ( 255 , 255 , 255 );
  
}

vacío  dibujar () {
    
  strokeWeight ( 3 );
  trazo (# DBD9D9 );
  línea ( 0 , 220 , 1200 , 220 );
  // linea de separacion
  strokeWeight ( 3 );
  trazo (# DBD9D9 );
  línea ( 300 , 220 , 300 , 800 );
  fondo ( 255 );
  llenar ( 0 );
  textSize ( 20 );
  texto ( " DATOS SENSORES " , 75 , 450 );
  texto ( " MQ135: " + r + " ppm " , 75 , 500 );
  texto ( " MQ7: " + r2 + " ppm " , 75 , 550 );
  
   // linea de separacion
  strokeWeight ( 3 );
  trazo (# DBD9D9 );
  línea ( 0 , 220 , 1200 , 220 );
  // linea de separacion
  strokeWeight ( 3 );
  trazo (# DBD9D9 );
  línea ( 300 , 220 , 300 , 800 );
  
  llenar ( 0 , 0 , 255 );
  textSize ( 45 );
  texto ( " UNIVERSIDAD TECNICA DEL NORTE " , 180 , 60 );
  
  llenar ( 0 );
  textSize ( 35 );
  texto ( " LIZBETH ESPINOZA - FERNANDA CHIQUITO " , 200 , 120 );
  
  si (r < 200 ) {
    imageMode ( ESQUINA );
    imagen (aireLImg, 500 , 300 , 350 , 350 );
    llenar ( 0 );
  textSize ( 20 );
  texto ( " AIRE LIMPIO " , 600 , 300 );
  } más {
    imageMode ( ESQUINA );
    imagen (aireSImg, 500 , 300 , 350 , 350 );
    llenar ( 0 );
  textSize ( 20 );
  texto ( " AIRE CONTAMINADO " , 600 , 300 );
  }
  
  //   si (r2 <200) {
  //   imageMode (ESQUINA);
  //   imagen (aireLImg, 500,300, 350,350);
  //   llenar (0);
  // tamaño del texto (20);
  // texto ("AIRE LIMPIO", 600,300);
  // } más {
  //   imageMode (ESQUINA);
  //   imagen (aireSImg, 500,300, 350,350);
  //   llenar (0);
  // tamaño del texto (20);
  // texto ("AIRE CONTAMINADO", 600,300);
  // }
  
  // si (r3 <200) {
  //   imageMode (ESQUINA);
  //   imagen (aireLImg, 500,300, 350,350);
  //   llenar (0);
  // tamaño del texto (20);
  // texto ("AIRE LIMPIO", 600,300);
  // } más {
  //   imageMode (ESQUINA);
  //   imagen (aireSImg, 500,300, 350,350);
  //   llenar (0);
  // tamaño del texto (20);
  // texto ("AIRE CONTAMINADO", 600,300);
  // }
  
  carrera ( 0 , 0 , 0 );
  llenar ( 255 , 255 , 255 );
  rect ( 350 , 290 , 80 , 500 );
  trazo ( 255 , 255 , 255 );
  llenar ( 255 , 0 , 255 );
  rect ( 350 , 500 + r, 80 , 290 - r);
  
}


void  serialEvent ( puerto serie  ) {
 si (aux == 0 ) {
      r = puerto . leer();
      println (r);
      aux ++ ;
    }
    más  si (aux == 1 ) {
      r2 = puerto . leer();
      println (r2);      
      aux ++ ;
    } más  si (aux == 2 ) {
      r3 = puerto . leer();
      println (r3);
      aux = 0 ;
    }
}
