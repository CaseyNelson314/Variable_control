# Variable-control
Click,Toggle,Count動作
演算順序の性質から前回,現在のループからのデータを1行で比較しています
# Data
- *Arduino 1.8.16*
- *CaseyNelson314*
- *2021/11/01*
# Program
- *Click*
```
Clickdata = data * !(data = digitalRead(sw));

data                        : 前回データ
!(data = digitalRead(sw))   : 現在データ

前回LOW、現在がHIGHの場合 Clickdata = HIGH
```
- *Toggle*
```
XOR演算によってClickdataがHIGHの場合反転処理を行う
```
- *Count*
```
ClickdataがHIGHになるごとにカウントアップ
```
# Process
1. Click初期
```
newdata = !digitalRead(sw);       //注swpinはpullup
if (olddata == 0 && newdata == 1) {
  Clickdata = 1;
} else {
  Clickdata = 0;
}
olddata = newdata;
```
2. 条件式から代入式へ
```
newdata = !digitalRead(sw);
Clickdata = !olddata * newdata;
olddata = newdata;
```
3. ぷぅ
```
olddata = newdata;
newdata = !digitalRead(sw);
Clickdata = !olddata * newdata;
```
4. ムリヤリ
```
Clickdata = !newdata * (newdata = !digitalRead(sw));
```
5. 反転(!)削減
```
Clickdata = newdata * !(newdata = digitalRead(sw));
```
6. へんすうなまえかえた
```
Clickdata = data * !(data = digitalRead(sw));
```
```
Clickdata = !data * (data = digitalRead(sw));   //pullupなし
```
