int EL = 1;  // Error Light
int GL = 2;  // Guard Light
int PL = 3;  // Processing light


//StepLM - Length Calculating Motor
//StepCM - Wire Cutter Actuator

void setup() 
{
    Serial1.begin(9600); // Bluetooth Input
    int NR = 0;

}

void loop() 
{     
      char St, Le, N, P;
      P =  Serial1.read(); // Read Position form User
      /*
        Decode input
      */
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
        While(P==1)
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
  //Move Servo to bring wire head to cut position.
  //Add delay
  //Add Bleep
}

