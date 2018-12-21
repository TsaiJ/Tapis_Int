const int LARGEUR = 10; 
const int LONGEUR = 13;
int mat [LARGEUR][LONGEUR];
float matv [LARGEUR][LONGEUR];
#include <SoftwareSerial.h>
SoftwareSerial mySerial(6,7);  //6 to ble tx, 7 to ble rx

void setup() {


  DDRD |= B11111100;   //Set pins 0-7 to output
  DDRB |= B00011111;   //Set pins 8-11 to output

  
  Serial.begin(9600);
  mySerial.begin(9600);

  
}

void loop() {
  // put your main code here, to run repeatedly:
  delay(200);
  setMux(6);
  setMux1(7);
  Serial.println(analogRead(0));


  for(int i = 0; i <=LONGUEUR; i++){
  setMux(i);
    for(int j = 0; j<LARGEUR ; j++){
      delay(5);
      mat[3-j][i] = rVelo(analogRead(i));
    }
  }
  
  //Envoie les valeurs des capteurs
  mySerial.write("n");
    for(int i = 0; i < LARGEUR; i++){
      for (int j = 0; j < LONGEUR; j ++){
        int t = mat[i][j];
    }
  }
  mySerial.write("t");

}


// Retoune une valeur associe avec un intervalle de resistance
int rVelo(int vo){
  float v = vo*0.0048758;
  if(v > 4.28){
    return 0;
  }else if(v > 3.33){
    return 1;
  }else if (v >1.875){
    return 2;
  }else
    return 3;
}

/**
 * NE PAS ENVOYER b > 7;
 * POUR LES setMUX
 */
void setMux(int b) {
   if(b/8 >0){
      digitalWrite(5, HIGH);
      b -=8;
    }else{
      digitalWrite(5, LOW);
    }
    if(b/4 >0){
      digitalWrite(4, HIGH);
      b-=4;
    }else{
      digitalWrite(4, LOW);
    }
    if(b/2 >0){
      digitalWrite(3, HIGH);
      b-=2;
    }else{
      digitalWrite(3, LOW);
    }
    if(b/1 >0){
      digitalWrite(2, HIGH);
    }else{
      digitalWrite(2, LOW);
    }
}


/**
 * NE PAS ENVOYER b > 7;
 */
void setMux1(int b){
  if(b/4 >0){
      digitalWrite(9, HIGH);
      b-=4;
    }else{
      digitalWrite(9, LOW);
    }
    if(b/2 >0){
      digitalWrite(10, HIGH);
      b-=2;
    }else{
      digitalWrite(10, LOW);
    }
    if(b/1 >0){
      digitalWrite(8, HIGH);
    }else{
      digitalWrite(8, LOW);
    }
   
    
}

void setMux2(int b){
  if(b/4 >0){
      digitalWrite(11, HIGH);
      b-=4;
    }else{
      digitalWrite(11, LOW);
    }
    if(b/2 >0){
      digitalWrite(12, HIGH);
      b-=2;
    }else{
      digitalWrite(12, LOW);
    }
    if(b/1 >0){
      digitalWrite(13, HIGH);
    }else{
      digitalWrite(13, LOW);
    }
}
