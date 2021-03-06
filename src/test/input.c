#include "framework/unity_fixture.h"
#include "framework/unity.h"

#include <string.h>
#include <unistd.h>
#include "../input.h"

TEST_GROUP(input);

TEST_SETUP(input) 
{ 
} 
 
TEST_TEAR_DOWN(input) 
{ 
}

TEST(input, KevKeyService)
{
  int i;
  char *input = "iwanttofiddle";
  tU32 *result;
  for (i = 0; i < strlen(input); i++) {
    gLast_key_down = input[i] - 75;
    result = KevKeyService();
    gLast_key_down = 0;
    result = KevKeyService();
  }
  sleep(1);
  gLast_key_down = 0;
  result = KevKeyService();

  TEST_ASSERT_EQUAL_INT(0x33f75455, result[0]);
  TEST_ASSERT_EQUAL_INT(0xc10aaaf2, result[1]);
}

TEST_GROUP_RUNNER(input) {
  RUN_TEST_CASE(input, KevKeyService);
}
