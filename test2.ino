int led = D7; // LED is connected to D0
int pushButton = D2; // Push button is connected to D2
int analogvalue = 0;
double tempC = 0;
char *message = "my name is particle";
String aString;


// This routine runs only once upon reset
void setup()
{
  pinMode(led, OUTPUT); // Initialize D0 pin as output
  pinMode(pushButton, INPUT_PULLUP);
  /*Particle.subscribe("hook-response/pushButtonState", myHandler, MY_DEVICES);*/
  // Initialize D2 pin as input with an internal pull-up resistor
}

// This routine loops forever
void loop()
{
  int pushButtonState;

  pushButtonState = digitalRead(pushButton);

  if(pushButtonState == LOW){ //If we push down on the push button
    digitalWrite(led, HIGH);  // Turn ON the LED
    /*Spark.publish("pushButtonState","Pressed",60,PRIVATE);*/
    Particle.publish("pushButtonState","Pressed", 60, PRIVATE);
    // Add a delay to prevent getting tons of emails from IFTTT
    delay(5000);
  }
  else
  {
    Particle.publish("pushButtonState","Unpressed", 60, PRIVATE);
    digitalWrite(led, LOW);   // Turn OFF the LED
  }

}

void myfunction(int params) {
  digitalWrite(led, HIGH);
}
