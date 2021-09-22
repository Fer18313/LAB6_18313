/* 
  FERNANDO JAVIER SANDOVAL RUBALLOS
 CARNE: 18313
 DIGITAL 2 - PRELAB 7
 9/22/2021
 
                   JUEGO DE LEDS
 */


// LED color coded TIVA-c
#define LED1 RED_LED
#define LED2 BLUE_LED
#define LED3 GREEN_LED

// PUSH_button TIVA-c
#define SW1 PF_4
#define SW2 PF_0

// LED WIN pinout
const int h1 = 36;
const int h2 = 37;

// LEDS P1
#define J0 PB_0
#define J1 PB_1
#define J2 PE_4
#define J3 PE_5
#define J4 PB_4
#define J5 PA_5
#define J6 PA_6
#define J7 PA_7

#define P0 PD_0
#define P1 PD_1
#define P2 PD_2
#define P3 PD_3
#define P4 PE_1
#define P5 PE_2
#define P6 PE_3
#define P7 PA_2

// VAR
int P1_counter = 0;
int P2_counter = 0;
int F = 0;
volatile byte state = LOW;


// CONFIG_ INIT
void setup() {
  // put your setup code here, to run once:
  pinMode(LED1,OUTPUT);
  pinMode(LED2,OUTPUT);
  pinMode(LED3,OUTPUT);
  pinMode(SW1, INPUT_PULLUP);
  pinMode(SW2, INPUT_PULLUP);
  pinMode(J0, OUTPUT);
  pinMode(J1, OUTPUT);
  pinMode(J2, OUTPUT);
  pinMode(J3, OUTPUT);
  pinMode(J4, OUTPUT);
  pinMode(J5, OUTPUT);
  pinMode(J6, OUTPUT);
  pinMode(J7, OUTPUT);
  pinMode(h1, OUTPUT);
  pinMode(h2, OUTPUT);
  attachInterrupt(digitalPinToInterrupt(SW1), PUSH_BUTTON_SW1, RISING);
  attachInterrupt(digitalPinToInterrupt(SW2), PUSH_BUTTON_SW2, RISING);
}


// MAIN_ CODE
void loop() {
  // put your main code here, to run repeatedly: 
  DEL();
  DEL_2();
  if (F == 1){
    DEL();
    DEL_2();
    digitalWrite(LED1, HIGH);
    delay(1000);
    digitalWrite(LED3, HIGH);
    delay(1000);
    digitalWrite(LED1, LOW);
    digitalWrite(LED3, HIGH);
    delay(1000);
    digitalWrite(LED3, LOW);
    F = 2;
  }
  
  if(P1_counter == 1){
    DEL();
    digitalWrite(J0, HIGH);
    }
  else if(P1_counter == 2){
    DEL();
    digitalWrite(J1, HIGH);
    }
  else if(P1_counter == 3){
    DEL();
    digitalWrite(J2, HIGH);
    }
  else if(P1_counter == 4){
    DEL();
    digitalWrite(J3, HIGH);
    }
  else if(P1_counter == 5){
    DEL();
    digitalWrite(J4, HIGH);
    }
  else if(P1_counter == 6){
    DEL();
    digitalWrite(J5, HIGH);
    }
  else if(P1_counter == 7){
    DEL();
    digitalWrite(J6, HIGH);
    }
  else if(P1_counter == 8){
    DEL();
    digitalWrite(J7, HIGH);
    digitalWrite(h1, HIGH);
    DEL_2();
    digitalWrite(J7, LOW);
    F = 3;
  }
  if(P2_counter == 1){
    DEL_2();
    digitalWrite(P0, HIGH);
    }
  else if(P2_counter == 2){
    DEL_2();
    digitalWrite(P1, HIGH);
    }
  else if(P2_counter == 3){
    DEL_2();
    digitalWrite(P2, HIGH);
    }
  else if(P2_counter == 4){
    DEL_2();
    digitalWrite(P3, HIGH);
    }
  else if(P2_counter == 5){
    DEL_2();
    digitalWrite(P4, HIGH);
    }
  else if(P2_counter == 6){
    DEL_2();
    digitalWrite(P5, HIGH);
    }
  else if(P2_counter == 7){
    DEL_2();
    digitalWrite(P6, HIGH);
    }
  else if(P2_counter == 8){
    DEL_2();
    digitalWrite(P7, HIGH);
    digitalWrite(h2, HIGH);
    DEL();
    digitalWrite(P7, LOW);
    F = 3;
}
}

void DEL(){
          digitalWrite(J0, LOW);
          digitalWrite(J1, LOW);
          digitalWrite(J2, LOW);
          digitalWrite(J3, LOW);
          digitalWrite(J4, LOW);
          digitalWrite(J5, LOW);
          digitalWrite(J6, LOW);
          digitalWrite(J7, LOW);
}
void DEL_2(){
          digitalWrite(P0, LOW);
          digitalWrite(P1, LOW);
          digitalWrite(P2, LOW);
          digitalWrite(P3, LOW);
          digitalWrite(P4, LOW);
          digitalWrite(P5, LOW);
          digitalWrite(P6, LOW);
          digitalWrite(P7, LOW);
}


void PUSH_BUTTON_SW1(){
  if(F == 0){
     F = 1; 
    }
  if(F == 2){
    P1_counter++;
    }                                 
}

void PUSH_BUTTON_SW2(){
  if(F == 0){
     F = 1; 
    }
  if(F == 2){
    P2_counter++;
    }
}
