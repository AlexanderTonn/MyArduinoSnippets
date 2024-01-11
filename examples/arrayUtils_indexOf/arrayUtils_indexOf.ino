#include "atUtility.h"

atUtilities atUtil;

void setup()
{
  Serial.begin(9600);

  Array<int, 5> a1 = {{42, 420, 1337, 666, 69}};
  Array<bool, 5> a2 = {{true, false, true, false, true}};

  // returning valid indices
  Serial.println(atUtil.indexOf(a1, 1337));
  Serial.println(atUtil.indexOf(a2, false));

  // value not found: returning 0
  Serial.println(atUtil.indexOf(a1, 6));
}

void loop()
{
}