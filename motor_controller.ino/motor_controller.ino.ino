/*
 * motor controller
 * 
 * TODO:
 * 1. it would be nice to have different modes somehow
 * 
 * uses: arduino pro mini (the 3V one)
 * 
 */

static const uint8_t analog_pins[] = {A0,A1,A2,A3};
static const uint8_t digital_pins[] = {3,5,6,9};
static const uint8_t pot_vals[] = {0,0,0,0};
static const uint8_t motor_vals[] = {0,0,0,0};

void setup() {
  
  Serial.begin(9600);
  
  // setup analog inputs
  for( int i=0; i < 4; i++ ) {
    pinMode( analog_pins[i], INPUT );
  }

  // setup digital outputs
  for( int i=0; i < 4; i++ ) {
    pinMode( digital_pins[i], OUTPUT );
  }
}

void loop() {
  
  for( int i=0 i < 4; i++ ){
    pot_vals[i] = analogRead(analog_pins[i]);
    motor_vals[i] = map(pot_vals[i], 0, 1023, 0, 255 );
    analogWrite(analog_pins[i], motor_vals[i] );
  }

  delay(2);
}
