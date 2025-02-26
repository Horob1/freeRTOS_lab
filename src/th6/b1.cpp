// #include <Arduino.h>
// #include <Arduino_FreeRTOS.h>
// #include <queue.h>

// QueueHandle_t xMailbox;
// TaskHandle_t TaskHandle_1;
// TaskHandle_t TaskHandle_2;

// void vUpdateMailbox(void *pvParameters);
// void vReadMailbox(void *pvParameters);

// void setup()
// {
//   Serial.begin(9600);

//   xMailbox = xQueueCreate(1, sizeof(int32_t));
//   if (xMailbox == NULL)
//   {
//     Serial.println("Queue creation failed!");
//     while (1)
//       ;
//   }

//   xTaskCreate(vUpdateMailbox, "Sender", 256, NULL, 1, &TaskHandle_1);
//   xTaskCreate(vReadMailbox, "Receiver", 256, NULL, 1, &TaskHandle_2);
//   vTaskStartScheduler();
// }

// void loop(){}

// void vUpdateMailbox(void *pvParameters)
// {
//   int32_t ulNewValue = 1;
//   while (1)
//   {
//     xQueueOverwrite(xMailbox, &ulNewValue);
//     Serial.print("Data written to mailbox: ");
//     Serial.println(ulNewValue);
//     ulNewValue++;
//     vTaskDelay(500);
//   }
// }

// void vReadMailbox(void *pvParameters)
// {
//   int32_t value_received;
//   while (1)
//   {
//     xQueuePeek(xMailbox, &value_received, portMAX_DELAY);
//     Serial.print("Data Read from mailbox = ");
//     Serial.println(value_received);
//     vTaskDelay(100);
//   }
// }
