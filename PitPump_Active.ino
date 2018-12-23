Controls pump in oil pit


pumpLowLevelPin = 3;
pumpHighLevelPin = 4;
pumpRelayPin = 5;

unsigned long currentTime = millis();
unsigned long PumpStartTime =0;
unsigned long allowRunTime = 50000;
unsigned long pumpRestTime = 100000;
unsigned long pumpRestStart = 0;

boolean pumpRunning = FALSE;
boolean pumpRestMode = False;

void setup(){
  pinMode(pumpLowLevelPin, INPUT);
  pinMode(pumpHighLevelPin), INPUT);
  pinMode(pumpRelayPin, OUTPUT);
}

void loop() {



  currentTime = millis();


  if (currentTime - pumpRestStart => pumpRestTime) {

  if (currentTime - PumpStartTime >= allowRunTime  && pumpRunning == TRUE) {
    digitalWrite(pumpRelayPin, HIGH);
    pumpRestMode = HIGH;
    pumpRestStart = millis();
  }

if (pumpHighLevelPin == HIGH && pumpRunning == FALSE) {
  digitalWrite(pumpRelayPin, LOW);
  pumpRunning = TRUE;
  PumpStartTime = millis();


}
if (pumpLowLevelPin == LOW) {
  digitWrite (pumpRelayPin, HIGH);
  pumpRunning= FALSE;
}
}
}

boolean pumpRest(pumpRestMode){
  boolean _pumpRestMode = pumpRestMode;
  if(_pumpRestMode != )
}
