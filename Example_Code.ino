#include<servo.h>

//Declaring motor driver pin

//Motor A
int enableA = 11;
int mA1 = 12;
int mA2 = 13;

//Motor B
int enableB = 9;
int mB1 = 7;
int mB2 = 8;

//Pins of 2 IR sensors
int IRout1 = 10;
int IRout2 = 2;

//naming servo motor as my_servo
Servo my_servo;

//Declaring the trigger pin and echo pin of the ultrasonic sensor
int trigPin = 6;
int echoPin = 5;


void setup(){
//initialize variables of components

//connecting my_servo at pin 3
my_servo.attach(3);

//setting motorA and motorB as output
pinMode(enableA,OUTPUT);
pinMode(mA1,OUTPUT);
pinMode(mA2,OUTPUT);
pinMode(enableB,OUTPUT);
pinMode(mB1,OUTPUT);
pinMode(mB2,OUTPUT);
Serial.begin(9600);

//setting up the ultrasonic sensor
pinMode(trigPin,OUTPUT);
pinMode(echoPin,INPUT);

//setting up the 2 IR sensors
pinMode(IRout1,INPUT);
pinMode(IRout2,INPUT);
}

//Main loop
void loop(){
int IR1_value = digitalRead(IRout1);
int IR2_value = digitalRead(IRout2);

//ultrasonic sensor receiving data
digitalWrite(trigPin,HIGH);
delay(10);
digitalWrite(echoPin,LOW);
duration = pulseIn(echoPin,LOW);
distance = duration * (0.034/2);

//making the car spin slowly until it detects an object
while(distance<=45 or distance=0){
   digitalWrite(mA1, HIGH);
   digitalWrite(mA2, LOW);
   analogWrite(enableA,80);

   digitalWrite(mB1, LOW);
   digitalWrite(mB2, HIGH);
   analogWrite(enableB,80);
    
   delay(1000);
  }

//this if statement will start processing once an object is detected, the car will start moving towards the object 
 
if (distance<=45 && IR1_value=LOW && IR2_value=LOW){
    while(distance>=3 && IR1_value=LOW){
       digitalWrite(mA1, HIGH);
       digitalWrite(mA2, LOW);
       analogWrite(enableA,127);

       digitalWrite(mB1, HIGH);
       digitalWrite(mB2, LOW);
       analogWrite(enableB,127);
    }
//this if statement will stop the car when the object is less than 3cm away from the sensor
    if (distance<3){
       digitalWrite(mA1, LOW);
       digitalWrite(mA2, LOW);
       analogWrite(enableA,0);

       digitalWrite(mB1, LOW);
       digitalWrite(mB2, LOW);
       analogWrite(enableB,0);
       delay(1000);
//the servo will activate the slab which will scoop the object into the shovel 
       my_servo.write(180);
       delay(2000);

//when the object is carried, the car will start moving until the front part is out of the circle 
       while (IR1_value=LOW){
          digitalWrite(mA1, HIGH);
          digitalWrite(mA2, LOW);
          analogWrite(enableA,63);
          digitalWrite(mB1, HIGH);
          digitalWrite(mB2, LOW);
          analogWrite(enableB,63);
       }


//After that, the car will stop and dump the object 
       digitalWrite(mA1, LOW);
       digitalWrite(mA2, LOW);
       analogWrite(enableA,0);
       digitalWrite(mB1, LOW);
       digitalWrite(mB2, LOW);
       analogWrite(enableB,0);
       delay(1000);
       my_servo.write(0);
       delay(1500);

//The car will move backwards until its entire frame is back in the circle
       while(IR1_value=HIGH){
          digitalWrite(mA1, LOW);
          digitalWrite(mA2, HIGH);
          analogWrite(enableA,127);
          digitalWrite(mB1, LOW);
          digitalWrite(mB2, HIGH);
          analogWrite(enableB,127);           
       }
       digitalWrite(mA1, LOW);
       digitalWrite(mA2, LOW);
       analogWrite(enableA,0);
       digitalWrite(mB1, LOW);
       digitalWrite(mB2, LOW);
       analogWrite(enableB,0);
       delay(1000);              
    }

// this statement will start working when the car is accidentally out of the circle going towards an object   
    else if(IR1_value = HIGH){

       //the car will move backwards to be back in the circle
       while(IR1_value=HIGH && IR2_value=LOW){  
           digitalWrite(mA1, LOW);
           digitalWrite(mA2, HIGH);
           analogWrite(enableA,127);
           digitalWrite(mB1, LOW);
           digitalWrite(mB2, HIGH);
           analogWrite(enableB,127);
       }

       //then it will stop
       digitalWrite(mA1, LOW);
       digitalWrite(mA2, LOW);
       analogWrite(enableA,0);
       digitalWrite(mB1, LOW);
       digitalWrite(mB2, LOW);
       analogWrite(enableB,0);
       delay(1000); 
    }
  }
}
 


