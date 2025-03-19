// #include <Arduino.h>
// #include <Arduino_FreeRTOS.h>
// #include <queue.h>

// #define BUF_LEN 64
// static QueueHandle_t xQueue;

// void readSerial(void *parameters)
// {
//   char buf[BUF_LEN];
//   uint8_t idx = 0;
//   memset(buf, 0, BUF_LEN);
//   while (1)
//   {
//     if (Serial.available() > 0)
//     {
//       char c = Serial.read();
//       if (idx < BUF_LEN - 1)
//       {
//         buf[idx++] = c;
//       }
//       if (c == '\n')
//       {
//         buf[idx - 1] = '\0';
//         Serial.println("Reading terminal ...");
//         vTaskDelay(1000 / portTICK_PERIOD_MS);
//         xQueueSend(xQueue, buf, portMAX_DELAY);
//         idx = 0;
//         memset(buf, 0, BUF_LEN);
//       }
//     }
//     vTaskDelay(100 / portTICK_PERIOD_MS);
//   }
// }

// void printMessage(void *parameters)
// {
//   char receivedBuf[BUF_LEN];
//   while (1)
//   {
//     if (xQueueReceive(xQueue, receivedBuf, portMAX_DELAY) == pdTRUE)
//     {
//       Serial.println("Printing ...");
//       vTaskDelay(1000 / portTICK_PERIOD_MS);
//       Serial.println(receivedBuf);
//     }
//     vTaskDelay(100 / portTICK_PERIOD_MS);
//   }
// }

// void setup()
// {
//   Serial.begin(9600);
//   Serial.println("Enter a string:");
//   xQueue = xQueueCreate(5, BUF_LEN);
//   xTaskCreate(readSerial, "Read Serial", 128, NULL, 1, NULL);
//   xTaskCreate(printMessage, "Print Message", 128, NULL, 1, NULL);
// }

// void loop() {}
