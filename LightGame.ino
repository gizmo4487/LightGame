// Sample configuration for LEDs
/*int greenL1 = 2;
int greenL2 = 3;
int yellowL1 = 4;
int yellowL2 = 5;
int red = 6;
int yellowR2 = 7;
int yellowR1 = 8;
int greenR2 = 9;
int greenR1 = 10;*/
int button = 0; // Initialize button state
int light = 0;  // Initialize LED pin
void setup() {
  // put your setup code here, to run once:
  
  /* Lights are on pins 2-10, and button is on pin 11 */
  
  for(int i=2;i<11;i++){
    pinMode(i,OUTPUT);
  }
  pinMode(11,INPUT);
  
 // Start serial communication with baud rate 115,200 
 Serial.begin(115200);
 Serial.println("Begin!");
}

void loop() {
  // put your main code here, to run repeatedly:
  /* Cycle LEDs */
  for(int i=2; i<11; i++){
    light = i;  // Set LED pin to i
    button = digitalRead(11); // Read button state
    digitalWrite(light,HIGH); // Turn on LED at pin "light"
    
    /* Sample button 75 times */
    for(int j=0;j<75;j++){
      Serial.println(button); // Print button state (0 or 1) to serial monitor

      /* Flash current LED 4 times if the button is pressed */
      if(button==1){
        for(int k=0; k<4; k++){
          digitalWrite(light,LOW);
          delay(200);
          digitalWrite(light,HIGH);
          delay(200);
        }
        while(button==1){
          button = digitalRead(11); // Wait until button state is 0 before continuing
        }
        digitalWrite(light,LOW);  // Turn off LED
        delay(3000);  // Wait 3 seconds
      }
      delay(1); // Wait 1 ms
    }
    
    
    digitalWrite(light,LOW);  // Turn off LED and move to the next LED
  }
  

}
