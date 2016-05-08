char command;
String string;

void setup() {
  Serial.begin(9600);
}

void loop() {
  if (Serial.available() > 0){
    string = "";
    }    
    
    while(Serial.available() > 0) {
      command = ((byte)Serial.read());
      if(command == ':') {
        break;
      } else {
        string += command;
      }
      
      delay(1);
    }
    
    if(string == "F") {
      Serial.println("FORWARD");
      delay(10);
    }

    if(string == "B") {
      Serial.println("BACKWARD");
      delay(10);
    }

    if(string == "L") {
      Serial.println("LEFT");
      delay(10);
    }

    if(string == "R") {
      Serial.println("RIGHT");
      delay(10);
    }
    if(string == "SE") {
      Serial.println("STOP ENGINE");
      delay(10);
    }
    if(string == "ST") {
      Serial.println("STOP TURNING");
      delay(10);
    }
 }
