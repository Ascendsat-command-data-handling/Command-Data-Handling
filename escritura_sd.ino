#include <SPI.h>
#include <SD.h>
int Lectura_bateria = D13;
float bt;
float bl;
const int chipSelect = D5;
void setup() {
  pinMode(Lectura_bateria, INPUT);
  Serial.begin(9600);
  while (!Serial) {
    ; // Espera a que la consola serial se abra
  }
  Serial.print("Inicializando tarjeta SD...");
  if (!SD.begin(chipSelect)) {
    Serial.println("Falló al inicializar la tarjeta SD.");
    return;
  }
  Serial.println("Tarjeta SD lista.");
  // Crear un nuevo archivo
  File dataFile = SD.open("datos.txt", FILE_WRITE);
  if (dataFile) {
    Serial.println("Guardando datos...");
    dataFile.println("Inicio de registro de datos:");
    dataFile.close();
    Serial.println("Datos guardados.");
  } else {
    Serial.println("Error al abrir el archivo para escritura.");
  }
}
void loop() {
  bt = analogRead(Lectura_bateria);
  bl = bt * (3.3 + 5.1) / 5.1;
  // Abre el archivo
  File dataFile = SD.open("datos.txt", FILE_WRITE);
  if (dataFile) {
    // Escribe en el archivo
    dataFile.println("Voltaje de la batería: " + String(bl));
    dataFile.close();
  } else {
    Serial.println("Error al abrir el archivo para escritura.");
  } 
  delay(1000);
}