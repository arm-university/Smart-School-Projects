const int button1 = 2; //first button is on pin 8
const int button2 = 3; //second is on pin 9
const int button3 = 5; //third is pin 10
const int button4 = 6; //fourth button is pin 11
const int LED[] = {A3,A0,A1,A4};

const int Green = 9;

int code[] = {1,2,3,4};
int entered[4];

void setup() {
  Serial.begin(9600);
  Serial.println(code[0]);

  pinMode(button1, INPUT_PULLUP); //button 1 is an input
  pinMode(button2, INPUT_PULLUP); //button 2 is an input
  pinMode(button3, INPUT_PULLUP); //button 3 is an input
  pinMode(button4, INPUT_PULLUP); //button 4 is an input
  pinMode(Green, OUTPUT);

  for (int i = 0; i < 4;i++){ //work through numbers 0-3
    Serial.println(code[i]); //print each digit of the code
    Serial.println(entered[i]); //print each element of the entered[]
                                //array (this was for me to check that it 
                                //started at 0
    pinMode(LED[i],OUTPUT);
  }
}

void loop(){ //run repeatedly
  if (digitalRead(button1) == LOW){ //if button1 is pressed
    checkEntered1(1); //call checkEntered and pass it a 1
    
    delay(250);
  }
  else if (digitalRead(button2) == LOW){ //if button2 is pressed
    checkEntered1(2); //call checkEntered1 and pass it a 2
    
    delay(250); //wait
  }
  else if (digitalRead(button3) == LOW){ //if button3 is pressed
    checkEntered1(3); //call checkEntered1 and pass it a 3
    
    delay(250); //wait
  }
  else if (digitalRead(button4) == LOW){ //if button4 is pressed
    checkEntered1(4); //call checkEntered1 and pass it a 4
    
    delay(250); //wait
  }
}

void checkEntered1(int button){ //check the first element of the entered[] array
  digitalWrite(LED[button-1],HIGH);
  if (entered[0] != 0){ //if it is not a zero, i.e. it has already been inputted
    checkEntered2(button); //move on to checkEntered2, passing it "button"
  }
  else if(entered[0] == 0){ //if it is zero, i.e. if it hasn't been defined with a button yet
    entered[0] = button; //set the first element as the button that has been pressed
    Serial.print("1: ");Serial.println(entered[0]); //for debugging
  }
}

void checkEntered2(int button){ //check the second element of the entered[] array]
  digitalWrite(LED[button-1],HIGH);
  if (entered[1] != 0){ //if it is not a zero, i.e. it has already been inputted
    checkEntered3(button); //move on to checkEntered3, passing it "button"
  }
  else if(entered[1] == 0){ //if it is zero, i.e. if it hasn't been defined with a button yet
    entered[1] = button; //set the second element as the button that has been pressed
    Serial.print("2: ");Serial.println(entered[1]); //for debugging
  }
}

void checkEntered3(int button){  //check the third element of the entered[] array
  digitalWrite(LED[button-1],HIGH);
  if (entered[2] != 0){ //if it is not a zero, i.e. it has already been inputted
    checkEntered4(button); //move on to checkEntered4, passing it "button"
  }
  
  else if (entered[2] == 0){ //if it is zero, i.e. if it hasn't been defined with a button yet
    entered[2] = button; //set the third element as the button that has been pressed
    Serial.print("3: ");Serial.println(entered[2]); //for debugging
  }
}

void checkEntered4(int button){ //check the fourth element of the entered[] array
  digitalWrite(LED[button-1],HIGH);
  if (entered[3] == 0){ //if it is zero, i.e. if it hasn't been defined with a button yet
    entered[3] = button; //set the final element as the button that has been pressed
    Serial.print("4: "); //for debugging
    delay(100); //allow time for processing
    compareCode(); //call the compareCode function
  }
}


void compareCode(){ //checks if the code entered is correct by comparing the code[] array with the entered[] array
  for (int i = 0; i<4;i++){ //these three lines are for debugging
    Serial.println(entered[i]);
  }
  if ((entered[0]==code[0]) && (entered[1]==code[1]) && (entered[2]==code[2]) && (entered[3]==code[3])){ //if all the elements of each array are equal
    digitalWrite(Green, HIGH); //turn the green LED on
    delay(1000); //wait for a bit
    digitalWrite(Green, LOW); //turn the green LED off

    for (int i = 0; i < 4; i++){ //this next loop is for debugging
      entered[i] = 0;
    }
    loop(); //return to loop() (not really necessary)
  }
  else { //if you (or the intruder) get the code wrong
    for (int i = 0; i < 4; i++){ //this next loop is for debugging
      entered[i] = 0;
    }
  }
  close_all();
}


void close_all(){
  digitalWrite(LED[0],LOW);
  digitalWrite(LED[1],LOW);
  digitalWrite(LED[2],LOW);
  digitalWrite(LED[3],LOW);
}
