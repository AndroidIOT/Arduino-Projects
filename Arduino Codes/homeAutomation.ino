String voice;

int led1 = 2, //Connect LED 1 To Pin #2 
int led2 = 3, //Connect LED 2 To Pin #3 
int led3 = 4, //Connect LED 3 To Pin #4 
int led4 = 5, //Connect LED 4 To Pin #5 
int buzz = 6; //Connect Buzzer 5 To Pin #6 
  
void allon(){
     digitalWrite(led1, HIGH); 
     digitalWrite(led2, HIGH); 
     digitalWrite(led3, HIGH); //Function to turn oll the components on
     digitalWrite(led4, HIGH); 
     digitalWrite(buzz, HIGH); 
}
void alloff(){
     digitalWrite(led1, LOW); 
     digitalWrite(led2, LOW); 
     digitalWrite(led3, LOW); //Function to turn all components off
     digitalWrite(led4, LOW); 
     digitalWrite(buzz, LOW);
}
void setup() {
  Serial.begin(9600);      //9600 is the baud rate 
  pinMode(led1, OUTPUT); 
  pinMode(led2, OUTPUT); 
  pinMode(led3, OUTPUT); 
  pinMode(led4, OUTPUT); 
  pinMode(buzz, OUTPUT); 
}

void loop() {
  while (Serial.available()){  //Check if there is an available byte to read
  delay(10); //Delay added to make thing stable
  char c = Serial.read(); //Conduct a serial read
  if (c == '#') {break;} //Exit the "WHILE" loop when the # is detected after the word
  voice += c; //Shorthand for voice = voice + c
  }  
  if (voice.length() > 0) {
    //Serial.println(voice);
       if(voice == "*all on") {allon();}  //Turn Off All Pins (Call Function)
  else if(voice == "*all off"){alloff();} //Turn On  All Pins (Call Function)

  //Turning all pins on, one by one
     
  else if(voice == "*TV on") {digitalWrite(led1, HIGH);} 
  else if(voice == "*fan on") {digitalWrite(led2, HIGH);} //Try changing the commands 
  else if(voice == "*computer on") {digitalWrite(led3, HIGH);}
  else if(voice == "*bedroom lights on") {digitalWrite(led4, HIGH);}
  else if(voice == "*bathroom lights on") {digitalWrite(buzz, HIGH);}
  
  //Turning all pins off, one by one
  
  else if(voice == "*TV off") {digitalWrite(led1, LOW);} 
  else if(voice == "*fan off") {digitalWrite(led2, LOW);}
  else if(voice == "*computer off") {digitalWrite(led3, LOW);}
  else if(voice == "*bedroom lights off") {digitalWrite(led4, LOW);}
  else if(voice == "*bathroom lights off") {digitalWrite(buzz, LOW);}
//-----------------------------------------------------------------------//  
voice="";}} //Reset the string after so as to make it ready for next input
