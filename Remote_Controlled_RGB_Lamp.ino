#include <IRremote.h> //including a IRremote library
int RECV_PIN = 2; //declaring the var to pin 
int bluepin = 11; //declaring the var to pin
int greenpin = 10; //declaring the var to pin
int redpin= 9; //declaring the var to pin
IRrecv irrecv(RECV_PIN); 
decode_results results;

void setup() {//void setup
  // put your setup code here, to run once:
  Serial.begin(9600);
  
  irrecv.enableIRIn();
  pinMode(redpin,OUTPUT); // declaring redpin output
  pinMode(greenpin,OUTPUT);// declaring greenpin output
  pinMode(bluepin,OUTPUT);// declaring bluepin output
}

void loop() {
  // put your main code here, to run repeatedly:
  if(irrecv.decode(&results)){
    int value=results.value;
    Serial.println(value);
    switch(value){    //set the color red for button 1
      case 16:
      delay(50);
      analogWrite(redpin,0);// off
      analogWrite(greenpin,0);// off
      analogWrite(bluepin,0);// off
      delay(50);
      analogWrite(redpin,255);// off
      analogWrite(greenpin,0);// off
      analogWrite(bluepin,0);// on
    }
    switch(value){    //set the color green for button 2
      case 2064:
      delay(50);
      analogWrite(redpin,0);// off
      analogWrite(greenpin,0);// off
      analogWrite(bluepin,0);// off
      delay(50);
      analogWrite(redpin,0);// off
      analogWrite(greenpin,255);// on
      analogWrite(bluepin,0);// off
    }
    switch(value){    //set the color blue for button 3
      case 1040:
      delay(50);
      analogWrite(redpin,0);// off
      analogWrite(greenpin,0);// off
      analogWrite(bluepin,0);// off
      delay(50);
      analogWrite(redpin,0);// off
      analogWrite(greenpin,0);// off
      analogWrite(bluepin,255);// on
    }
    switch(value){    //set the color cyan for button 4 
      case 3088:
      delay(50);
      analogWrite(redpin,0);// off
      analogWrite(greenpin,0);// off
      analogWrite(bluepin,0);// off
      delay(50);
      analogWrite(redpin,0);// off
      analogWrite(greenpin,255);// on
      analogWrite(bluepin,255);// on
    }
    switch(value){    //set the color white for button 5
      case 528:
      delay(50);
      analogWrite(redpin,0);// off
      analogWrite(greenpin,0);// off
      analogWrite(bluepin,0);// off
      delay(50);
      analogWrite(redpin,255);// on
      analogWrite(greenpin,255);// on
      analogWrite(bluepin,255);// on
    }
    switch(value){    //set the color yellow for button 6
      case 2576:
      delay(50);
      analogWrite(redpin,0);// off
      analogWrite(greenpin,0);// off
      analogWrite(bluepin,0);// off
      delay(50);
      analogWrite(redpin,255);// on
      analogWrite(greenpin,255);// on
      analogWrite(bluepin,0);// off
    }
    switch(value){    //set the color purple for button 7
      case 1552:
      delay(50);
      analogWrite(redpin,0);// off
      analogWrite(greenpin,0);// off
      analogWrite(bluepin,0);// off
      delay(50);
      analogWrite(redpin,255);// on
      analogWrite(greenpin,0);// off
      analogWrite(bluepin,255);// on
    }
    switch(value){    //set the color pink for button 8
      case 3600:
      delay(50);
      analogWrite(redpin,0);// off
      analogWrite(greenpin,0);// off
      analogWrite(bluepin,0);// off
      delay(50);
      analogWrite(redpin,255);// on
      analogWrite(greenpin,0);// off
      analogWrite(bluepin,128);// siglity on
    }
    switch(value){    //set the color turn off
      case 2704:
      delay(50);
      analogWrite(redpin,0);// off
      analogWrite(greenpin,0);// off
      analogWrite(bluepin,0);// off
    }
    irrecv.resume();
  }
}
