#include <Stepper.h> //including stepper motor library
#include <max6675.h>
//The volume of the container is depends on height only for constatnt radious.
//the total volume of the cotainer holds 10 injera and volume is 5.3litter 
//take radius 10cm for test program
int trigPin = 9;    // TRIG pin use auxily pins 
int echoPin = 8;    // ECHO pin
#define relaypin1 10
#define led 13 
#define buzzer 3
#define Motor1_step            54// using RAMP1.4 for all motors 
#define Motor1_dir             55
#define Motor1_Enable_PIN      38
#define Motor2_step             60 
#define Motor2_dir              61
#define Motor2_Enable_PIN       56
#define Motor3_step             46
#define Motor3_dir              48
#define Motor3_Enable_PIN       62
#define Motor4_step             26
#define Motor4_dir              28
#define Motor4_Enable_PIN       24
#define Motor5_step             36
#define Motor5_dir              34
#define Motor5_Enable_PIN       30
#define  RELAY_ENABLE           14
#define SO  31
#define CS  35
#define SCK 39
#define relaypin2 18
MAX6675 thermocouple(SO, CS,SCK);
float temp_c, temp_f;
float duration_us, distance_cm;
void setup() {
    Serial.begin (9600);
 pinMode(relaypin, OUTPUT);
  digitalWrite(relaypin1, HIGH); // initially relay is off state 
  // configure the trigger pin to output mode
  pinMode(trigPin, OUTPUT);
  // configure the echo pin to input mode
  pinMode(echoPin, INPUT);
   // setting motors output 
pinMode( Motor1_step, OUTPUT);
pinMode( Motor1_dir, OUTPUT);
pinMode(Motor1_Enable_PIN, OUTPUT);
pinMode( Motor2_step, OUTPUT);
pinMode( Motor2_dir, OUTPUT);
pinMode(Motor2_Enable_PIN, OUTPUT);
pinMode( Motor3_step, OUTPUT);
pinMode( Motor3_dir, OUTPUT);
pinMode(Motor3_Enable_PIN, OUTPUT);
pinMode( Motor4_step, OUTPUT);
pinMode( Motor4_dir, OUTPUT);
pinMode(Motor4_Enable_PIN, OUTPUT);
pinMode( Motor5_step, OUTPUT);
pinMode( Motor5_dir, OUTPUT);
pinMode(Motor5_Enable_PIN, OUTPUT);
pinMode(RELAY_ENABLE,OUTPUT); // RELAY PIN   
digitalWrite(RELAY_ENABLE,HIGH);
// Turn off motors - Initial state
digitalWrite(Motor1_dir, LOW);
digitalWrite(Motor2_dir, LOW);
digitalWrite(Motor3_dir, LOW);
digitalWrite(Motor4_dir, LOW);
digitalWrite(Motor5_dir, LOW);
digitalWrite(Motor1_Enable_PIN, LOW);
digitalWrite(Motor2_Enable_PIN, LOW);
digitalWrite(Motor3_Enable_PIN, LOW);
digitalWrite(Motor4_Enable_PIN, LOW);
digitalWrite(Motor5_Enable_PIN, LOW);
pinMode(relaypin, OUTPUT);
digitalWrite(relaypin, HIGH); // initially relay is off state 
}void loop() {
 temp_c = Thermocouple_read();
if(isnan(temp_c)){ }
if(temp_c>180){ 
digitalWrite(relaypin, LOW); // Turn LED off.   
delay(300);}
else if(temp_c<160){  
digitalWrite(relaypin, HIGH); }
delay(500); }
double Thermocouple_read() {
uint16_t v_out;
pinMode(CS, OUTPUT);
pinMode(SO, INPUT);
pinMode(SCK, OUTPUT);
digitalWrite(CS, LOW);
delay(1); 
v_out = shiftIn(SO, SCK, MSBFIRST);
v_out <<= 8;
v_out |= shiftIn(SO, SCK, MSBFIRST);
digitalWrite(CS, HIGH);
if (v_out & 0x4) { 
//Thermocouple is disconnected
return NAN; }
// The lower three bits (0,1,2) are discarded status bits
v_out >>= 3;
// The remaining bits are the number of 0.25 degree (C) counts
return v_out*0.2529;
  digitalWrite(Motor1_dir,HIGH);//MOTOR1
  for (int x =0; x<8300; x++){
    digitalWrite(Motor1_step,HIGH); 
    delayMicroseconds(20000); 
    digitalWrite(Motor1_step,LOW); 
    delayMicroseconds(20000);  }
    delay(100);
      digitalWrite(Motor2_dir, LOW);//MOTOR 2 polishing
  for (int x =0; x<550; x++){
    digitalWrite(Motor2_step,HIGH); 
    delayMicroseconds(70000); 
    digitalWrite(Motor2_step,LOW); 
    delayMicroseconds(70000);  }
    delay(1000);
  digitalWrite(Motor1_dir, LOW);//MOTOR 1
  for (int x =0; x<600; x++){
    digitalWrite(Motor1_step,HIGH); 
    delayMicroseconds(20000); 
    digitalWrite(Motor1_step,LOW); 
    delayMicroseconds(20000);}
    delay(100);
     digitalWrite(Motor2_dir, HIGH);//MOTOR 2 pouring
     digitalWrite(RELAY_ENABLE,HIGH);//open solenoid valve to allow passing of dough
  for (int x =0; x<550; x++){
    digitalWrite(Motor2_step,HIGH); 
    delayMicroseconds(70000); 
    digitalWrite(Motor2_step,LOW); 
    delayMicroseconds(70000);  }
    delay(1000);
    digitalWrite(RELAY_ENABLE,LOW);//Closed solenoid valve to cut passing of dough
    delay(14000);
   digitalWrite(Motor1_dir, LOW);//MOTOR 1
  for (int x =0; x<7700; x++){
    digitalWrite(Motor1_step,HIGH); 
    delayMicroseconds(20000); 
    digitalWrite(Motor1_step,LOW); 
    delayMicroseconds(20000);  }
    delay(100);
    //Rotate Motor 3…………..CCW for 5sec and stop to open the lid cover  NEW
  digitalWrite(Motor3_dir,HIGH);
  for (int x =0; x<100; x++){
    digitalWrite(Motor3_step,HIGH); 
    delayMicroseconds(900000); 
    digitalWrite(Motor3_step,LOW); 
    delayMicroseconds(900000);  }
    delay(1000);
    //Rotate Motor 3…………..CCW for 5sec and stop to open the lid cover  NEW
 digitalWrite(Motor3_dir,LOW);
  for (int x =0; x<100; x++){
    digitalWrite(Motor3_step,HIGH); 
    delayMicroseconds(900000); 
    digitalWrite(Motor3_step,LOW); 
    delayMicroseconds(900000);  }
    delay(1000);
    digitalWrite(Motor5_dir,HIGH);//MOTOR 5
  for (int x =0; x<45; x++){
    digitalWrite(Motor5_step,HIGH); 
    delayMicroseconds(90000); 
    digitalWrite(Motor5_step,LOW); 
    delayMicroseconds(90000);  }
    delay(1000);
     digitalWrite(Motor4_dir, LOW);//MOTOR 4
  for (int x =0; x<1650; x++){
    digitalWrite(Motor4_step,HIGH); 
    delayMicroseconds(1000); 
    digitalWrite(Motor4_step,LOW); 
    delayMicroseconds(1000);  }
   delay(1000);
    digitalWrite(Motor5_dir,HIGH);
  for (int x =0; x<20; x++){
    digitalWrite(Motor5_step,HIGH); 
    delayMicroseconds(190000); 
    digitalWrite(Motor5_step,LOW); 
    delayMicroseconds(190000);  }
    delay(1000);
    digitalWrite(Motor4_dir, HIGH);//MOTOR 4
  for (int x =0; x<1600; x++){
    digitalWrite(Motor4_step,HIGH); 
    delayMicroseconds(1000); 
    digitalWrite(Motor4_step,LOW); 
    delayMicroseconds(1000);  }
   delay(1000);
digitalWrite(Motor5_dir,LOW);
  for (int x =0; x<50; x++){
    digitalWrite(Motor5_step,HIGH); 
    delayMicroseconds(90000); 
    digitalWrite(Motor5_step,LOW); 
    delayMicroseconds(90000);  }
    delay(1000);
     digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW)
  // measure duration of pulse from ECHO pin
  duration_us = pulseIn(echoPin, HIGH);
  // calculate the distance
  distance_cm = 0.017 * duration_us;
  // print the value to Serial Monitor
  Serial.print("distance: ");
  Serial.print(distance_cm);
  Serial.println(" cm");
  delay(500);
if(distance_cm<5.1){ 
digitalWrite(led, HIGH); // Turn LED off. 
digitalWrite(buzzer,HIGH);  
digitalWrite(relaypin, HIGH);
delay(300);}
else if(distance_cm<1.7){  
digitalWrite(led, LOW); // Turn LED off. 
digitalWrite(buzzer,HIGH);  
digitalWrite(relaypin, LOW); 
 }
delay(500);
}
