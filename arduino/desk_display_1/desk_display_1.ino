#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

// ===================== HARDWARE CONFIG =====================
#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64
#define OLED_RESET -1

#define CLK 2
#define DT 3
#define SW 4
#define BUZZER_PIN 6

#define DEBOUNCE_MS 40
#define LONG_PRESS_MS 700

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

// ===================== GLOBALS =====================
volatile int encoderCount = 0;
volatile bool moved = false;

bool lastButtonState = HIGH;
bool buttonPressed = false;
unsigned long pressTime = 0;
unsigned long lastDebounce = 0;

bool redraw = true;

// ===================== IDLE / AUTO EMOTION =====================
#define IDLE_TIMEOUT_MS 30000UL  // 30 seconds
unsigned long lastInteraction = 0;

// ===================== STATES =====================
enum State { MENU, TIMER, SETTINGS, EMOTION };
State currentState = MENU;

enum TimerState {
  TIMER_SET_MIN,
  TIMER_SET_SEC,
  TIMER_RUNNING,
  TIMER_PAUSED,
  TIMER_DONE
};

TimerState timerState = TIMER_SET_MIN;

// ===================== MENU =====================
const char* mainMenu[] = {"Timer", "Settings", "Robot Emotions"};
const int mainMenuLength = 3;
int menuIndex = 0;

// ===================== TIMER =====================
int timerMinutes = 0;
int timerSeconds = 0;
unsigned long lastTick = 0;

// ===================== SETTINGS =====================
bool buzzerEnabled = true;
uint8_t volumeLevel = 2; // 0=mute, 1=low, 2=mid, 3=high
int settingsIndex = 0; // 0 = Buzzer, 1 = Volume

// ===================== ROBOT EMOTION (COZMO-STYLE) =====================
// Emotion states
enum EmotionType { NEUTRAL, HAPPY, SAD, SURPRISED, CURIOUS, ANGRY, SLEEPY, CONFUSED, EXCITED };
EmotionType currentEmotion = NEUTRAL;
unsigned long lastEmotionChange = 0;

// Eye position and dimensions (current smoothed values)
float eyeWidth = 24.0;
float eyeHeight = 32.0;
float eyeSpacing = 20.0;
float eyeY = 16.0;

// Target values for smooth interpolation
float targetEyeWidth = 24.0;
float targetEyeHeight = 32.0;
float targetEyeSpacing = 20.0;
float targetEyeY = 16.0;

// Pupil tracking
float pupilOffsetX = 0.0;
float pupilOffsetY = 0.0;
float targetPupilX = 0.0;
float targetPupilY = 0.0;
unsigned long lastEyeMove = 0;

// Blinking animation
unsigned long lastBlink = 0;
float blinkAmount = 0.0;  // 0.0 = fully open, 1.0 = fully closed
bool isBlinking = false;
int blinkPhase = 0;  // 0 = not blinking, 1 = closing, 2 = opening

// Eye squint for happy expression
float squintAmount = 0.0;
float targetSquint = 0.0;

// ===================== BUZZER =====================
bool buzzerActive = false;
unsigned long buzzerOffTime = 0;

void startBeep(unsigned int freq, unsigned long duration) {
  if (!buzzerEnabled || volumeLevel == 0) return;

  unsigned int f = freq;
  if (volumeLevel == 1) f = freq / 2;
  else if (volumeLevel == 3) f = freq * 1.5;

  tone(BUZZER_PIN, f);
  buzzerActive = true;
  buzzerOffTime = millis() + duration;
}

void updateBuzzer() {
  if (buzzerActive && millis() >= buzzerOffTime) {
    noTone(BUZZER_PIN);
    buzzerActive = false;
  }
}

// ===================== ENCODER ISR =====================
void encoderISR() {
  if (digitalRead(CLK) == digitalRead(DT)) encoderCount++;
  else encoderCount--;
  moved = true;
}

