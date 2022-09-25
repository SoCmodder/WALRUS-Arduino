byte incomingByte[20];
int LOCK = 10;
int UNLOCK = 8;

void setup(){
  Serial.begin(57600);
  pinMode(LOCK, OUTPUT);
  pinMode(UNLOCK, OUTPUT); 
  pinMode(13, OUTPUT);
}

void loop(){
  if(Serial.available() > 0){
    //incomingByte[] = Serial.read();
    for(int i=0; i<Serial.available(); i++){
      incomingByte[i] = Serial.read();  
    }
    Serial.println(incomingByte[0]);
    if(incomingByte[0] == 0){
       digitalWrite(LOCK, HIGH); 
       delay(200);
       digitalWrite(LOCK, LOW);
       delay(200);
    }
    else if(incomingByte[0] == 1){
       digitalWrite(UNLOCK, HIGH);
       delay(200);
       digitalWrite(UNLOCK, LOW);
       delay(200);
    }
  }    
}
