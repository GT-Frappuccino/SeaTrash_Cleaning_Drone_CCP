int ena =13;

int enb = 8; 

int in1 = 12;

int in2 = 11;

int in3 = 10;

int in4 = 9;

void setup (){

  pinMode (ena, OUTPUT) ;
  pinMode (enb, OUTPUT) ;
  pinMode (in1, OUTPUT) ;
  pinMode (in2, OUTPUT) ;
  pinMode (in3, OUTPUT) ;
  pinMode (in4, OUTPUT) ;
  
  
}

void loop(){
 
  analogWrite(ena , 200) ;
  analogWrite(enb, 200) ;
 
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);

  delay (1000);

  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);
  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH);

  delay (1000);

    digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);
  digitalWrite(in3, HIGH);
  digitalWrite(in4, HIGH);

  delay (1000);
  

   
  
}

