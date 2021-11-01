/*
        @file   Variable_control.ino
        @brief  変数制御
        @author CaseyNelson314
        @date   2021/11/01
*/

#define sw 4

bool Clickswdata,  Toggleswdata , Countswdata;
bool Clickdata,    Toggledata;
int  Countdata;

void setup() {
  Serial.begin(115200);
  pinMode(sw, INPUT_PULLUP);
}

void loop() {

  Clickdata   = Clickswdata  * !(Clickswdata  = digitalRead(sw));  //click

  Toggledata ^= Toggleswdata * !(Toggleswdata = digitalRead(sw));  //Toggle

  Countdata  += Countswdata  * !(Countswdata  = digitalRead(sw));  //Count

  Serial.print(Clickdata);    //速くて見えないよ☆
  Serial.print(Toggledata);
  Serial.print(Countdata);
  Serial.println();

}
