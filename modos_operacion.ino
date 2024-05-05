
const int Lectura_bateria = D13; 
const float Umbral_bateria = 3.5; 
void setup() {
  pinMode(Lectura_bateria, INPUT);
  Serial.begin(9600);}
void loop() {
  float voltaje_bateria = leerVoltajeBateria(); 
  Serial.print("Voltaje de la batería: ");
  Serial.print(voltaje_bateria);
  Serial.println("V");
  if (voltaje_bateria < Umbral_bateria) {
    // Cambia al modo de ahorro de energía
    entrarModoAhorro();
  }
  delay(1000); }
float leerVoltajeBateria() {
  // Lee el voltaje de la batería
  int lectura_ADC = analogRead(Lectura_bateria);
  float voltaje = bt * (3.3 + 5.1) / 5.1;
  voltaje = voltaje * (5.0 / 1023.0);
  return voltaje;}
void entrarModoAhorro() {
  Serial.println("Entrando en el modo de ahorro de energía");
}

