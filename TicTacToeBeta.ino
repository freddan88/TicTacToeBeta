int pin_Out_S0 = 2;
int pin_Out_S1 = 3;
int pin_Out_S2 = 4;
int pin_In_Mux1 = A0;
int Mux1_State[8] = {0};
int onLight = 0;
// Digital Ports to LED:s
int ledA1 = 5;
int ledY7 = 11;
int ledY6 = 12;
int ledY5 = 10;
int ledY4 = 13;
int ledY3 = 6;
int ledY2 = 9;
int ledY1 = 8;
int ledY0 = 7;


int isLedLightning[9] = {
  0, //led up left
  0, //led up center
  0, //led up right
  0, //led center left
  0, //led center center
  0, //led center right
  0, //led bottom left
  0, //led bottom center
  0  //led bottom right
};


void setup() {
  pinMode(ledA1, OUTPUT);
  pinMode(ledY7, OUTPUT);
  pinMode(ledY6, OUTPUT);
  pinMode(ledY5, OUTPUT);
  pinMode(ledY4, OUTPUT);
  pinMode(ledY3, OUTPUT);
  pinMode(ledY2, OUTPUT);
  pinMode(ledY1, OUTPUT);
  pinMode(ledY0, OUTPUT);
  
  pinMode(pin_Out_S0, OUTPUT);
  pinMode(pin_Out_S1, OUTPUT);
  pinMode(pin_Out_S2, OUTPUT);
  Serial.begin(9600);
}
void loop() {
  int sensorValue = analogRead(A1);
  Serial.print("A1:");
  Serial.println(sensorValue);
  updateMux1();
  
  //led 6
  if(sensorValue >= 13 ){
    digitalWrite(ledA1, HIGH);
    isLedLightning[6] = 1;
    
  } else {
    digitalWrite(ledA1, LOW);
    isLedLightning[6] = 0;
  }
  
  
  //for(int i = 0; i < 8; i ++) {
  
      //led 0
      if(Mux1_State[0] <= 55){
        digitalWrite(ledY0, HIGH);
        isLedLightning[0] = 1; 
        
      } else {
        digitalWrite(ledY0, LOW);
        isLedLightning[0] = 0;
      }
      
      //led 1
      if(Mux1_State[5] <= 95){
        digitalWrite(ledY5, HIGH);
        isLedLightning[1] = 1;
        
      } else {
        digitalWrite(ledY5, LOW);
        isLedLightning[1] = 0;
      }
      
      //led 2
      if(Mux1_State[4] <= 50){
        digitalWrite(ledY4, HIGH);
        isLedLightning[2] = 1;
        
      } else {
        digitalWrite(ledY4, LOW);
        isLedLightning[2] = 0;
      }
      
      //led 3
      if(Mux1_State[3] <= 55){
        digitalWrite(ledY3, HIGH);
        isLedLightning[3] = 1;
        
      } else {
        digitalWrite(ledY3, LOW);
        isLedLightning[3] = 0;
      }
      
      //led 4
      if(Mux1_State[2] <= 55){
        digitalWrite(ledY2, HIGH);
        isLedLightning[4] = 1;
        
      } else {
        digitalWrite(ledY2, LOW);
        isLedLightning[4] = 0;
      }
      
      //led 5
      if(Mux1_State[6] <= 40){
        digitalWrite(ledY6, HIGH);
        isLedLightning[5] = 1;
        
      } else {
        digitalWrite(ledY6, LOW);
        isLedLightning[5] = 0;
      }
      
      //led 7
      if(Mux1_State[1] <= 50){
        digitalWrite(ledY1, HIGH);
        isLedLightning[7] = 1;
        
      } else {
        digitalWrite(ledY1, LOW);
        isLedLightning[7] = 0;
      }
      
      //led 8
      if(Mux1_State[7] <= 50){
        digitalWrite(ledY7, HIGH);
        isLedLightning[8] = 1;
        
      } else {
        digitalWrite(ledY7, LOW);
        isLedLightning[8] = 0;
      }
      delay(200); 
      
      int portNR = 3;
      
     Serial.print("Y");
     Serial.print(portNR);
     Serial.print(":");
     Serial.println(Mux1_State[portNR]);
      //Serial.print(i);
      //Serial.println(Mux1_State[i]);
      // WIN IFS
      
      if(isLedLightning[0] == 1 && isLedLightning[1] == 1 && isLedLightning[2] == 1) {
        digitalWrite(ledY0, LOW);
        digitalWrite(ledY5, LOW);
        digitalWrite(ledY4, LOW);
        delay(70);
        digitalWrite(ledY0, HIGH);
        digitalWrite(ledY5, HIGH);
        digitalWrite(ledY4, HIGH);
      }

      if(isLedLightning[3] == 1 && isLedLightning[4] == 1 && isLedLightning[5] == 1) {
        digitalWrite(ledY3, LOW);
        digitalWrite(ledY2, LOW);
        digitalWrite(ledY6, LOW);
        delay(70);
        digitalWrite(ledY3, HIGH);
        digitalWrite(ledY2, HIGH);
        digitalWrite(ledY6, HIGH);
      }

      if(isLedLightning[6] == 1 && isLedLightning[7] == 1 && isLedLightning[8] == 1) {
        digitalWrite(ledA1, LOW);
        digitalWrite(ledY1, LOW);
        digitalWrite(ledY7, LOW);
        delay(70);
        digitalWrite(ledA1, HIGH);
        digitalWrite(ledY1, HIGH);
        digitalWrite(ledY7, HIGH);
      }

      if(isLedLightning[0] == 1 && isLedLightning[3] == 1 && isLedLightning[6] == 1) {
        digitalWrite(ledY0, LOW);
        digitalWrite(ledY3, LOW);
        digitalWrite(ledA1, LOW);
        delay(70);
        digitalWrite(ledY0, HIGH);
        digitalWrite(ledY3, HIGH);
        digitalWrite(ledA1, HIGH);
      }

      if(isLedLightning[1] == 1 && isLedLightning[4] == 1 && isLedLightning[7] == 1) {
        digitalWrite(ledY5, LOW);
        digitalWrite(ledY2, LOW);
        digitalWrite(ledY1, LOW);
        delay(70);
        digitalWrite(ledY5, HIGH);
        digitalWrite(ledY2, HIGH);
        digitalWrite(ledY1, HIGH);
      }

      if(isLedLightning[2] == 1 && isLedLightning[5] == 1 && isLedLightning[8] == 1) {
        digitalWrite(ledY4, LOW);
        digitalWrite(ledY6, LOW);
        digitalWrite(ledY7, LOW);
        delay(70);
        digitalWrite(ledY4, HIGH);
        digitalWrite(ledY6, HIGH);
        digitalWrite(ledY7, HIGH);
      }

      if(isLedLightning[0] == 1 && isLedLightning[4] == 1 && isLedLightning[8] == 1) {
        digitalWrite(ledY0, LOW);
        digitalWrite(ledY2, LOW);
        digitalWrite(ledY7, LOW);
        delay(70);
        digitalWrite(ledY0, HIGH);
        digitalWrite(ledY2, HIGH);
        digitalWrite(ledY7, HIGH);
      }

      if(isLedLightning[2] == 1 && isLedLightning[4] == 1 && isLedLightning[6] == 1) {
        digitalWrite(ledY4, LOW);
        digitalWrite(ledY2, LOW);
        digitalWrite(ledA1, LOW);
        delay(70);
        digitalWrite(ledY4, HIGH);
        digitalWrite(ledY2, HIGH);
        digitalWrite(ledA1, HIGH);
      }
      
  }

  
  void updateMux1 () {
    for (int i = 0; i < 8; i++) {
      digitalWrite(pin_Out_S0, HIGH && (i & B00000001));
      digitalWrite(pin_Out_S1, HIGH && (i & B00000010));
      digitalWrite(pin_Out_S2, HIGH && (i & B00000100));
      Mux1_State[i] = analogRead(pin_In_Mux1);
    }
}
