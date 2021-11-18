//GLOBALS
   byte sum = 0;
   
void printStatus(byte number)
{

    Serial.print("current number is: ");
    Serial.print(number, BIN);
    Serial.print("\n");
}

void printStatus(byte number, byte placeValue)
{

    Serial.print("current number is: ");
    Serial.print(number, BIN);
    Serial.print("\n");

    Serial.print("current placeValue is: ");
    Serial.print(placeValue);
    Serial.print("\n"); 

}

void displayLED(byte number)
{

  byte placeValue;

  for(placeValue = 3; placeValue < 11; placeValue++)
  {
    //print status of current loop
    //printStatus(number, placeValue);
    
    //checks if LSB is a 1
    bool compareBit = number & 0b0000001;

   //writes that value to the current LSB's place value
    digitalWrite(placeValue, compareBit);

   //shifts over number 1 bit
    int Temp = number >> 1;
    number = Temp;

   //print number after shift
   //printStatus(number);
    
  }
    
  
}


void setup() {
  // put your setup code here, to run once:

  //POWER
  pinMode(2, OUTPUT);
  digitalWrite(2, HIGH);

  //LEDS
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(8, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(10, OUTPUT);

  //BUTTON
  pinMode(12, INPUT);

 //SERIAL
  Serial.begin(9600);

  //LED TEST
  /*
  digitalWrite(LED1, HIGH);
  digitalWrite(LED2, HIGH);
  digitalWrite(LED3, HIGH);
  digitalWrite(LED4, HIGH);
  digitalWrite(LED5, HIGH);
  digitalWrite(LED6, HIGH);
  digitalWrite(LED7, HIGH);
  digitalWrite(LED8, HIGH);
  */

  //LED SET

  digitalWrite(3, LOW);
  digitalWrite(4, LOW);
  digitalWrite(5, LOW);
  digitalWrite(6, LOW);
  digitalWrite(7, LOW);
  digitalWrite(8, LOW);
  digitalWrite(9, LOW);
  digitalWrite(10, LOW);
  
}

void loop() {
  // put your main code here, to run repeatedly:


  bool buttonPressed = digitalRead(12);

  if(buttonPressed)
  {

    sum++;
    Serial.print("button pressed");
    Serial.print("\n");
    delay(250);

    buttonPressed = 0;
     
  }

  /*
  Serial.print("current sum is: ");
  Serial.print(sum);
  Serial.print("\n"); 
  */

  //display current sum
  displayLED(sum);



}
