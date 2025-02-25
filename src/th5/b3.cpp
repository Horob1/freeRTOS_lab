// #include <Arduino.h>
// #include <Arduino_FreeRTOS.h>
// #include "semphr.h"
// SemaphoreHandle_t xMutex;

// void OutputTask(void *pvParameters);
// void printer(const char *pcString);

// void setup()
// {
//   Serial.begin(9600);
//   xMutex = xSemaphoreCreateMutex();
//   xTaskCreate(OutputTask, "Printer Task 1", 100,(void *) "Task 1 #####################Task1 \r\n", 1, NULL);
//   xTaskCreate(OutputTask, "Printer Task 2", 100,(void *) "Task 2 ---------------------Task2 \r\n", 2, NULL);
// }

// // this is a definition of tasks
// void OutputTask(void *pvParameters)
// {
//   char *pcStringToPrint;
//   pcStringToPrint = (char *)pvParameters;
//   while (1)
//   {
//     printer(pcStringToPrint);
//     vTaskDelay(pdMS_TO_TICKS(100));
//   }
// }
// // this printer task send data to arduino serial monitor
// // aslo it is shared resource between both instances of the tasks
// void printer(const char *pcString)
// {
//   // take mutex
//   xSemaphoreTake(xMutex, portMAX_DELAY);
//   Serial.println(pcString); // send string to serial monitor
//   xSemaphoreGive(xMutex);   // release mutex
// }
// void loop() {}