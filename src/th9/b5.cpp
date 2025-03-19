#include <Arduino.h>
#include <Arduino_FreeRTOS.h>

void vTaskFunction(void *pvParameters)
{
  Serial.println("Task start...");
  for (int i = 0; i < 5; i++)
  {
    Serial.print("Loop count: ");
    Serial.println(i + 1);
    vTaskDelay(pdMS_TO_TICKS(1000));
  }
  Serial.println("Task finished!");
  vTaskDelete(NULL);
}

void setup()
{
  Serial.begin(9600);
  Serial.println("Start FreeRTOS!");
  BaseType_t result = xTaskCreate(vTaskFunction, "Task1", 128, NULL, 1, NULL);
  Serial.println("Task created with 128 bytes!");
  if (result != pdPASS)
  {
    Serial.println("Create task failed!");
  }
}

void loop() {}
