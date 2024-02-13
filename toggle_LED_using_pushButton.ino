
const int BUTTON_PIN = 12;  // GPIO pin 12 for button
const int LED_PIN    = 2;   // GPIO pin 2 for LED  

int ledState = LOW;        //current state of LED  is off
int lastButtonState;        // previous state of button
int currentButtonState;   //current state of button
  
void setup() {
  Serial.begin(115200);                        
  pinMode(BUTTON_PIN, INPUT);  // set GPIO 12 pin to input mode for button
  pinMode(LED_PIN, OUTPUT);      // set GPIO 2 pin to output mode for LED
  
  currentButtonState = digitalRead(BUTTON_PIN); // current value is low for pin 12
}
  
void loop() {
  lastButtonState    = currentButtonState;                // save the last state of button press
  currentButtonState = digitalRead(BUTTON_PIN); // read new state after pressing button
  
  if(lastButtonState == HIGH && currentButtonState == LOW) {    
    Serial.print("The button is pressed: ");
  
    // toggle state of LED
    if(ledState == LOW) {
       ledState = HIGH;  
       Serial.println("Turning LED on");
    }
    else {
      ledState = LOW;
      Serial.println("Turning LED off");
    } 
    
    digitalWrite(LED_PIN, ledState);  //turns the LED on or off based on state
  }
}