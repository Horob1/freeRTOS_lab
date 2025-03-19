// #include <Arduino.h>
// #include <Arduino_FreeRTOS.h>
// #include <semphr.h>
// SemaphoreHandle_t xCountingSemaphore;
// void Task1(void* paramaters);
// void Task2(void *paramaters);

// void setup()
// {
//   Serial.begin(9600); // Enable serial communication library.
//   pinMode(LED_BUILTIN, OUTPUT);

//   // Create task for Arduino led
//   xTaskCreate(Task1,   // Task function
//               "Ledon", // Task name
//               256,     // Stack size
//               NULL,
//               1, // Priority
//               NULL);
//   xTaskCreate(Task2,    // Task function
//               "Ledoff", // Task name
//               256,      // Stack size
//               NULL,
//               1, // Priority
//               NULL);
//   xCountingSemaphore = xSemaphoreCreateCounting(1, 1);
//   xSemaphoreGive(xCountingSemaphore);
// }

// void loop() {}

// void Task1(void *pvParameters)
// {
//   (void)pvParameters;

//   while (1)
//   {
//     xSemaphoreTake(xCountingSemaphore, portMAX_DELAY);
//     Serial.println("Inside Task1 and STerminal Taken");
//     digitalWrite(LED_BUILTIN, HIGH);
//     xSemaphoreGive(xCountingSemaphore);
//     vTaskDelay(1000 / portTICK_PERIOD_MS);
//   }
// }

// void Task2(void *pvParameters)
// {
//   (void)pvParameters;
//   while (1)
//   {
//     xSemaphoreTake(xCountingSemaphore, portMAX_DELAY);
//     Serial.println("Inside Task2 and Terminal Taken");
//     digitalWrite(LED_BUILTIN, LOW);
//     xSemaphoreGive(xCountingSemaphore);
//     vTaskDelay(1000 / portTICK_PERIOD_MS);
//   }
// }
