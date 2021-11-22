/*
        @file   VariableController.ino
        @brief  変数制御
        @author CaseyNelson314
        @date   2021/11/22
*/

#pragma once

class VariableController {
  private:
    const byte swPort;
    bool swClick,   swToggle,   SWTOGGLE;
    bool clickData, toggleData, TOGGLEDATA;

  public:
    VariableController(byte SWPORT = 0): swPort(SWPORT) {
      if (swPort != 0)pinMode(swPort, INPUT_PULLUP);
    };

    bool GetClickSw() {
      return swClick * !(swClick = digitalRead(swPort));
    }
    bool GetToggleSw() {
      return SWTOGGLE ^= swToggle * !(swToggle = digitalRead(swPort));
    }

    bool GetClick(bool input) {
      return !clickData * (clickData = input);
    }
    bool GetToggle(bool input) {
      return TOGGLEDATA ^= !toggleData * (toggleData = input);
    }

};