// ===================== INPUT HANDLING =====================
void onShortClick() {
  lastInteraction = millis();
  if (currentState == MENU) {
    if (menuIndex == 0) currentState = TIMER;
    else if (menuIndex == 1) currentState = SETTINGS;
    else {
      currentState = EMOTION;
      // Play friendly startup chirp
      if (buzzerEnabled && volumeLevel > 0) {
        tone(BUZZER_PIN, 659);
        delay(80);
        tone(BUZZER_PIN, 784);
        delay(80);
        tone(BUZZER_PIN, 988);
        delay(100);
        noTone(BUZZER_PIN);
      }
    }
    redraw = true;
  }
  else if (currentState == TIMER) {
    if (timerState == TIMER_SET_MIN) timerState = TIMER_SET_SEC;
    else if (timerState == TIMER_SET_SEC) {
      timerState = TIMER_RUNNING;
      lastTick = millis();
    }
    else if (timerState == TIMER_RUNNING) timerState = TIMER_PAUSED;
    else if (timerState == TIMER_PAUSED) timerState = TIMER_RUNNING;
    else if (timerState == TIMER_DONE) {
      timerMinutes = 0;
      timerSeconds = 0;
      timerState = TIMER_SET_MIN;
    }
    redraw = true;
  }
  else if (currentState == SETTINGS) {
    // Toggle the value of the selected setting
    if (settingsIndex == 0) {
      buzzerEnabled = !buzzerEnabled;
    } else {
      volumeLevel = (volumeLevel + 1) % 4;  // Cycle through 0-3
    }
    redraw = true;
  }
}

void onLongPress() {
  lastInteraction = millis();
  if (currentState == TIMER) {
    timerState = TIMER_SET_MIN;
    currentState = MENU;
    redraw = true;
  }
  else if (currentState == SETTINGS || currentState == EMOTION) {
    currentState = MENU;
    redraw = true;
  }
}

void handleButton() {
  bool reading = digitalRead(SW);

  if (reading != lastButtonState) lastDebounce = millis();

  if ((millis() - lastDebounce) > DEBOUNCE_MS) {
    if (reading == LOW && !buttonPressed) {
      buttonPressed = true;
      pressTime = millis();
    }

    if (reading == HIGH && buttonPressed) {
      buttonPressed = false;
      unsigned long duration = millis() - pressTime;
      if (duration >= LONG_PRESS_MS) onLongPress();
      else onShortClick();
    }
  }
  lastButtonState = reading;
}

void handleEncoder() {
  lastInteraction = millis();
  static int lastCount = 0;
  if (!moved) return;
  moved = false;

  int delta = encoderCount - lastCount;
  lastCount = encoderCount;

  if (currentState == MENU) {
    menuIndex = (menuIndex + delta + mainMenuLength) % mainMenuLength;
    redraw = true;
  }
  else if (currentState == TIMER) {
    if (timerState == TIMER_SET_MIN)
      timerMinutes = constrain(timerMinutes + delta, 0, 99);
    else if (timerState == TIMER_SET_SEC)
      timerSeconds = (timerSeconds + delta + 60) % 60;
    redraw = true;
  }
  else if (currentState == EMOTION) {
    // Encoder rotation cycles through emotions
    int emotionCount = 9; // Total number of emotions
    EmotionType previousEmotion = currentEmotion;
    
    if (delta > 0) {
      currentEmotion = (EmotionType)((currentEmotion + 1) % emotionCount);
    } else if (delta < 0) {
      currentEmotion = (EmotionType)((currentEmotion - 1 + emotionCount) % emotionCount);
    }
    
    // Play sound only if emotion actually changed
    if (currentEmotion != previousEmotion) {
      setEmotionTargets(currentEmotion);
      playEmotionSound(currentEmotion);
      lastEmotionChange = millis();
    }
    redraw = true;
  }
  else if (currentState == SETTINGS) {
    // Encoder changes which setting is selected
    settingsIndex = (settingsIndex + delta + 2) % 2;
    redraw = true;
  }
}

// ===================== TIMER =====================
void updateTimer() {
  if (timerState != TIMER_RUNNING) return;

  if (millis() - lastTick >= 1000) {
    lastTick = millis();

    if (timerMinutes == 0 && timerSeconds == 0) {
      timerState = TIMER_DONE;
      startBeep(2000, 500);
    } else {
      if (timerSeconds == 0) {
        timerSeconds = 59;
        timerMinutes--;
      } else timerSeconds--;
    }
    redraw = true;
  }
}

