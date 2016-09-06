//By:ASpace
//Youtube channel:https://www.youtube.com/channel/UC9i2-Fy9IOo8yzypeB7Xpow
//Voice Activated Arduino (Bluetooth + Android)

String voice;
int  red = 2; //Connect LED 1 To Pin #2 
int green = 3; //Connect LED 2 To Pin #3 
int blue= 4; //Connect LED 3 To Pin #4 
 

void setup() {
  Serial.begin(9600);
  pinMode(red, OUTPUT); 
  pinMode(green, OUTPUT); 
  pinMode(blue, OUTPUT); 
  digitalWrite(red, HIGH); //This statement indicates that initally the Leds are off,since this a common anode configuration digitalWrite is HIGH.
  digitalWrite(green, HIGH); 
  digitalWrite(blue, HIGH); 
 
} 
void loop() {
  while (Serial.available()){  //Check if there is an available byte to read
  delay(10); //Delay added to make thing stable 
  char c = Serial.read(); //Conduct a serial read
  if (c == '#') {break;} //Exit the loop when the # is detected after the word
  voice += c; //Shorthand for voice = voice + c
  }  
  if (voice.length() > 0) {
    Serial.println(voice); 

  if(voice == "*all on") {allon();}  //Turn Off All Pins (Call Function)
  else if(voice == "*all off"){alloff();} //Turn On  All Pins (Call Function)
  

  else if(voice == "*red on") {digitalWrite(red, LOW);} 
  else if(voice == "*green on") {digitalWrite(green, LOW);}
  else if(voice == "*blue on") {digitalWrite(blue, LOW);}
  
  else if(voice == "*red") {digitalWrite(red, HIGH);} 
  else if(voice == "*green") {digitalWrite(green, HIGH);}
  else if(voice == "*blue") {digitalWrite(blue, HIGH);}
   
voice="";}} //Reset the variable after initiating

void allon()
{
     digitalWrite(red, LOW); 
     digitalWrite(green, LOW); 
     digitalWrite(blue, LOW);
     
}
void alloff()
{
     digitalWrite(red, HIGH); 
     digitalWrite(green, HIGH); 
     digitalWrite(blue, HIGH); 
}
