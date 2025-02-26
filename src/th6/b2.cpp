// #include <Arduino.h>
// #include <Arduino_FreeRTOS.h>
// #include "event_groups.h"

// #define TASK1_BIT (1UL << 0UL) //0b00000001
// #define TASK2_BIT (1UL << 1UL) //0b00000010
// #define TASK3_BIT (1UL << 2UL) //0b00000100

// EventGroupHandle_t xEventGroup;

// void InputTask1(void *pvParameters);
// void InputTask2(void *pvParameters);
// void InputTask3(void *pvParameters);
// void OutputTask(void *pvParameters);

// const TickType_t xDelay500ms = pdMS_TO_TICKS(500);

// void setup()
// {
//   Serial.begin(9600);
//   xEventGroup = xEventGroupCreate();
//   if (xEventGroup == NULL)
//   {
//     Serial.println("Event group creation failed!");
//     while (1)
//       ;
//   }
//   xTaskCreate(InputTask1, "Input Task 1", 100, NULL, 1, NULL);
//   xTaskCreate(InputTask2, "Input Task 2", 100, NULL, 1, NULL);
//   xTaskCreate(InputTask3, "Input Task 3", 100, NULL, 1, NULL);
//   xTaskCreate(OutputTask, "Output Task", 100, NULL, 1, NULL);
//   vTaskStartScheduler();
// }

// // defintion of input task1
// void InputTask1(void *pvParameters)
// {
//   while (1)
//   {
//     // set flag bit TASK1_BIT
//     xEventGroupSetBits(xEventGroup, TASK1_BIT);
//     // delay this task for 500ms
//     vTaskDelay(xDelay500ms);
//   }
// }

// // defintion of input task2

// void InputTask2(void *pvParameters)
// {
//   while (1)
//   {
//     // set flag bit TASK2_BIT
//     xEventGroupSetBits(xEventGroup, TASK2_BIT);
//     // delay this task for 500ms
//     vTaskDelay(xDelay500ms);
//   }
// }

// // defintion of input task3

// void InputTask3(void *pvParameters)
// {
//   while (1)
//   {
//     // set flag bit TASK2_BIT
//     xEventGroupSetBits(xEventGroup, TASK3_BIT);
//     // delay this task for 500ms
//     vTaskDelay(xDelay500ms);
//   }
// }

// //  Definition of output task
// void OutputTask(void *pvParameters)
// {
//   // define a variable which holds the state of events
//   const EventBits_t xBitsToWaitFor = (TASK1_BIT | TASK2_BIT | TASK3_BIT);
//   EventBits_t xEventGroupValue;
//   while (1)
//   {
//     xEventGroupValue = xEventGroupWaitBits(xEventGroup,
//                                            xBitsToWaitFor,
//                                            pdTRUE,
//                                            pdTRUE,
//                                            portMAX_DELAY);
//     if ((xEventGroupValue & TASK1_BIT) != 0)
//     {
//       Serial.println("Task1 event occured");
//     }
//     if ((xEventGroupValue & TASK2_BIT) != 0)
//     {
//       Serial.println("Task2 event occured");
//     }
//     if ((xEventGroupValue & TASK3_BIT) != 0)
//     {
//       Serial.println("Task3 event occured");
//     }
//   }
// }
// void loop() {}