// ===================== DRAW =====================
void drawMenu() {
  display.clearDisplay();
  display.setTextSize(1);
  for (int i = 0; i < mainMenuLength; i++) {
    if (i == menuIndex) {
      display.fillRect(0, i * 12, 128, 12, SSD1306_WHITE);
      display.setTextColor(SSD1306_BLACK);
    } else display.setTextColor(SSD1306_WHITE);
    display.setCursor(4, i * 12 + 2);
    display.println(mainMenu[i]);
  }
  display.display();
}

void drawTimer() {
  display.clearDisplay();
  char buf[6];
  sprintf(buf, "%02d:%02d", timerMinutes, timerSeconds);

  display.setTextSize(2);
  int16_t x1, y1; uint16_t w, h;
  display.getTextBounds(buf, 0, 0, &x1, &y1, &w, &h);
  display.setCursor((SCREEN_WIDTH - w) / 2, 16);
  display.println(buf);

  display.setTextSize(1);
  const char* status = (timerState == TIMER_RUNNING) ? "Running" :
                       (timerState == TIMER_PAUSED) ? "Paused" :
                       (timerState == TIMER_DONE) ? "Done" :
                       (timerState == TIMER_SET_SEC) ? "Set seconds" : "Set minutes";

  display.getTextBounds(status, 0, 0, &x1, &y1, &w, &h);
  display.setCursor((SCREEN_WIDTH - w) / 2, 44);
  display.println(status);
  display.display();
}

void drawSettings() {
  display.clearDisplay();
  display.setTextSize(1);
  display.setCursor(0, 8);

  display.print(settingsIndex == 0 ? "> " : "  ");
  display.print("Buzzer: ");
  display.println(buzzerEnabled ? "ON" : "OFF");

  display.print(settingsIndex == 1 ? "> " : "  ");
  display.print("Volume: ");
  if (volumeLevel == 0) display.println("Mute");
  else if (volumeLevel == 1) display.println("Low");
  else if (volumeLevel == 2) display.println("Medium");
  else display.println("High");

  display.setCursor(0, 48);
  display.println("Click=toggle  Hold=exit");
  display.display();
}

// ===================== COZMO-STYLE ROBOT EMOTION =====================

// Play emotion-specific sound
void playEmotionSound(EmotionType emotion) {
  if (!buzzerEnabled || volumeLevel == 0) return;
  
  switch(emotion) {
    case NEUTRAL:
      // Soft neutral beep
      startBeep(800, 100);
      break;
      
    case HAPPY:
      // Cheerful ascending tones
      tone(BUZZER_PIN, 523);  // C
      delay(80);
      tone(BUZZER_PIN, 659);  // E
      delay(80);
      tone(BUZZER_PIN, 784);  // G
      delay(100);
      noTone(BUZZER_PIN);
      break;
      
    case SAD:
      // Descending sad tones
      tone(BUZZER_PIN, 494);  // B
      delay(150);
      tone(BUZZER_PIN, 392);  // G
      delay(150);
      tone(BUZZER_PIN, 330);  // E
      delay(200);
      noTone(BUZZER_PIN);
      break;
      
    case SURPRISED:
      // Quick rising pitch
      for (int freq = 400; freq <= 1200; freq += 100) {
        tone(BUZZER_PIN, freq);
        delay(30);
      }
      noTone(BUZZER_PIN);
      break;
      
    case CURIOUS:
      // Questioning tone (up then down)
      tone(BUZZER_PIN, 600);
      delay(100);
      tone(BUZZER_PIN, 800);
      delay(100);
      tone(BUZZER_PIN, 700);
      delay(80);
      noTone(BUZZER_PIN);
      break;
      
    case ANGRY:
      // Harsh buzzing tones
      tone(BUZZER_PIN, 200);
      delay(100);
      tone(BUZZER_PIN, 180);
      delay(100);
      tone(BUZZER_PIN, 200);
      delay(100);
      noTone(BUZZER_PIN);
      break;
      
    case SLEEPY:
      // Slow descending yawn
      tone(BUZZER_PIN, 600);
      delay(200);
      tone(BUZZER_PIN, 500);
      delay(200);
      tone(BUZZER_PIN, 400);
      delay(250);
      noTone(BUZZER_PIN);
      break;
      
    case CONFUSED:
      // Warbling uncertain sound
      tone(BUZZER_PIN, 500);
      delay(80);
      tone(BUZZER_PIN, 600);
      delay(80);
      tone(BUZZER_PIN, 500);
      delay(80);
      tone(BUZZER_PIN, 550);
      delay(100);
      noTone(BUZZER_PIN);
      break;
      
    case EXCITED:
      // Fast energetic beeps
      for (int i = 0; i < 4; i++) {
        tone(BUZZER_PIN, 1000);
        delay(60);
        noTone(BUZZER_PIN);
        delay(40);
      }
      break;
  }
}

