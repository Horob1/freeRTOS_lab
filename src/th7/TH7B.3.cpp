// #include <Arduino.h>
// #include <Arduino_FreeRTOS.h>

// TaskHandle_t TaskHandle_2;
// TaskHandle_t TaskHandle_3;
// TaskHandle_t TaskHandle_4;

// static void MyTask2(void *pvParameters);
// static void MyTask3(void *pvParameters);
// static void MyTask4(void *pvParameters);
// static void ExternalInterrupt();

// void setup()
// {
//   Serial.begin(9600);
//   Serial.println(F("Starting ISR and Tasks"));

//   attachInterrupt(digitalPinToInterrupt(2), ExternalInterrupt, FALLING);

//   xTaskCreate(MyTask4, "Task4", 100, NULL, 4, &TaskHandle_4);
//   xTaskCreate(MyTask3, "Task3", 100, NULL, 3, &TaskHandle_3);
//   xTaskCreate(MyTask2, "Task2", 100, NULL, 2, &TaskHandle_2);
//   vTaskStartScheduler();
// }

// void loop(){}
// static void ExternalInterrupt()
// {
//   static int count = 0;
//   BaseType_t taskYieldRequired = 0;

//   if (count <= 3)
//   {
//     count++;
//   }

//   switch (count) // Resume one task at a time depending on count value
//   {
//   case 1:
//     Serial.println(F("ISR Resuming Task2"));
//     taskYieldRequired = xTaskResumeFromISR(TaskHandle_2);
//     Serial.println(F("Leaving ISR"));
//     break;

//   case 2:
//     Serial.println(F("ISR Resuming Task3"));
//     taskYieldRequired = xTaskResumeFromISR(TaskHandle_3);
//     Serial.println(F("Leaving ISR"));
//     break;

//   case 3:
//     Serial.println(F("ISR Resuming Task4"));
//     taskYieldRequired = xTaskResumeFromISR(TaskHandle_4);
//     Serial.println(F("Leaving ISR"));
//     break;

//   default:
//     // DO nothing
//     break;
//   }

//   if (taskYieldRequired == 1)
//   {
//     taskYIELD();
//   }
// }

// /* Task2 with priority 2 */
// static void MyTask2(void *pvParameters)
// {
//   Serial.println(F("Task2, Deleting itself"));
//   vTaskDelete(NULL);
// }

// /* Task3 with priority 3 */
// static void MyTask3(void *pvParameters)
// {
//   Serial.println(F("Task3, Deleting Itself"));
//   vTaskDelete(NULL);
// }

// /* Task4 with priority 4 */
// static void MyTask4(void *pvParameters)
// {
//   Serial.println(F("Task4 Running, Suspending all tasks"));
//   vTaskSuspend(TaskHandle_2); // Suspend Task2/3
//   vTaskSuspend(TaskHandle_3);
//   vTaskSuspend(NULL); // Suspend Own Task

//   Serial.println(F("Back in Task4, Deleting Itself"));
//   vTaskDelete(TaskHandle_4);
// }