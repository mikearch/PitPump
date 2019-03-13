//Controls pump in oil pit

//All pins need pull down resistors
pumpLowLevelPin = 3;
pumpHighLevelPin = 4;
pumpRelayPin = 5;

unsigned long currentTime = millis();
unsigned long PumpStartTime =0;
unsigned long allowRunTime = 300000;
unsigned long pumpRestTime = 600000;
unsigned long pumpRestStart = 0;

boolean pumpRunning = false;    //True =pump running, False = pump off
boolean pumpRestMode = true;   //True = resting,  False = Active

void setup(){
  pinMode(pumpLowLevelPin, INPUT);  //monitors low water level float switch
  pinMode(pumpHighLevelPin), INPUT);//monitors high water level float switch
  pinMode(pumpRelayPin, OUTPUT);    //activates relay to turn pump on
  pinMode(LED_BUILTIN, OUTPUT)      //activates builtin for testing purposes

  Serial.println("*************Values at Setup***************")
  Serial.println("currentTime = ", currentTime);
  Serial.println("PumpStartTime = ", PumpStartTime);
  Serial.println("allowRunTime = ", allowRunTime);
  Serial.println("pumpRestTime = ", pumpRestTime);
  Serial.println("pumpRestStart = ", pumpRestStart);
  Serial.println("pumpRunning = ", pumpRunning);
  Serial.println("pumpRestMode = ", pumpRestMode);
}

void loop() {

  currentTime = millis();

    //Skips pump control while pump is resting
    if (currentTime - pumpRestStart => pumpRestTime) {
      pumpRestMode = false;

    if (pumpRestMode = !pumpRestMode) {  //Test
      Serial.println("Change of pump rest state.  It is now= ",pumpRestMode);
    }

      //Turns pump off if run time exceeded while pump is running
      if (currentTime - PumpStartTime >= allowRunTime  && pumpRunning == true) {
        digitalWrite(pumpRelayPin, HIGH);
        pumpRunning = false;
        pumpRestMode = true;
        pumpRestStart = millis();
        digitalWrite(LED_BUILTIN, LOW);  //Test
        Serial.println("Pump turned off due to exceeding time limit");   //Test
      }

      //Turns pump on if high water float closed and pump is previously off, resets pump timer
      if (pumpHighLevelPin == HIGH && pumpRunning == false) {
        digitalWrite(pumpRelayPin, LOW);
        pumpRunning = true;
        PumpStartTime = millis();
        pumpRestMode = false;
        digitalWrite(LED_BUILTIN, HIGH);  //Test
        Serial.println("Pump turned on by high water level float");   //Test
      }

      //Turns off pump when low water level float (wired empty to OPEN) open
      if (pumpLowLevelPin == LOW) {
        digitalWrite (pumpRelayPin, HIGH);
        pumpRunning= false;
        digitalWrite(LED_BUILTIN, LOW);  //Test
        Serial.println("Pump turned off by low level float"); //Test
      }
  }
}