// Helper function: Smooth interpolation (easing)
float smoothLerp(float current, float target, float speed) {
  float diff = target - current;
  if (abs(diff) < 0.1) return target;
  return current + diff * speed;
}

// Set emotion targets based on emotion type
void setEmotionTargets(EmotionType emotion) {
  switch(emotion) {
    case NEUTRAL:
      // Standard upright eyes, centered
      targetEyeWidth = 24.0;
      targetEyeHeight = 32.0;
      targetEyeSpacing = 20.0;
      targetEyeY = 16.0;
      targetSquint = 0.0;
      targetPupilX = 0.0;
      targetPupilY = 0.0;
      break;
      
    case HAPPY:
      // Squinted eyes like a smile, raised position
      targetEyeWidth = 26.0;
      targetEyeHeight = 28.0;
      targetEyeSpacing = 20.0;
      targetEyeY = 18.0;
      targetSquint = 0.3;  // Squint creates happy look
      targetPupilX = 0.0;
      targetPupilY = 1.0;
      break;
      
    case SAD:
      // Drooped, lower position, narrower
      targetEyeWidth = 22.0;
      targetEyeHeight = 26.0;
      targetEyeSpacing = 20.0;
      targetEyeY = 20.0;  // Lower on screen
      targetSquint = -0.2;  // Slight droop
      targetPupilX = 0.0;
      targetPupilY = 3.0;  // Look down
      break;
      
    case SURPRISED:
      // Wide open, taller, slightly separated
      targetEyeWidth = 28.0;
      targetEyeHeight = 38.0;
      targetEyeSpacing = 24.0;  // Wider apart
      targetEyeY = 13.0;  // Higher on screen
      targetSquint = 0.0;
      targetPupilX = 0.0;
      targetPupilY = -3.0;  // Look up
      break;
      
    case CURIOUS:
      // Slightly taller, one eye raised feel
      targetEyeWidth = 24.0;
      targetEyeHeight = 34.0;
      targetEyeSpacing = 20.0;
      targetEyeY = 15.0;
      targetSquint = 0.0;
      targetPupilX = 3.0;  // Look to the side
      targetPupilY = -1.0;
      break;
      
    case ANGRY:
      // Narrowed, lower brow position, intense
      targetEyeWidth = 26.0;
      targetEyeHeight = 24.0;  // Shorter, more intense
      targetEyeSpacing = 18.0;  // Closer together
      targetEyeY = 18.0;
      targetSquint = -0.4;  // Strong downward angle
      targetPupilX = 0.0;
      targetPupilY = 0.0;
      break;
      
    case SLEEPY:
      // Half-closed, droopy
      targetEyeWidth = 24.0;
      targetEyeHeight = 18.0;  // Very short (half-closed)
      targetEyeSpacing = 20.0;
      targetEyeY = 22.0;  // Lower position
      targetSquint = 0.2;  // Slight droop
      targetPupilX = 0.0;
      targetPupilY = 2.0;  // Look slightly down
      break;
      
    case CONFUSED:
      // Asymmetric eyes, one wider than other effect
      targetEyeWidth = 23.0;
      targetEyeHeight = 30.0;
      targetEyeSpacing = 22.0;
      targetEyeY = 16.0;
      targetSquint = 0.1;
      targetPupilX = -4.0;  // Look to one side
      targetPupilY = 1.0;
      break;
      
    case EXCITED:
      // Wide, tall, energetic
      targetEyeWidth = 28.0;
      targetEyeHeight = 36.0;
      targetEyeSpacing = 22.0;
      targetEyeY = 14.0;
      targetSquint = 0.0;
      targetPupilX = 0.0;
      targetPupilY = -2.0;  // Look up with excitement
      break;
  }
}

