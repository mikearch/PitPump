//Controls pump in oil pit


pumpLowLevelPin = 3;
pumpHighLevelPin = 4;
pumpRelayPin = 5;

unsigned long currentTime = millis();
unsigned long PumpStartTime =0;
unsigned long allowRunTime = 50000;
unsigned long pumpRestTime = 100000;
unsigned long pumpRestStart = 0;

boolean pumpRunning = FALSE;    //True =pump running, False = pump off
boolean pumpRestMode = False;   //True = resting,  False = Active

void setup(){
  pinMode(pumpLowLevelPin, INPUT);  //monitors low water level float switch
  pinMode(pumpHighLevelPin), INPUT);//monitors high water level float switch
  pinMode(pumpRelayPin, OUTPUT);    //activates relay to turn pump on
}

void loop() {



  currentTime = millis();

    //Skips pump control while pump is resting
    if (currentTime - pumpRestStart => pumpRestTime) {
      pumpRestMode = FALSE;

      //Turns pump off if run time exceeded while pump is running
      if (currentTime - PumpStartTime >= allowRunTime  && pumpRunning == TRUE) {
        digitalWrite(pumpRelayPin, HIGH);
        pumpRestMode = HIGH;
        pumpRestStart = millis();
      }

      //Turns pump on if high water float closed and pump is previously off, resets pump timer
      if (pumpHighLevelPin == HIGH && pumpRunning == FALSE) {
        digitalWrite(pumpRelayPin, LOW);
        pumpRunning = TRUE;
        PumpStartTime = millis();
      }

      //Turns off pump when low water level float (wired empty to OPEN) open
      if (pumpLowLevelPin == LOW) {
        digitWrite (pumpRelayPin, HIGH);
        pumpRunning= FALSE;
      }
  }
}
