
boolean started = false; 
int soundDetectedPin = 10; 
int soundDetectedVal = 0;

void setup() {                
  Serial.begin(115200); 
  pinMode (soundDetectedPin, INPUT);
}

void loop() {
  
  delay(20); 
  soundDetectedVal = digitalRead (soundDetectedPin) ; 
    
  if (Serial.available() > 0) {
    int inByte = Serial.read();
    switch (inByte) {
      case '0':
        stopCapture(); 
        break;
      case '1':  
        startCapture();
        break;
    }
  }

  if (started) {
    if (soundDetectedVal == 1) {
       Serial.println(0);
    } else {
       Serial.println(1);   
    }
  }
}

void startCapture() {
  if (started) {
    Serial.println("Invalid");
  } else {
    started = true; 
    Serial.println("Done");
    }
}

void stopCapture() {
  if (!started) {
    Serial.println("Invalid");
  } else {
    started = false; 
    Serial.println("Done");
  }
}