void drawEyes() {
  display.clearDisplay();
  
  // Calculate eye centers
  int leftEyeCenterX = 32;
  int rightEyeCenterX = 96;
  int eyeCenterY = (int)eyeY + (int)eyeHeight / 2;
  
  // Calculate current eye dimensions with blink applied
  int currentEyeHeight = (int)(eyeHeight * (1.0 - blinkAmount));
  if (currentEyeHeight < 3) currentEyeHeight = 3; // Minimum during blink
  
  int currentEyeWidth = (int)eyeWidth;
  
  // Apply squint (moves top of eye down)
  int squintOffset = (int)(squintAmount * 6.0);
  int eyeTopY = eyeCenterY - currentEyeHeight / 2 + squintOffset;
  
  // Left eye - tall rounded rectangle (Cozmo style)
  int leftEyeX = leftEyeCenterX - currentEyeWidth / 2;
  display.fillRoundRect(
    leftEyeX,
    eyeTopY,
    currentEyeWidth,
    currentEyeHeight,
    10,  // Heavy corner radius for soft, friendly look
    SSD1306_WHITE
  );
  
  // Right eye
  int rightEyeX = rightEyeCenterX - currentEyeWidth / 2;
  display.fillRoundRect(
    rightEyeX,
    eyeTopY,
    currentEyeWidth,
    currentEyeHeight,
    10,
    SSD1306_WHITE
  );
  
  // Draw pupils only if eyes are open enough
  if (blinkAmount < 0.7) {
    int pupilSize = 4;
    
    // Calculate pupil positions with offset tracking
    int leftPupilX = leftEyeCenterX + (int)pupilOffsetX;
    int leftPupilY = eyeCenterY + (int)pupilOffsetY;
    int rightPupilX = rightEyeCenterX + (int)pupilOffsetX;
    int rightPupilY = eyeCenterY + (int)pupilOffsetY;
    
    // Constrain pupils within eye boundaries
    leftPupilX = constrain(leftPupilX, leftEyeX + pupilSize, leftEyeX + currentEyeWidth - pupilSize);
    leftPupilY = constrain(leftPupilY, eyeTopY + pupilSize, eyeTopY + currentEyeHeight - pupilSize);
    rightPupilX = constrain(rightPupilX, rightEyeX + pupilSize, rightEyeX + currentEyeWidth - pupilSize);
    rightPupilY = constrain(rightPupilY, eyeTopY + pupilSize, eyeTopY + currentEyeHeight - pupilSize);
    
    // Draw pupils (black circles)
    display.fillCircle(leftPupilX, leftPupilY, pupilSize, SSD1306_BLACK);
    display.fillCircle(rightPupilX, rightPupilY, pupilSize, SSD1306_BLACK);
    
    // Add highlight dots for life-like appearance
    display.fillCircle(leftPupilX - 1, leftPupilY - 1, 1, SSD1306_WHITE);
    display.fillCircle(rightPupilX - 1, rightPupilY - 1, 1, SSD1306_WHITE);
  }
  
  // Display current emotion name at bottom
  display.setTextSize(1);
  display.setCursor(0, 56);
  const char* emotionName = "";
  switch(currentEmotion) {
    case NEUTRAL: emotionName = "Neutral"; break;
    case HAPPY: emotionName = "Happy :)"; break;
    case SAD: emotionName = "Sad :("; break;
    case SURPRISED: emotionName = "Surprised!"; break;
    case CURIOUS: emotionName = "Curious?"; break;
    case ANGRY: emotionName = "Angry >:("; break;
    case SLEEPY: emotionName = "Sleepy..."; break;
    case CONFUSED: emotionName = "Confused??"; break;
    case EXCITED: emotionName = "Excited!!"; break;
  }
  display.println(emotionName);
  
  display.display();
}

