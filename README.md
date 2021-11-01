# Variable-control
```
Click,Toggle,Count動作
演算順序の性質から前回のループの値と現在のループの値を1行で比較できます
```
# Data
```
version   Arduino 1.8.16
Author    CaseyNelson314
Date      2021/11/01
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

↓

newdata = !digitalRead(sw);
Clickdata = !olddata * newdata;
olddata = newdata;

↓

olddata = newdata;
newdata = !digitalRead(sw);
Clickdata = !olddata * newdata;

↓

Clickdata = !newdata * (newdata = !digitalRead(sw));

↓

Clickdata = newdata * !(newdata = digitalRead(sw));

↓

Clickdata = data * !(data = digitalRead(sw));
```
