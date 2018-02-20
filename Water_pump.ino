/*
 * This code is authored by Dakota James Owen Keeler.
 * It is meant to regulate a water pump.
 * 
 *  The water_sensor needs 5v to run
 */
const short relyPin = 8;
const int water_sensor = A0;

// init the value used for the sensor
int water_sensor_value_in = 0; 
int water_sensor_value = 0;

void setup() {
  // initialize serial communications at 9600 bps:
  Serial.begin(9600);
  
  pinMode(relyPin, OUTPUT);
  pinMode(water_sensor, INPUT);
}

void loop() {
  water_sensor_value_in = analogRead(water_sensor); // reads our input
  water_sensor_value = map(water_sensor_value_in, 0, 1023, 0, 100);
  
  if (water_sensor_value < 19){
    Serial.println("Not in water");
    
    digitalWrite(relyPin, LOW);
    
  } else if (water_sensor_value > 30) {
    Serial.println("There is a lot of water");
    
    digitalWrite(relyPin, HIGH);
    delay(60000); // 1.5 minutes in milliseconds
    
  } else if (water_sensor_value < 25 && water_sensor_value > 20) {
    Serial.println("Water is draining, just making sure it is all gone");
    Serial.print("Sensor value = ");
    Serial.println(water_sensor_value);

    digitalWrite(relyPin, HIGH);
    delay(60000);
    digitalWrite(relyPin, LOW);
    
  }else{
    Serial.println("Something went wrong, should never be here");
    digitalWrite(relyPin, LOW);
    
  }

  // makes sure to shut the pump off after if statement.
  digitalWrite(relyPin, LOW);
  delay(2); // this is just a slight delay to keep it from going to fast.

}

