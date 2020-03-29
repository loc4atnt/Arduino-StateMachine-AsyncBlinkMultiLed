class LedTask {

  private:
    int blinkTime;
    unsigned long t0, t1;
    boolean ledState;
    int ledPin;
    void(LedTask::*runningFunc)();// Con trỏ trỏ tới hàm xử lý của một trạng thái

    void resetFunc() {
      t0 = millis();

      if (true)
        runningFunc = &checkTimesFunc;
    }

    void checkTimesFunc() {
      t1 = millis();

      if ( (t1 - t0) > blinkTime )
        runningFunc = &checkLedStateFunc;
    }

    void checkLedStateFunc() {
      ledState = digitalRead(ledPin);

      if (ledState == HIGH)
        runningFunc = &turnOffLedFunc;
      else
        runningFunc = &turnOnLedFunc;
    }

    void turnOnLedFunc() {
      digitalWrite(ledPin, HIGH);

      if (true)
        runningFunc = &resetFunc;
    }

    void turnOffLedFunc() {
      digitalWrite(ledPin, LOW);

      if (true)
        runningFunc = &resetFunc;
    }
    
  public:
    void init(int ledPin, int blinkTime) {
      this->ledPin = ledPin;
      this->blinkTime = blinkTime;

      pinMode(ledPin, OUTPUT);
      runningFunc = &resetFunc;// Trạng thái ban đầu là Reset
    }
    
    void run() {
      (this->*runningFunc)();// Chạy hàm được trỏ bởi con trỏ
    }
};

