#include "detector.h"

namespace Setup{

  void SetSerial(){

    Serial.begin(9600);

  }

  void setBuzzer(){

    pinMode(BUZZER,OUTPUT);

  }

  void setLed(){

    pinMode(LED,OUTPUT);

  }

  void setGasSensor(){

    pinMode(DETECTOR,INPUT);

  }

  void Setup(){

    SetSerial();

    Serial.print("========SETUP_MODE========\n\n");

    Serial.println("[+]Setup buzzer");
    setBuzzer();

    Serial.println("[+]Setup Led");
    setLed();

    Serial.println("[+]Setup Gas_sensor");
    setGasSensor();

    delay(1000);

  }

};

void setup(){

  Setup::Setup();

}

namespace GAS_DETECTOR{

  uint16_t level(){

    uint16_t level = analogRead(DETECTOR);

    Serial.print("[+]Gas level : ");
    Serial.println(level);

    return level;

  }

};

namespace LEVELS{

  void level_write(uint16_t pin,uint16_t level){

    if(pin == BUZZER){

      Serial.print("[+]Buzzer on level: ");

    }else{

      Serial.print("[+]Led on level: ");

    }

    Serial.println(level);

    analogWrite(pin,level);
    delay(10);

  }

};


void loop(){

  Serial.print("\n========LOOP_FUNCTION========\n\n");

  uint16_t level =  GAS_DETECTOR::level();
                    LEVELS::level_write(BUZZER,level);
                    LEVELS::level_write(LED,level);
  
  
  delay(2000);

 
}
