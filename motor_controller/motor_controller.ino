/*
  for loop test

   uses: arduino pro mini (the 3V one)

*/

static const uint8_t analog_pins[] = {A0, A1, A2, A3};
static const uint8_t digital_pins[] = {3, 5, 6, 9};
int pot_vals[] = {0, 0, 0, 0};
int val[] = {0, 0, 0, 0};
int range;


void setup() {

  Serial.begin(9600);

  // setup analog inputs
  for ( int i = 0; i < 4; i++ ) {
    pinMode( analog_pins[i], INPUT );
  }

  // setup digital inputs
  for ( int i = 0; i < 4; i++ ) {
    pinMode( digital_pins[i], OUTPUT );
  }

}


void loop() {

  for (int i = 0; i < 4; i++) {

    val[i] = analogRead(analog_pins[i]);
    analogWrite(digital_pins[i], map( val[i], 0, 1023, 0, 255 ));

  }

  delay(2);

}
