// #include <Arduino.h>
// #include <Wire.h>
// #include <LiquidCrystal_I2C.h>
// #include <Arduino_FreeRTOS.h>
// #include <queue.h>

// LiquidCrystal_I2C lcd(0x27, 16, 2);
// const int analogPin = A0;

// QueueHandle_t xQueue;

// void taskReadADC(void *pvParameters)
// {
//   int adc = 0;
//   double volt = 0;
//   int newAdc = 0;
//   while (1)
//   {
//     newAdc = analogRead(analogPin);
//     if (newAdc != adc)
//     {
//       adc = newAdc;
//       volt = adc * 5.0 / 1023;
//       Serial.print("AdcTask = ");
//       Serial.println(adc);
//       Serial.print("VoltTask = ");
//       Serial.println(volt);
//       xQueueSend(xQueue, &volt, portMAX_DELAY);
//     }

//     vTaskDelay(1000 / portTICK_PERIOD_MS);
//   }
// }

// void taskDisplay(void *pvParameters)
// {
//   double value;
//   while (1)
//   {
//     if (xQueueReceive(xQueue, &value, portMAX_DELAY) == pdTRUE)
//     {
//       lcd.setCursor(0, 0);
//       lcd.print("Volt: ");
//       lcd.print(value);
//     }
//     vTaskDelay(1000 / portTICK_PERIOD_MS);
//   }
// }

// void setup()
// {
//   Serial.begin(9600);
//   lcd.init();
//   lcd.backlight();
//   xQueue = xQueueCreate(5, sizeof(double));
//   if (xQueue == NULL)
//   {
//     Serial.println("Error creating the queue!");
//     while (1)
//       ; // Dừng chương trình
//   }
//   pinMode(analogPin, INPUT);
//   xTaskCreate(taskReadADC, "ReadADC", 128, NULL, 2, NULL);
//   xTaskCreate(taskDisplay, "Display", 128, NULL, 1, NULL);
//   vTaskStartScheduler();
// }

// void loop(){}