#include <Arduino.h>
#include <Arduino_FreeRTOS.h>
#include "queue.h"

#define TIMER_LED 13
#define BUTTON_LED 12
#define BUTTON_PIN 2

QueueHandle_t xStringQueue;
QueueHandle_t xLedQueue;
int timer1_counter;
void vStringPrinter(void *pvParameters);
void vLedController(void *pvParameters);
void InterruptInit();
void ButtonISR();
void setup()
{
  Serial.begin(9600);

  pinMode(TIMER_LED, OUTPUT);
  pinMode(BUTTON_LED, OUTPUT);
  pinMode(BUTTON_PIN, INPUT_PULLUP);

  xStringQueue = xQueueCreate(5, sizeof(char *));
  xLedQueue = xQueueCreate(5, sizeof(int));

  xTaskCreate(vStringPrinter, "StringPrinter", 100, NULL, 1, NULL);
  xTaskCreate(vLedController, "LedController", 100, NULL, 1, NULL);

  attachInterrupt(digitalPinToInterrupt(BUTTON_PIN), ButtonISR, FALLING);
  InterruptInit();
}

void vStringPrinter(void *pvParameters)
{
  char *pcString;
  while (1)
  {
    if (xQueueReceive(xStringQueue, &pcString, portMAX_DELAY) == pdPASS)
    {
      Serial.println(pcString);
    }
  }
}

void vLedController(void *pvParameters)
{
  int ledPin;
  while (1)
  {
    if (xQueueReceive(xLedQueue, &ledPin, portMAX_DELAY) == pdPASS)
    {
      digitalWrite(ledPin, HIGH);
      vTaskDelay(pdMS_TO_TICKS(100));
      digitalWrite(ledPin, LOW);
    }
  }
}

ISR(TIMER1_OVF_vect)
{
  TCNT1 = timer1_counter;
  static const char *pcString = "Hello World";
  xQueueSendToBackFromISR(xStringQueue, &pcString, pdFALSE);
  int ledPin = TIMER_LED;
  xQueueSendToBackFromISR(xLedQueue, &ledPin, pdFALSE);
}

void ButtonISR()
{
  static const char *pcString = "Interrupt From Button";
  xQueueSendToBackFromISR(xStringQueue, &pcString, pdFALSE);
  int ledPin = BUTTON_LED;
  xQueueSendToBackFromISR(xLedQueue, &ledPin, pdFALSE);
}

void loop() {}

void InterruptInit()
{
  noInterrupts();
  TCCR1A = 0;
  TCCR1B = 0;
  TCNT1 = 0;
  timer1_counter = 3036;
  TCNT1 = timer1_counter;
  TCCR1B |= (1 << CS12);
  TIMSK1 |= (1 << TOIE1);
  interrupts();
}