void updateEmotion() {
  unsigned long now = millis();
  
  // === SMOOTH INTERPOLATION FOR ALL PARAMETERS ===
  // Eyes smoothly transition between emotion states
  eyeWidth = smoothLerp(eyeWidth, targetEyeWidth, 0.15);
  eyeHeight = smoothLerp(eyeHeight, targetEyeHeight, 0.15);
  eyeSpacing = smoothLerp(eyeSpacing, targetEyeSpacing, 0.15);
  eyeY = smoothLerp(eyeY, targetEyeY, 0.15);
  squintAmount = smoothLerp(squintAmount, targetSquint, 0.12);
  
  // Smooth pupil tracking
  pupilOffsetX = smoothLerp(pupilOffsetX, targetPupilX, 0.2);
  pupilOffsetY = smoothLerp(pupilOffsetY, targetPupilY, 0.2);
  
  // === BLINKING ANIMATION ===
  // Multi-phase smooth blink (close → hold → open)
  if (isBlinking) {
    if (blinkPhase == 1) {
      // Closing phase
      blinkAmount += 0.15;
      if (blinkAmount >= 1.0) {
        blinkAmount = 1.0;
        blinkPhase = 2;
      }
    } else if (blinkPhase == 2) {
      // Opening phase
      blinkAmount -= 0.2;
      if (blinkAmount <= 0.0) {
        blinkAmount = 0.0;
        blinkPhase = 0;
        isBlinking = false;
      }
    }
    redraw = true;
  }
  
  // Trigger random blinks
  if (!isBlinking && now - lastBlink > random(2000, 5000)) {
    isBlinking = true;
    blinkPhase = 1;
    lastBlink = now;
  }
  
  // === IDLE EYE MOVEMENT ===
  // Random subtle eye drift when not being controlled
  if (now - lastEyeMove > random(2500, 4500)) {
    targetPupilX = random(-5, 6) * 0.8;
    targetPupilY = random(-3, 4) * 0.8;
    lastEyeMove = now;
  }
  
  // === EMOTION CYCLING ===
  // Auto-cycle through emotions for demo (every 8 seconds in emotion mode)
  if (currentState == EMOTION && now - lastEmotionChange > 8000) {
    currentEmotion = (EmotionType)((currentEmotion + 1) % 9);
    setEmotionTargets(currentEmotion);
    playEmotionSound(currentEmotion);
    lastEmotionChange = now;
  }
  
  // Apply current emotion targets
  setEmotionTargets(currentEmotion);
  
  // Request redraw if anything is animating
  if (isBlinking || abs(eyeWidth - targetEyeWidth) > 0.5 || 
      abs(pupilOffsetX - targetPupilX) > 0.5) {
    redraw = true;
  }
}

// ===================== SETUP =====================
void setup() {
  lastInteraction = millis();
  pinMode(CLK, INPUT_PULLUP);
  pinMode(DT, INPUT_PULLUP);
  pinMode(SW, INPUT_PULLUP);
  pinMode(BUZZER_PIN, OUTPUT);

  attachInterrupt(digitalPinToInterrupt(CLK), encoderISR, FALLING);

  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);
  display.clearDisplay();
  display.setTextColor(SSD1306_WHITE);
  display.display();
  
  // Seed random for natural idle behavior
  randomSeed(analogRead(A0));
  
  // Initialize emotion targets
  setEmotionTargets(NEUTRAL);
}

// ===================== LOOP =====================
void loop() {
  // Auto-switch to Robot Emotions after idle timeout (only from MENU)
  if (currentState == MENU && (millis() - lastInteraction) > IDLE_TIMEOUT_MS) {
    currentState = EMOTION;
    currentEmotion = NEUTRAL;
    setEmotionTargets(NEUTRAL);
    redraw = true;
  }
  
  handleEncoder();
  handleButton();
  updateTimer();
  updateBuzzer();

  if (currentState == EMOTION) updateEmotion();

  if (redraw) {
    redraw = false;
    if (currentState == MENU) drawMenu();
    else if (currentState == TIMER) drawTimer();
    else if (currentState == SETTINGS) drawSettings();
    else drawEyes();
  }
}
