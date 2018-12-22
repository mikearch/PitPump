Controls pump in oil pit


pumpLowLevelPin = 3;
pumpHighLevelPin = 4;
pumpRelayPin = 5;

unsigned long currentTime = millis();
unsigned long oldTime =0;
unsigned long allowRunTime = 50000;
unsigned long pumpRestTime = 100000;

boolean pumpRunning = FALSE;
boolean pumpRestMode = False;

void setup(){
  pinMode(pumpLowLevelPin, INPUT);
  pinMode(pumpHighLevelPin), INPUT);
  pinMode(pumpRelayPin, OUTPUT);
}

void loop() {

  if (currentTime - oldTime >= allowRunTime  && pumpRunning == TRUE) {
    digitalWrite(pumpRelayPin, HIGH);
    pumpRestMode = HIGH;
  }

if (pumpHighLevelPin == HIGH && pumpRunning == FALSE) {
  digitalWrite(pumpRelayPin, LOW);
  pumpRunning = TRUE;
  oldTime = currentTime;

}
if (pumpLowLevelPin == LOW) {
  digitWrite (pumpRelayPin, HIGH);
  pumpRunning= FALSE;
}


}

boolean pumpRest(){
  boolean _pumpRestMode = 
}
