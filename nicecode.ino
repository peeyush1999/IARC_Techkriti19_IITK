#define rpin 38
#define lpin 38
#define analogPin A15
#define setlfr 35
#define buzz 13


//=======================WFR======================
#define trigf 49
#define echof 47


//right Sensor--------------------------------------------------
#define trigr 53
#define echor 51


//left Sensor--------------------------------------------------
#define trigl 45
#define echol 43
#define USONIC_DIV 58.0  

#define MAX(x,y) x>y?x:y


#define setDistance 10   // determines the distance from the wall bot eeds to maintain

#include <NewPing.h>

#define SONAR_NUM 3      // Number of sensors.
#define MAX_DISTANCE 200 // Maximum distance (in cm) to ping.
#define MAX_DISTANCE_FRONT 40 // Maximum distance (in cm) to ping.

NewPing sonar[SONAR_NUM] = {   // Sensor object array.    left front right
  NewPing(trigl, echol, MAX_DISTANCE), // Each sensor's trigger pin, echo pin, and max distance to ping. 
  NewPing(trigf, echof, MAX_DISTANCE_FRONT), 
  NewPing(trigr, echor, MAX_DISTANCE)
};

long front_Distance = 0;
long right_Distance = 0;
long left_Distance = 0;
long lfr_Distance = 0;
unsigned long int distance=0;
int zone=1;
int wall=0;

//================================================

String str ="",data="";

char received;


void motorMove(int left_speed,int right_speed); // determine the rotation of the motor
void readIR();        // use to measue istance in the final zone
void readline();      // take the digital inputs from lsa08 and initialises the val[] array
long getLine();       // get the line position from the LSA08
void getNode();       // determine the identity/type of the node
void pid_lfr();     // calculate the speed difference for line following bot
long frontDistance();  // get front sensor distance
long rightDistance(); // get right sensor distance
long leftDistance(); // get left sensor distance
double measure(int TRIGGER , int ECHO );  // basic ultrasonic function to convert pulse to distance in cm
void pid_wfr(double distance);       // determines the speed difference for the wall following
void right_follow();  // to follow right wall
void left_follow();   // to follow left wall
void getDistance();     // initialise variables for the new values of distance
void rotateCW(int left_speed,int right_speed);
void rotateACW(int left_speed,int right_speed);
void stopall();
int flag=0;
int zeroFlag=0;   // set to 1 when all val =0  



int in[5] = {0,9,8,11,12};
int ir[8] = {23,25,27,29,31,33,35,37};
int val[8]={0,0,0,0,0,0,0,0};


//nodes
int trueNode=0;
int falseNode =0;
void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);

pinMode(rpin,INPUT);
pinMode(lpin,INPUT);

  
  pinMode(echof,INPUT);
  pinMode(trigf,OUTPUT);

  pinMode(echor,INPUT);
  pinMode(trigr,OUTPUT);
  
  pinMode(echol,INPUT);
  pinMode(trigl,OUTPUT);



}

void loop() {
  // put your main code here, to run repeatedly:
  //setpid();
// readline(); alredy in getNode;
/*
  

right_follow();
  */
  //pid_lfr();

  if( zone == 0)
  {
pid_lfr();
getNode(); // it also call pid
flag=0;
  }


  if(zone == 1 || zone == 2 )
  {
    getDistance();

    
  }


// wall follower
/*getDistance();
right_follow();
*/






}
