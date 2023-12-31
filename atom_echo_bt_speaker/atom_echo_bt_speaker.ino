#include <LiteLED.h>
#include <BluetoothA2DPSink.h>

// An example of ESP32 bluetooth audio sink using M5Stack Atom device
// Device Documentation: https://docs.m5stack.com/en/atom/atomecho

#define LED_GPIO 27
#define LED_TYPE LED_STRIP_SK6812
#define LED_TYPE_IS_RGBW 0
#define LED_BRIGHT 30
#define BUTTON_PIN 39

LiteLED led(LED_TYPE, LED_TYPE_IS_RGBW);
BluetoothA2DPSink a2dp_sink;

static const crgb_t L_RED = 0xff0000;
static const crgb_t L_ORANGE = 0xffa500;
static const crgb_t L_GREEN = 0x00ff00;
static const crgb_t L_BLUE = 0x0000ff;
static const crgb_t L_WHITE = 0xe0e0e0;

static void on_audio_state_changed(esp_a2d_audio_state_t state, void *arg) {
  switch (state) {
    case ESP_A2D_AUDIO_STATE_REMOTE_SUSPEND:
      led.setPixel(0, L_ORANGE, 1);
      break;
    case ESP_A2D_AUDIO_STATE_STOPPED:
      led.setPixel(0, L_RED, 1);
      break;
    default:
      led.setPixel(0, L_GREEN, 1);
      break;
  }
}

void setup() {
  Serial.begin(115200);

  i2s_pin_config_t my_pin_config = {
    .bck_io_num = 19,
    .ws_io_num = 33,
    .data_out_num = 22,
    .data_in_num = I2S_PIN_NO_CHANGE
  };
  a2dp_sink.set_pin_config(my_pin_config);
  a2dp_sink.set_mono_downmix(true);
  a2dp_sink.set_on_audio_state_changed(on_audio_state_changed);
  a2dp_sink.start("Atom Echo");

  led.begin(LED_GPIO, 1);
  led.brightness(LED_BRIGHT);
  led.setPixel(0, L_RED, 1);
  pinMode(BUTTON_PIN, INPUT_PULLUP);
}

bool playing = true;
bool pressed = false;

void loop() {
  bool status = digitalRead(BUTTON_PIN) == 0;
  if (pressed != status) {
    pressed = status;

    if (status) {
      if (playing) {
        a2dp_sink.pause();
      } else {
        a2dp_sink.play();
      }

      playing = !playing;
      delay(1000);
    }
  }

  delay(100);
}