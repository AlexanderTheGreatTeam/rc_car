char command;
String string;

int enable_motor = 8;
int forward_motor = 9;
int backward_motor = 10;

int enable_turn = 11;
int forward_turn = 12;
int backward_turn = 13;

void setup() {
  Serial.begin(9600);
  int i = 0;
  for(i = 8; i < 14; i++){
    pinMode(i, OUTPUT);
  }
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
      //Serial.println("FORWARD");
      run_motor_forward(enable_motor, forward_motor, backward_motor);
      delay(10);
    }

    if(string == "B") {
      //Serial.println("BACKWARD");
      run_motor_backward(enable_motor, forward_motor, backward_motor);
      delay(10);
    }

    if(string == "L") {
      //Serial.println("LEFT");
      turn_left(enable_turn, forward_turn, backward_turn);
      delay(10);
    }

    if(string == "R") {
      //Serial.println("RIGHT");
      turn_right(enable_turn, forward_turn, backward_turn);
      delay(10);
    }
    if(string == "SE") {
      //Serial.println("STOP ENGINE");
      motor_stop(enable_motor, forward_motor, backward_motor);
      delay(10);
    }
    if(string == "ST") {
      //Serial.println("STOP TURNING");
      stop_turning(enable_turn, forward_turn, backward_turn);
      delay(10);
    }
 }

 void run_motor_forward(int enable, int forward, int backward) {
    digitalWrite(enable, HIGH);
    digitalWrite(forward, HIGH);
    digitalWrite(backward, LOW);
}

void run_motor_backward(int enable, int forward, int backward) {
    digitalWrite(enable, HIGH);
    digitalWrite(forward, LOW);
    digitalWrite(backward, HIGH);
}

void motor_stop(int enable, int forward, int backward){
  digitalWrite(enable, LOW);
  digitalWrite(forward, LOW);
  digitalWrite(backward, LOW);
}

void turn_left(int enable, int forward, int backward){
  run_motor_forward(enable, forward, backward);
}

void turn_right(int enable, int forward, int backward){
  run_motor_backward(enable, forward, backward);
}

void stop_turning(int enable, int forward, int backward){
  motor_stop(enable, forward, backward);
}

