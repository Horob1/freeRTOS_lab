// #include <Arduino.h>
// #include <Arduino_FreeRTOS.h>
// #include <task.h>
// #include <stdlib.h>
// #include <assert.h>

// static volatile bool initialized_ = false;

// void malloc_init()
// {
//   initialized_ = true;
// }

// void *allocateMemory(size_t size)
// {
//   while (!initialized_)
//   {
//     vTaskDelay(1);
//   }
//   return malloc(size);
// }

// void releaseMemory(void *ptr)
// {
//   if (ptr)
//   {
//     free(ptr);
//   }
// }

// void memoryTask(void *pvParameters)
// {
//   Serial.println("Starting memoryTask...");
//   Serial.print("Stack high watermark: ");
//   Serial.println(uxTaskGetStackHighWaterMark(NULL));

//   char *dynamicMemory = (char *)allocateMemory(100 * sizeof(char));
//   if (dynamicMemory == NULL)
//   {
//     Serial.println("Memory allocation failed!");
//   }
//   else
//   {
//     Serial.println("Memory allocated.");
//     strcpy(dynamicMemory, "Hello from FreeRTOS Heap!");
//     Serial.println(dynamicMemory);
//   }
//   releaseMemory(dynamicMemory);
//   Serial.println("Memory released.");

//   vTaskDelete(NULL);
// }

// void setup()
// {
//   Serial.begin(9600);
//   Serial.println("Initializing FreeRTOS Heap Example...");
//   malloc_init();
//   xTaskCreate(memoryTask, "Memory Task", 128, NULL, 1, NULL);
// }

// void loop() {}