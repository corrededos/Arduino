int switchState = 0;

void setup() {
  // put your setup code here, to run once:
  pinMode(2,OUTPUT);
  pinMode(3,OUTPUT);
  pinMode(8,INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  
  //Check to se if there is any voltage on pin 2 with digital read, High = yes = switch (button) pressed, LOW = no = button not pressed.
  
  //Read pin 2
  switchState = digitalRead(8);


  //Check return value
  if(switchState == LOW){ 
    // the button is not pressed
    digitalWrite(2,LOW); 
    digitalWrite(3,LOW);  
  }
  else{ // the button is pressed
      digitalWrite(2,HIGH);  // green LED 
      digitalWrite(3,LOW);  // red LED 1 

      delay(250); // wait for a quarter second
      // toggle the leds
      digitalWrite(2,LOW);  // red LED 1 
      digitalWrite(3,HIGH); // red LED 2 
      delay(250); // wait for a quarter second
  }
}
