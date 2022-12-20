#include <SoftwareSerial.h>
SoftwareSerial BTSerial(3,5);
int LED=4;
int TRIG=10;
int ECO=9;
int DURACION;
int DISTANCIA;
char cstr[16];

void setup() {
  pinMode(LED, OUTPUT);
  BTSerial.begin(9600);
  pinMode(TRIG,OUTPUT);
  pinMode(ECO,INPUT);
  pinMode(LED,OUTPUT);
  Serial.begin(9600);

}

void loop() {
  // Lectura del sensor
  analogWrite(TRIG,HIGH);
  delay(1);
  analogWrite(TRIG,LOW);
  DURACION=pulseIn(ECO,HIGH);
  DISTANCIA=DURACION / 58.2;
  //Serial.println(DISTANCIA);

  // Conversion de datos a texto
  itoa(DISTANCIA, cstr, 10);

  // Envio de datos
  BTSerial.write("Valor de la distancia: ");
  BTSerial.write(cstr);
  BTSerial.write("\n");
    
  delay(666);

  
  // Lectura de datos recibidos
  if(BTSerial.available()){
    String message = BTSerial.readStringUntil('\n');
    Serial.println(message);
  }
}
