#include "Sensor.h"

/* Project level constants */
#define RANGE_SENSOR_PIN_0  0
#define RANGE_SENSOR_PIN_1  1
#define RANGE_SENSOR_PIN_2  2
#define RANGE_SENSOR_PIN_3  3
#define RANGE_SENSOR_PIN_4  4

/*granica koliko želim ispisa u loopu, koristim u if petlji*/
#define MAX_VALUES 51 

/*pomoćna varijabla da si ograničim broj ispisa u loopu*/
int tmp = 1; 

/* Instances */
Sensor* sensor_0 = new Sensor(RANGE_SENSOR_PIN_0);
Sensor* sensor_1 = new Sensor(RANGE_SENSOR_PIN_1);
Sensor* sensor_2 = new Sensor(RANGE_SENSOR_PIN_2);
Sensor* sensor_3 = new Sensor(RANGE_SENSOR_PIN_3);
Sensor* sensor_4 = new Sensor(RANGE_SENSOR_PIN_4);

/* Setup function */
void setup() {
  Serial.begin(9600);
}

/* Infinite loop */
void loop() {
  /* Check for obstacles */
  if(tmp < MAX_VALUES){ 
    Serial.print(sensor_0->get_distance());
    Serial.print(" ");
    Serial.print(sensor_1->get_distance());
    Serial.print(" ");
    Serial.print(sensor_2->get_distance());
    Serial.print(" ");
    Serial.print(sensor_3->get_distance());
    Serial.print(" ");
    Serial.print(sensor_4->get_distance());
    Serial.println();
  }
  tmp += 1;
  /* Avoid reading before the new distance is sampled */
  delay(100);
}
