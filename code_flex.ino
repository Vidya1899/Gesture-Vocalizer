//Constants:
const int ledPin = 3;   //pin 3 has PWM funtion
const int flexPin = A0; //pin A0 to read analog input

//Variables:
int value; //save analog value


void setup(){
  
  pinMode(ledPin, OUTPUT);  //Set pin 3 as 'output'
  Serial.begin(9600);       //Begin serial communication

}

void loop(){
  
  value = analogRead(flexPin);         //Read and save analog value from potentiometer
  //Serial.println(value);               //Print value
  value = map(value, 460, 710, 0, 255);//Map value 0-1023 to 0-255 (PWM)
  
         //Send PWM value to led
  delay(100);                          //Small delay

  if(value<=60)
    value=0;
  else if(value>80 && value<120){
    value=125;
  }
  else{
    value=255;
  }
  analogWrite(ledPin, value);  
  Serial.println(value);
}
