# Variable-control
```
Click,Toggle,Count動作
演算順序の性質から前回のループからのデータと現在のループからのデータを1行で比較しています
```
# Data
```
version   Arduino 1.8.16
Author    CaseyNelson314
Date      2021/11/01
```
# Program
・Click
```
Clickdata = data * !(data = digitalRead(sw));

data : 前回データ  !(data = digitalRead(sw)) : 現在データ
前回LOW、現在がHIGHの場合 Clickdata = HIGH
```
・Toggle
```
XOR演算によってClickdataがHIGHの場合反転処理を行う
```
・Count
```
ClickdataがHIGHになるごとにカウントアップ
```
# Process
```
newdata = !digitalRead(sw);
if (olddata == 0 && newdata == 1) {
  Clickdata = 1;
} else {
  Clickdata = 0;
}
olddata = newdata;
```
↓
```
newdata = !digitalRead(sw);
Clickdata = !olddata * newdata;
olddata = newdata;
```
↓
```
olddata = newdata;
newdata = !digitalRead(sw);
Clickdata = !olddata * newdata;
```
↓
```
Clickdata = !newdata * (newdata = !digitalRead(sw));
```
↓
```
Clickdata = newdata * !(newdata = digitalRead(sw));
```
↓
```
Clickdata = data * !(data = digitalRead(sw));   //sw pullupネ☆
```
```
Clickdata = !data * (data = digitalRead(sw));   //pullupなし
```
