int Lectura_bateria=13;
float bt;
float bl;

void setup() {
  pinMode(Lectura_bateria,INPUT);
  Serial.begin(9600);
}
void loop() {
  bt = analogRead(Lectura_bateria); // Lectura analógica  
  bl = bt *(3.3+5.1)/5.1; // Calculo voltaje
  Serial.print ("Voltaje Bateria: ");
  Serial.println(bl);
  delay(1000);
}