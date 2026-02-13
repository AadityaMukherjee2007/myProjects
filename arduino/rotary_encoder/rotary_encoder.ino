#define CLK 2
#define DT  3
#define SW 4

#define LONG_PRESS_MS 800
#define DEBOUNCE_MS   30

bool lastButtonState = HIGH;
bool buttonPressed = false;

unsigned long pressTime = 0;
unsigned long lastDebounce = 0;

volatile int encoderCount = 0;
volatile bool moved = false;

void handleButton() {
  bool reading = digitalRead(SW);

  if (reading != lastButtonState) {
    lastDebounce = millis();
  }

  if ((millis() - lastDebounce) > DEBOUNCE_MS) {
    if (reading == LOW && !buttonPressed) {
      buttonPressed = true;
      pressTime = millis();
    }

    if (reading == HIGH && buttonPressed) {
      buttonPressed = false;
      unsigned long duration = millis() - pressTime;

      if (duration >= LONG_PRESS_MS) {
        Serial.println("LONG PRESS");
      } else {
        Serial.println("SHORT CLICK");
      }
    }
  }

  lastButtonState = reading;
}


void encoderISR() {
  if (digitalRead(CLK) == digitalRead(DT)) {
    encoderCount++;
  } else {
    encoderCount--;
  }
  moved = true;
}

void setup() {
  pinMode(CLK, INPUT_PULLUP);
  pinMode(DT, INPUT_PULLUP);
  pinMode(SW, INPUT_PULLUP);

  attachInterrupt(digitalPinToInterrupt(CLK), encoderISR, FALLING);

  Serial.begin(9600);
  Serial.println("Encoder Test");
}

void loop() {
  if (moved) {
    moved = false;
    Serial.print("Count: ");
    Serial.println(encoderCount);
  }
  handleButton();
}
