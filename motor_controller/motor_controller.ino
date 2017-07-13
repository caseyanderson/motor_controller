/*
  for loop test

   uses: arduino pro mini (the 3V one)

*/

static const uint8_t analog_pins[] = {A0, A1, A2, A3};
static const uint8_t digital_pins[] = {3, 5, 6, 9};

void setup() {
  Serial.begin(9600);

  // setup inputs, outputs
  for ( int i = 0; i < 4; i++ ) {
    pinMode( analog_pins[i], INPUT );
    pinMode( digital_pins[i], OUTPUT );
  }
}

void loop() {
  for (int i = 0; i < 4; i++) {
    unsigned int val = analogRead(analog_pins[i]);
    analogWrite(digital_pins[i], val / 4);
  }
  delay(2);
}
