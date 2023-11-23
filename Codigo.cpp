//Variables sensor ultrasónico y barra LED
int LED1 = 22;
int LED2 = 23;
int LED3 = 24;
int LED4 = 25;
int LED5 = 26;
int LED6 = 27;
int LED7 = 28;
int LED8 = 29;
int LED9 = 30;
int LED10 = 31;
int TRG = 3;
int ECO = 2;
int DURACION;
int DISTANCIA;
//Variables direccionales y bocina
int ENTRADA1 = 11;
int ENTRADA2 = 12;
int ENTRADA3 = 10;
int IZQ = 7;
int DER = 6;
int ESTADO;
//Variables RFID
#include <MFRC522.h>
#include <SPI.h>
#define RST_PIN         5
#define SS_PIN          53
MFRC522 mfrc522(SS_PIN, RST_PIN);
const int pirPin = 9;
bool sistemaActivado = false;
const int BOC = 4;
void setup() {
  //Ultrasónico
  pinMode(LED1, OUTPUT);
  pinMode(LED2, OUTPUT);
  pinMode(LED3, OUTPUT);
  pinMode(LED4, OUTPUT);
  pinMode(LED5, OUTPUT);
  pinMode(LED6, OUTPUT);
  pinMode(LED7, OUTPUT);
  pinMode(LED8, OUTPUT);
  pinMode(LED9, OUTPUT);
  pinMode(LED10, OUTPUT);
  pinMode(TRG, OUTPUT);
  pinMode(ECO, INPUT);
  //Direccionales
  pinMode(ENTRADA1, INPUT);
  pinMode(ENTRADA2, INPUT);
  pinMode(ENTRADA3, INPUT);
  pinMode(IZQ, OUTPUT);
  pinMode(DER, OUTPUT);
  pinMode(BOC, OUTPUT);
  //RFID
  pinMode(BOC, OUTPUT);
  Serial.begin(9600);
  SPI.begin();
  mfrc522.PCD_Init();
  pinMode(pirPin, INPUT); 
}
void loop() {
  //Ciclo sensor ultrasónico
  digitalWrite(TRG, HIGH);
  delay(1);
  digitalWrite(TRG, LOW);
  DURACION = pulseIn(ECO, HIGH);
  DISTANCIA = DURACION / 58.2;
  delay(200);
  if(DISTANCIA > 200){ 
    digitalWrite(LED10, LOW);
    digitalWrite(LED9, LOW);
    digitalWrite(LED8, LOW);
    digitalWrite(LED7, LOW);
    digitalWrite(LED6, LOW);
    digitalWrite(LED5, LOW);
    digitalWrite(LED4, LOW);
    digitalWrite(LED3, LOW);
    digitalWrite(LED2, LOW);
    digitalWrite(LED1, LOW);}
  if(DISTANCIA <= 200 && DISTANCIA >= 180){ 
    digitalWrite(LED10, LOW);
    digitalWrite(LED9, LOW);
    digitalWrite(LED8, LOW);
    digitalWrite(LED7, LOW);
    digitalWrite(LED6, LOW);
    digitalWrite(LED5, LOW);
    digitalWrite(LED4, LOW);
    digitalWrite(LED3, LOW);
    digitalWrite(LED2, LOW);
    digitalWrite(LED1, HIGH);}
  if(DISTANCIA < 180 && DISTANCIA >= 160){
    digitalWrite(LED10, LOW);
    digitalWrite(LED9, LOW);
    digitalWrite(LED8, LOW);
    digitalWrite(LED7, LOW);
    digitalWrite(LED6, LOW);
    digitalWrite(LED5, LOW);
    digitalWrite(LED4, LOW);
    digitalWrite(LED3, LOW);
    digitalWrite(LED2, HIGH);
    digitalWrite(LED1, HIGH);}
  if(DISTANCIA <160 && DISTANCIA >= 140){
    digitalWrite(LED10, LOW);
    digitalWrite(LED9, LOW);
    digitalWrite(LED8, LOW);
    digitalWrite(LED7, LOW);
    digitalWrite(LED6, LOW);
    digitalWrite(LED5, LOW);
    digitalWrite(LED4, LOW);
    digitalWrite(LED3, HIGH);
    digitalWrite(LED2, HIGH);
    digitalWrite(LED1, HIGH);}
  if(DISTANCIA <140 && DISTANCIA >= 120){
    digitalWrite(LED10, LOW);
    digitalWrite(LED9, LOW);
    digitalWrite(LED8, LOW);
    digitalWrite(LED7, LOW);
    digitalWrite(LED6, LOW);
    digitalWrite(LED5, LOW);
    digitalWrite(LED4, HIGH);
    digitalWrite(LED3, HIGH);
    digitalWrite(LED2, HIGH);
    digitalWrite(LED1, HIGH);}
  if(DISTANCIA <120 && DISTANCIA >= 100){
    digitalWrite(LED10, LOW);
    digitalWrite(LED9, LOW);
    digitalWrite(LED8, LOW);
    digitalWrite(LED7, LOW);
    digitalWrite(LED6, LOW);
    digitalWrite(LED5, HIGH);
    digitalWrite(LED4, HIGH);
    digitalWrite(LED3, HIGH);
    digitalWrite(LED2, HIGH);
    digitalWrite(LED1, HIGH);}
  if(DISTANCIA <100 && DISTANCIA >= 80){
    digitalWrite(LED10, LOW);
    digitalWrite(LED9, LOW);
    digitalWrite(LED8, LOW);
    digitalWrite(LED7, LOW);
    digitalWrite(LED6, HIGH);
    digitalWrite(LED5, HIGH);
    digitalWrite(LED4, HIGH);
    digitalWrite(LED3, HIGH);
    digitalWrite(LED2, HIGH);
    digitalWrite(LED1, HIGH);}
  if(DISTANCIA <80 && DISTANCIA >= 60){
    digitalWrite(LED10, LOW);
    digitalWrite(LED9, LOW);
    digitalWrite(LED8, LOW);
    digitalWrite(LED7, HIGH);
    digitalWrite(LED6, HIGH);
    digitalWrite(LED5, HIGH);
    digitalWrite(LED4, HIGH);
    digitalWrite(LED3, HIGH);
    digitalWrite(LED2, HIGH);
    digitalWrite(LED1, HIGH);}
  if(DISTANCIA < 60 && DISTANCIA >= 40){
    digitalWrite(LED10, LOW);
    digitalWrite(LED9, LOW);
    digitalWrite(LED8, HIGH);
    digitalWrite(LED7, HIGH);
    digitalWrite(LED6, HIGH);
    digitalWrite(LED5, HIGH);
    digitalWrite(LED4, HIGH);
    digitalWrite(LED3, HIGH);
    digitalWrite(LED2, HIGH);
    digitalWrite(LED1, HIGH);}
  if(DISTANCIA < 40 && DISTANCIA >= 20){
    digitalWrite(LED10, LOW);
    digitalWrite(LED9, HIGH);
    digitalWrite(LED8, HIGH);
    digitalWrite(LED7, HIGH);
    digitalWrite(LED6, HIGH);
    digitalWrite(LED5, HIGH);
    digitalWrite(LED4, HIGH);
    digitalWrite(LED3, HIGH);
    digitalWrite(LED2, HIGH);
    digitalWrite(LED1, HIGH);}
  if(DISTANCIA < 20 && DISTANCIA >= 0){
    digitalWrite(LED10, HIGH);
    digitalWrite(LED9, HIGH);
    digitalWrite(LED8, HIGH);
    digitalWrite(LED7, HIGH);
    digitalWrite(LED6, HIGH);
    digitalWrite(LED5, HIGH);
    digitalWrite(LED4, HIGH);
    digitalWrite(LED3, HIGH);
    digitalWrite(LED2, HIGH);
    digitalWrite(LED1, HIGH);}
  //Ciclo direccionales
  if(digitalRead(ENTRADA1) == HIGH){
    ESTADO = 1;
  }
  else{
    digitalWrite(IZQ, HIGH);
    ESTADO = 0;
  }
  while(ESTADO == 1){
    digitalWrite(IZQ, LOW);
    delay(200);
    digitalWrite(IZQ, HIGH);
    delay(200);
    ESTADO = 0;
  } 
  if(digitalRead(ENTRADA2) == HIGH){
    ESTADO = 2;
  }
  else{
    digitalWrite(DER, HIGH);
    ESTADO = 0;
  }
    while(ESTADO == 2){
    digitalWrite(DER, LOW);
    delay(200);
    digitalWrite(DER, HIGH);
    delay(200);
    ESTADO = 0;
  }
  if (digitalRead(ENTRADA3)== HIGH){
  digitalWrite(BOC, LOW);
  }
  else{
  digitalWrite(BOC, HIGH);
 }
//Ciclo RFID
  if (!sistemaActivado) {
    if (leerTarjeta()) {
      sistemaActivado = true;
    }
  } else {
    if (digitalRead(pirPin) == HIGH) {
      activarAlarma();
    } else {
      desactivarAlarma();
    }
    if (leerTarjeta()) {
      sistemaActivado = false;
    }
  }
}
bool leerTarjeta() {
  if (mfrc522.PICC_IsNewCardPresent() && mfrc522.PICC_ReadCardSerial()) {
    mfrc522.PICC_HaltA();
    return true;
  }
  return false;
}
void activarAlarma() {
  digitalWrite(DER, HIGH);
  digitalWrite(DER, HIGH);
  delay(200);
  digitalWrite(IZQ, LOW);
  digitalWrite(DER, LOW);
  delay(200);
}
void desactivarAlarma() {
  digitalWrite(IZQ, HIGH);
  digitalWrite(IZQ, HIGH); 
}