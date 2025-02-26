// #include <Arduino.h>
// #include <Arduino_FreeRTOS.h>
// #include <queue.h>

// QueueHandle_t xMailbox;
// TaskHandle_t TaskSendHandle;
// TaskHandle_t TaskReceiveHandle;
// void taskSend(void *pvParameters);
// void taskReceive(void *pvParameters);

// void setup()
// {
//   Serial.begin(9600);
//   pinMode(8, OUTPUT);
//   pinMode(9, OUTPUT);
//   digitalWrite(8, HIGH);
//   digitalWrite(9, LOW);
//   xMailbox = xQueueCreate(1, sizeof(int32_t));
//   if (xMailbox == NULL)
//   {
//     Serial.println("Queue creation failed!");
//     while (1)
//       ;
//   }
//   xTaskCreate(taskSend, "Sender", 256, NULL, 1, &TaskSendHandle);
//   xTaskCreate(taskReceive, "Receiver", 256, NULL, 1, &TaskReceiveHandle);
//   vTaskStartScheduler();
// }

// void loop() {}

// void taskSend(void *pvParameters)
// {
//   int32_t ulNewValue = 1;
//   while (1)
//   {
//     ulNewValue = random(0, 10);
//     xQueueOverwrite(xMailbox, &ulNewValue);
//     Serial.print("Data written to mailbox: ");
//     Serial.println(ulNewValue);
//     vTaskDelay(1000 / portTICK_PERIOD_MS);
//   }
// }

// void taskReceive(void *pvParameters)
// {
//   int32_t value_received;
//   while (1)
//   {
//     if (
//         xQueueReceive(xMailbox, &value_received, (1000 / portTICK_PERIOD_MS)) == pdTRUE)
//     {
//       Serial.print("Data Read from mailbox = ");
//       Serial.println(value_received);
//       if (value_received > 4)
//       {
//         digitalWrite(8, HIGH);
//         digitalWrite(9, LOW);
//       }
//       else
//       {
//         digitalWrite(8, LOW);
//         digitalWrite(9, HIGH);
//       }
//       vTaskDelay(500 / portTICK_PERIOD_MS);
//     }
//   }
// }