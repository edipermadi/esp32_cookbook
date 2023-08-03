#include <stdio.h>
#include <esp_random.h>

static unsigned long measure_rng() {
  uint8_t buffer[1024];

  unsigned long start = millis();
  for (int i = 0; i < 1024; i++) {
    esp_fill_random(buffer, sizeof(buffer));
  }
  unsigned long end = millis();

  return end - start;
}

void setup() {
  Serial.begin(115200);
}

void loop() {
  unsigned long duration = measure_rng();
  printf("generated 1 MB of random in %d ms\n", duration);
  delay(1000);
}
