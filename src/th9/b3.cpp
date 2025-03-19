// #include <Arduino.h>
// #include <Arduino_FreeRTOS.h>
// #include <task.h>

// void memoryTask(void *pvParameters)
// {
//   Serial.println("Starting memoryTask...");
//   Serial.print("Stack high watermark: ");
//   Serial.println(uxTaskGetStackHighWaterMark(NULL));
//   char *dynamicMemory = (char *)pvPortMalloc(100 * sizeof(char));
//   if (dynamicMemory == NULL)
//   {
//     Serial.println("pvPortMalloc failed!");
//   }
//   else
//   {
//     Serial.println("Memory allocated.");
//     strcpy(dynamicMemory, "Hello from FreeRTOS Heap!");
//     Serial.println(dynamicMemory);
//   }
//   vPortFree(dynamicMemory);
//   Serial.println("Memory released.");

//   vTaskDelete(NULL);
// }

// void setup()
// {
//   Serial.begin(9600);
//   Serial.println("Initializing FreeRTOS Heap Example...");

//   xTaskCreate(memoryTask, "Memory Task", 256, NULL, 1, NULL);
// }

// void loop() {}
