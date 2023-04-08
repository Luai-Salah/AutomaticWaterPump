#define POWER_PIN 7
#define GATE_PIN 8
#define SIGNAL_PIN A5

int value = 0; // variable to store the sensor's value

void setup()
{
  Serial.begin(9600);
  
  pinMode(POWER_PIN, OUTPUT); // configure D7 pin as an OUTPUT
  pinMode(GATE_PIN, OUTPUT); // configure D8 pin as an OUTPUT

  digitalWrite(POWER_PIN, HIGH); // turn the sensor ON
  digitalWrite(GATE_PIN, LOW); // turn the water pump OFF
}

void loop()
{
  value = analogRead(SIGNAL_PIN); // read the analog value from sensor

  Serial.print("Sensor Value: ");
  Serial.println(value); // print the sensor's value on the console

  if (value <= 50) // turn the water pump on if and only if the water level reaches 50 or below
    digitalWrite(GATE_PIN, HIGH);
  else if (value >= 300) // otherwise if it exceeds 300 stop the water pump
    digitalWrite(GATE_PIN, LOW);
}