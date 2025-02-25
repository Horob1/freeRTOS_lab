#include <Arduino.h>
#include <Arduino_FreeRTOS.h>
#include <semphr.h>

SemaphoreHandle_t interruptSemaphore;


void loop() {}

void interruptHandler()
{
  Serial.println("Semaphore is given");
  BaseType_t xHigherPriorityTaskWoken = pdFALSE;
  xSemaphoreGiveFromISR(interruptSemaphore, &xHigherPriorityTaskWoken);
}

void TaskLedon(void *pvParameters)
{
  (void)pvParameters;

  for (;;)
  {
    if (xSemaphoreTake(interruptSemaphore, portMAX_DELAY) == pdPASS)
    {
      Serial.println("TaskLedon Received Semaphore");
      digitalWrite(LED_BUILTIN, HIGH);
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
      digitalWrite(LED_BUILTIN, LOW);
    }
  }
}

void setup()
{
  Serial.begin(9600);

  xTaskCreate(TaskLedon, "Ledon", 128, NULL, 0, NULL);

  xTaskCreate(TaskLedoff, "Ledoff", 128, NULL, 0, NULL);

  interruptSemaphore = xSemaphoreCreateBinary();
  if (interruptSemaphore != NULL)
  {
    attachInterrupt(digitalPinToInterrupt(2), interruptHandler, HIGH);
  }
}