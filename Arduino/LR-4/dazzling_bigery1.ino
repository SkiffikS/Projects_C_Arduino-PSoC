int sensorState = 0;
void setup()
{
pinMode(2, INPUT);
pinMode(13, OUTPUT);
  pinMode(12, OUTPUT);
Serial.begin(9600);
}
void loop()
{
sensorState = digitalRead(2);
if(sensorState == HIGH) {
  digitalWrite(13, LOW);
digitalWrite(12, HIGH);
Serial.println("Sensor activated!");
} else {
digitalWrite(12, LOW);
digitalWrite(13, HIGH);
}
delay(1000);
}
  