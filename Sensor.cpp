#include "Sensor.h"

Sensor::Sensor(int pin)
{
  this->pin = pin;
  // Define pin as Input
  pinMode (pin, INPUT);
}

int Sensor::get_distance()
{
  int arr[NB_SAMPLE];
  for(int i=0; i<25; i++)
  {
    arr[i] = analogRead(this->pin);
  }
  int median = find_median(arr);
  float distance_help = map(median, 0, 1023, 0, 5000)/1000.0;
  return pow(((distance_help + 0.45) / 9.08), (-1/0.6809)) - 0.97;
}

int Sensor::find_median(int* measurements)
{
  return this->select(measurements, 0, 24, 12);
}

int Sensor::partition(int *arr, int left, int right)
{
  int x = arr[left];
  int i = left;
  int key;
  for (int j = left + 1; j <= right; j++)
  {
    if (arr[j] <= x)
    { 
      i = i+1;
      key = arr[i];
      arr[i] = arr[j];
      arr[j] = key;     
    }
  }
  key = arr[i];
  arr[i]= arr[left];
  arr[left] = key;
  return i;
}

int Sensor::select(int *arr, int left, int right, int i)
{
  if (left == right)
  {
    return arr[left];
  }
  int r = this->partition(arr, left, right);
  int k = r - left + 1;
  if (i == k)
  {
    return arr[r];
  }
  if (i < k)
  {
    return this->select(arr, left, r - 1, i);
  }
  else
   {
    return select(arr, r + 1, right, i - k);
  }
}
