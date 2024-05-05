void setup() {
  // inicializa el pin del LED como salida
  pinMode(LED_BUILTIN, OUTPUT);
}

void loop() {
  digitalWrite(LED_BUILTIN, HIGH); // enciende el LED
  delay(500);                      // espera medio segundo (500 milisegundos)
  digitalWrite(LED_BUILTIN, LOW);  // apaga el LED
  delay(500);                      // espera medio segundo
}
