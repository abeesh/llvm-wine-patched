#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

struct foo
{
  uint8_t   first_val;
  uint32_t  second_val;
  uint64_t  third_val;
};

struct bar
{
  int value;
};

int main ()
{
  int val = 100;
  struct foo mine = {55, 5555, 55555555};
  struct foo *ptr = (struct foo *) malloc (sizeof (struct foo));
  ptr->first_val = 66;
  ptr->second_val = 6666;
  ptr->third_val = 66666666;

  struct bar _b1 = {.value = 1};
  struct bar _b2 = {.value = 2};
  struct bar *b1 = &_b1;
  struct bar *b2 = &_b2;

  int _arr1[] = {1, 2};
  int _arr2[] = {3, 4};
  int* arr1 = _arr1;
  int* arr2 = _arr2;

  // Stop here and set values
  printf ("Val - %d Mine - %d, %d, %llu. Ptr - %d, %d, %llu\n", val, 
          mine.first_val, mine.second_val, mine.third_val,
          ptr->first_val, ptr->second_val, ptr->third_val); 

  // Stop here and check values
  printf ("This is just another call which we won't make it over %d.", val);
  return 0; // Set a breakpoint here at the end
}
