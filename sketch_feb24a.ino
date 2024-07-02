#include <Servo.h>
Servo s1 = Servo();  //base mortor
Servo s2 = Servo();  //left mortor look from back
Servo s3 = Servo();  //right mortor look from back
Servo s4 = Servo();  //top

#include <IRremote.h>
IRrecv r = IRrecv(7);
decode_results d = decode_results();

int angle = 83;
int delayTime = 10;
int leftFromBack = 90;
int rightFromBack = 90;
int top = 180;
bool on = false;
int onDelayTime = 20;
int offDelayTime = 20;
int mouthDelay = 3;

void setup() {

  s1.attach(8);
  s2.attach(9);
  s3.attach(10);
  s4.attach(11);

  r.enableIRIn();
  Serial.begin(9600);

  s1.write(83);  //base
  s4.write(top);  // top

  pinMode(12, OUTPUT);  //red led
}

void loop() {

  if (r.decode(&d)) {

    int v = d.value;
    Serial.println(v);

    if (v == -16321) {
      if (on == true) {
        on = false;
        digitalWrite(12, LOW);

        if (angle > 83) {
          for (int i = angle; i > 83; i--) {
            i--;
            s1.write(i);
            delay(offDelayTime);
          }
        } else if (angle < 83) {
          for (int i = angle; i < 83; i++) {
            i++;
            s1.write(i);
            delay(offDelayTime);
          }
        }

        if (top < 180) {
          for (int c = top; c < 180; c++) {
            c++;
            s4.write(c);
            delay(offDelayTime);
          }
        }

        if (leftFromBack > 50) {
          for (int a = leftFromBack; a > 50; a--) {
            a--;
            s2.write(a);
            delay(offDelayTime);
          }
        } else if (leftFromBack < 50) {
          for (int a = leftFromBack; a < 50; a++) {
            a++;
            s2.write(a);
            delay(offDelayTime);
          }
        }

        if (rightFromBack > 30) {
          for (int b = rightFromBack; b > 30; b--) {
            b--;
            s3.write(b);
            delay(offDelayTime);
          }
        } else if (rightFromBack < 30) {
          for (int b = rightFromBack; b < 30; b++) {
            b++;
            s3.write(b);
            delay(offDelayTime);
          }
        }


        

      } else if(on==false){
        on = true;
        digitalWrite(12, HIGH);

        if (angle > 83) {
          for (int c = angle; c > 83; c--) {
            c--;
            s1.write(c);
            delay(onDelayTime);
          }
        } else if (angle < 83) {
          for (int c = angle; c < 83; c++) {
            c++;
            s1.write(c);
            delay(onDelayTime);
          }
        }

        if (leftFromBack > 90) {
          for (int d = leftFromBack; d > 90; d--) {
            d--;
            s2.write(d);
            delay(onDelayTime);
          }
        } else if (leftFromBack < 90) {
          for (int d = leftFromBack; d < 90; d++) {
            d++;
            s2.write(d);
            delay(onDelayTime);
          }
        }

        if (rightFromBack > 90) {
          for (int e = rightFromBack; e > 90; e--) {
            e--;
            s3.write(e);
            delay(onDelayTime);
          }
        } else if (rightFromBack < 90) {
          for (int e = rightFromBack; e < 90; e++) {
            e++;
            s3.write(e);
            delay(onDelayTime);
          }
        }

        if (top < 180) {
          for (int i = top; i < 180; i++) {
          top++;
          s4.write(i);
          delay(mouthDelay);
        }
        }
      }
    }


    if (on == true) {

      // base mortor
      if (v == 255) {  //1  ->0

        for (int i = angle; i > 0; i--) {
          angle--;
          s1.write(angle);
          delay(delayTime);
        }
      }


      if (v == -32641) {  //2  ->90

        if (angle > 83) {
          for (int i = angle; i > 83; i--) {
            angle--;
            s1.write(angle);
            delay(delayTime);
          }
        } else if (angle < 83) {
          for (int i = angle; i < 83; i++) {
            angle++;
            s1.write(angle);
            delay(delayTime);
          }
        }
      }


      if (v == 16575) {  //3 ->180

        for (int i = angle; i < 180; i++) {
          angle++;
          s1.write(angle);
          delay(delayTime);
        }
      }





      // left mortor look from back
      if (v == 8415) {  //4  ->0

        for (int i = leftFromBack; i > 60; i--) {
          leftFromBack--;
          s2.write(leftFromBack);
          delay(delayTime);
        }
      }


      if (v == -24481) {  //5  ->90

        if (leftFromBack > 90) {
          for (int i = leftFromBack; i > 90; i--) {
            leftFromBack--;
            s2.write(leftFromBack);
            delay(delayTime);
          }
        } else if (leftFromBack < 90) {
          for (int i = leftFromBack; i < 90; i++) {
            leftFromBack++;
            s2.write(leftFromBack);
            delay(delayTime);
          }
        }
      }


      if (v == 24735) {  //6 ->180
        if (rightFromBack >60) {

          for (int i = leftFromBack; i < 160; i++) {
            leftFromBack++;
            s2.write(leftFromBack);
            delay(delayTime);
          }

        } else {

          for (int i = leftFromBack; i < 178; i++) {
            leftFromBack++;
            s2.write(leftFromBack);
            delay(delayTime);
          }
        }
      }





      // right from back
      if (v == 4335) {  //7  ->0
        if (leftFromBack == 60) {
          for (int i = rightFromBack; i > 75; i--) {
            rightFromBack--;
            s3.write(rightFromBack);
            delay(delayTime);
          }
        } else {
          for (int i = rightFromBack; i > 55; i--) {
            rightFromBack--;
            s3.write(rightFromBack);
            delay(delayTime);
          }
        }
      }


      if (v == -28561) {  //8  ->90

        if (rightFromBack > 90) {
          for (int i = rightFromBack; i > 90; i--) {
            rightFromBack--;
            s3.write(rightFromBack);
            delay(delayTime);
          }
        } else if (rightFromBack < 90) {
          for (int i = rightFromBack; i < 90; i++) {
            rightFromBack++;
            s3.write(rightFromBack);
            delay(delayTime);
          }
        }
      }


      if (v == 20655) {  //9 ->180
        if (leftFromBack == 160) {
          for (int i = rightFromBack; i < 145; i++) {
            rightFromBack++;
            s3.write(rightFromBack);
            delay(delayTime);
          }
        } else {
          for (int i = rightFromBack; i < 180; i++) {
            rightFromBack++;
            s3.write(rightFromBack);
            delay(delayTime);
          }
        }
      }


      // top
      if (v == 26775) {  //volume +  -> open

        for (int i = top; i > 20; i--) {
          top--;
          s4.write(i);
          delay(mouthDelay);
        }
      }

      if (v == 22695) {  //volume - close
        for (int i = top; i < 170; i++) {
          top++;
          s4.write(i);
          delay(mouthDelay);
        }
      }
    }


    r.resume();
  }
}