//I do not have or belong any credit of this code, majority of this sketch is based on the following link
//https://www.instructables.com/How-to-Make-Arduino-Sumo-Robot/
int trig = 3;
int echo = 4;
long time;
float distance;
const int IN1=6;
const int IN2=5;
const int IN3=9;
const int IN4=10;
#define IR_sensor_front A0 // front sensor

void setup() 
{
  pinMode(trig,OUTPUT);
  pinMode(echo,INPUT);
Serial.begin(9600);
delay (5000); 
digitalWrite(trig,LOW);
    delay(2);
    digitalWrite(trig,HIGH);
    delay(10);
    digitalWrite(trig,LOW);
    time = pulseIn(echo,HIGH);
    distance = time*0.034/2;
    delay(1000);
}
void loop()
{
  
 int IR_front = analogRead(IR_sensor_front);
 int IR_back = analogRead(IR_sensor_back);
 digitalWrite(trig,LOW);
    delay(2);
    digitalWrite(trig,HIGH);
    delay(10);
    digitalWrite(trig,LOW);
    time = pulseIn(echo,HIGH);
    distance = time*0.034/2;
    delay(100);
while(distance>50){

ROTATE(100);
    delay(100);
    Stop();
    delay(50);
    int IR_front = analogRead(IR_sensor_front);
    digitalWrite(trig,LOW);
    delay(2);
    digitalWrite(trig,HIGH);
    delay(10);
    digitalWrite(trig,LOW);
    time = pulseIn(echo,HIGH);
    distance = time*0.034/2;
    delay(50);

     if (IR_front > 650 ) 
   {
   Stop();
   delay (50);
   BACKWARD(85);
   delay (500);
   ROTATE(90);
   delay(1000);
   }
}  

  while(distance<=30){
     FORWARD(90);
     digitalWrite(trig,LOW);
    delay(2);
    digitalWrite(trig,HIGH);
    delay(10);
    digitalWrite(trig,LOW);
    time = pulseIn(echo,HIGH);
    distance = time*0.034/2;
    int IR_front = analogRead(IR_sensor_front);
     if (IR_front > 650 )
   {
   Stop();
   delay (50);
   BACKWARD(85);
   delay (500);
   ROTATE(90);
   delay(1000);
   }
   delay(100);
  }  
 if (IR_front > 650 ) 
   {
   Stop();
   delay (50);
   BACKWARD(85);
   delay (500);
   ROTATE(90);
   delay(1000);
   }
  else{
   Stop();
   delay (50);
   FORWARD(85);
   delay (500);
  }
 }
void FORWARD (int Speed){
  analogWrite(IN1,Speed);
  analogWrite(IN2,0);
  analogWrite(IN3,0);
  analogWrite(IN4,Speed);
}
void BACKWARD (int Speed){
  analogWrite(IN1,0);
  analogWrite(IN2,Speed);
  analogWrite(IN3,Speed);
  analogWrite(IN4,0);
}
void ROTATE (int Speed)
{
  analogWrite(IN1,Speed);
  analogWrite(IN2,0);
  analogWrite(IN3,Speed);
  analogWrite(IN4,0);
}
void Stop(){
  analogWrite(IN1,0);
  analogWrite(IN2,0);
  analogWrite(IN3,0);
  analogWrite(IN4,0);
}
