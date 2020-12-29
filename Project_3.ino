// Project 3 - Whack-a-mole game
// Alex Eldaief

int LED_Y_1 = 5;      
int LED_Y_2 = 2;      
int LED_Y_3 = 7;
int BUTTON_1 = 0;  
int BUTTON_2 = 1;   
int BUTTON_3 = 8;
int LED_G = 4; 
int LED_R = 3;    
int MOTOR = 6;


void setup() {
  pinMode(LED_Y_1, OUTPUT);
  pinMode(LED_Y_2, OUTPUT);
  pinMode(LED_Y_3, OUTPUT);
  pinMode(BUTTON_1, INPUT_PULLUP);
  pinMode(BUTTON_2, INPUT_PULLUP);
  pinMode(BUTTON_3, INPUT_PULLUP);
  pinMode(LED_G, OUTPUT);
  pinMode(LED_R, OUTPUT);
  pinMode(MOTOR, OUTPUT);
  randomSeed(millis());     //initialize random number generator
}

void loop() {
  digitalWrite(MOTOR, LOW);
  if (random(3)==0) {  // random function returns a random integer between 0 and 2 
    Whack_mole(BUTTON_1, LED_Y_1);  // First light flashes
  }
  else if (random(3)==1) {  
    Whack_mole(BUTTON_2, LED_Y_2); // Second light flashes
  }
  else {
    Whack_mole(BUTTON_3, LED_Y_3); // Third light flashes
  }
  delay(random(1000, 4000));  // Random time between next flash
}

// Function that shows whether you get the correct light
void Whack_mole(int Mole_Switch, int Mole_Light) {
  digitalWrite(Mole_Light, HIGH);  // Turns on one of the three yellow lights
  int wait = random(600, 900); // Waits a random time before light goes off
  long start_time = millis();  // Saves the start time of the light flashing
  while (millis() - start_time < wait) { // Waits until a button is pushed
    if (digitalRead(Mole_Switch) == LOW) { // Checks if the button is pushed
      digitalWrite(LED_G, HIGH);  // Green light comes on
      digitalWrite(Mole_Light, LOW); // Yellow light goes off since it's correct
      digitalWrite(MOTOR, HIGH); // Motor turns off
      delay(500); // Motor and light wait a certain time
      digitalWrite(LED_G, LOW); // Green light goes off
      digitalWrite(MOTOR, LOW); // Motor turns off
      return; 
    }
  }
  // If mole is not hit with correct button or not at all
  digitalWrite(Mole_Light, LOW);  // Turns off the random light 
  digitalWrite(LED_R, HIGH); // Red light blicks twice to show incorrect answer 
  delay(200); 
  digitalWrite(LED_R, LOW); 
  delay(200);
  digitalWrite(LED_R, HIGH); 
  delay(200);                         
  digitalWrite(LED_R, LOW); 
}
