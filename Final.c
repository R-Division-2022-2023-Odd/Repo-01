//Lights

int EL = 1;  // Error Light
int GL = 2;  // Guard Light
int PL = 3;  // Processing light

//Stepper Pins
#define SPLM1 4
#define SPLM2 5
#define SPLM3 6
#define SPLM4 7

#define SPCM1 8
#define SPCM2 9
#define SPCM3 10
#define SPCM4 11

//Buzzer pins
#define BP1 12

//Servo pins
#include <Servo.h>
Servo SM;


//StepLM - Length Calculating Motor
//StepCM - Wire Cutter Actuator

void setup() 
{
    Serial1.begin(9600); // Bluetooth Input
    Serial.begin(9600);

  //Pin Declaration Lights
    pinMode(EL, OUTPUT);
    pinMode(GL, OUTPUT);
    pinMode(PL, OUTPUT);

  //Pin Declarations stepper motor
    pinMode(SPLM1, OUTPUT);
    pinMode(SPLM2, OUTPUT);
    pinMode(SPLM3, OUTPUT);
    pinMode(SPLM4, OUTPUT);

    pinMode(SPCM1, OUTPUT);
    pinMode(SPCM2, OUTPUT);
    pinMode(SPCM3, OUTPUT);
    pinMode(SPCM4, OUTPUT);

  //Pin Declarations Buzzer

    pinMode(BP1, OUTPUT);

  //Pin Declarations Servo
  SM.attach(13);


}

void loop() 
{     
      char St, Le, N, P;
      P =  Serial1.read(); // Read Position form User
      /*
        Decode input
        
      */
          int NR = 0;

      if(P == 0)
      {
        
        while(N>NR)
        {
          LEDN(GL);  //Guard Light ON
          LEDN(PL);  //Processing Light ON

          StepLM(St); //Strip Length Deploy //Processing light ON
          StepCM();

          StepLM(Le);
          StepCM();

          StepLM(St);
          StepCMF();

          LEDF(GL);  //Guard Light OFF
          LEDF(PL);  //Processing Light OFF
          NR = NR++;
        }
        // Relay Message of Completion.
        
      }
      else if(P == 1)
      {
        while(P==1)
        LEDBN(EL); // Error Light ON
        //Display Wire not present
        //Manual Move StepLM
      }
}


// Functions


//LED Funtions

void LEDN(int P)
{
        pinMode(P, HIGH);
}

void LEDF(int P)
{
        pinMode(P, LOW);
}

void LEDBN(int P)
{
        pinMode(P, HIGH);
        delay(1000);
        pinMode(P, LOW);
        delay(1000);
}


//Stepper Funtions

void StepLM(int L)
{
  //Move stepper according to length.
  //Add Delay
}

void StepCM()
{
  //Move Stepper Actuator. Not Input Needed. Just pre-detremined Movement.
  //Add delay
  //Add Bleep
}

void StepCMF()
{
  //Move Stepper Actuator. Not Input Needed. Just pre-detremined Movement.
  SM.write(35);  
  delay(15);
  //Add delay
  //Add Bleep
}

