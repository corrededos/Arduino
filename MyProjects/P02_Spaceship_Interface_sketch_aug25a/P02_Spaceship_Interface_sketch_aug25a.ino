int switchState = 0;

void setup() {
  // put your setup code here, to run once:
  pinMode(3,OUTPUT);
  pinMode(4,OUTPUT);
  pinMode(5,OUTPUT);
  pinMode(2,INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  
  //Check to se if there is any voltage on pin 2 with digital read, High = yes = switch (button) pressed, LOW = no = button not pressed. åäö
  
  //Read pin 2
  switchState = digitalRead(2);


  //Check return value
  if(switchState == LOW){ 
    // the button is not pressed
    digitalWrite(3,HIGH);  // green LED 
    digitalWrite(4,LOW);  // red LED 1 
    digitalWrite(5,LOW); // red LED 2 
  }
  else{ // the button is pressed
      digitalWrite(3,LOW);  // green LED 
      digitalWrite(4,LOW);  // red LED 1 
      digitalWrite(5,HIGH); // red LED 2  

      delay(250); // wait for a quarter second
      // toggle the leds
      digitalWrite(4,HIGH);  // red LED 1 
      digitalWrite(5,LOW); // red LED 2 
      delay(250); // wait for a quarter second
      
  }
}
