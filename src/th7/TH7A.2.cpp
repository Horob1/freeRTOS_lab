#include <Arduino_FreeRTOS.h>
#include <Arduino.h>
#include <semphr.h>
SemaphoreHandle_t interruptSemaphore;
int ledPin = 13;
void TaskLedon(void *pvParameters)
{
  (void)pvParameters;

  for (;;)
  {
    if (xSemaphoreTake(interruptSemaphore, portMAX_DELAY) == pdPASS)
    {
      Serial.println("TaskLedon Received Semaphore");
      digitalWrite(ledPin, HIGH);
    }
  }
}

void TaskLedoff(void *pvParameters)
{
  (void)pvParameters;
  for (;;)
  {
    if (xSemaphoreTake(interruptSemaphore, portMAX_DELAY) == pdPASS)
    {
      Serial.println("TaskLedoff Received Semaphore");
      digitalWrite(ledPin, LOW);
    }
  }
}
void interruptHandler()
{
  Serial.println("Semaphore is given");
  BaseType_t xHigherPriorityTaskWoken pdFALSE;
  xSemaphoreGiveFromISR(interruptSemaphore, &xHigherPriorityTaskWoken);
}

void setup()
{
  Serial.begin(9600);
  pinMode(ledPin, OUTPUT);

  xTaskCreate(TaskLedon,
              "Ledon",
              128,
              NULL,
              0,
              NULL);
  xTaskCreate(TaskLedoff,
              "Ledoff",
              128,
              NULL,
              0,
              NULL);
  interruptSemaphore = xSemaphoreCreateBinary();
  if (interruptSemaphore != NULL)
  {
    attachInterrupt(digitalPinToInterrupt(2), interruptHandler, HIGH);
  }
}

void loop() {}
