#include "ledtask.h"

LedTask ledTask1, ledTask2;// Tạo 2 đối tượng tiến trình

void setup() {
  ledTask1.init(8, 100);// Cài đặt tiến trình 1: Blink led ở chân số 8, chu kỳ 100ms
  ledTask2.init(9, 1000);// Cài đặt tiến trình 2: Blink led ở chân số 9, chu kỳ 1000ms
}

void loop() {
  ledTask1.run();// Chạy tiến trình
  ledTask2.run();// Chạy tiến trình
}

