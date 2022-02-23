#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file

#include "test/catch.hpp"
#include "typewise-alert.h"

TEST_CASE("infers the breach according to limits") 
{
  REQUIRE(inferBreach(12, 20, 30) == TOO_LOW);
  REQUIRE(inferBreach(30, 10, 25) == TOO_HIGH);
  REQUIRE(inferBreach(30, 45, 90) == NORMAL);
}

/*TEST_CASE("Classify Temperature Range") 
{
  //Passive cooling test cases
  REQUIRE(classifyTemperatureBreach(PASSIVE_COOLING, -1) == TOO_LOW);
  REQUIRE(classifyTemperatureBreach(PASSIVE_COOLING, 0) == NORMAL);
  REQUIRE(classifyTemperatureBreach(PASSIVE_COOLING, 35) == NORMAL);
  REQUIRE(classifyTemperatureBreach(PASSIVE_COOLING, 30) == NORMAL);
  REQUIRE(classifyTemperatureBreach(PASSIVE_COOLING, 45) == TOO_HIGH);
  
  //Hi-Active cooling test cases
  REQUIRE(classifyTemperatureBreach(HI_ACTIVE_COOLING, -2) == TOO_LOW);
  REQUIRE(classifyTemperatureBreach(HI_ACTIVE_COOLING, 0) == NORMAL);
  REQUIRE(classifyTemperatureBreach(HI_ACTIVE_COOLING, 45) == NORMAL);
  REQUIRE(classifyTemperatureBreach(HI_ACTIVE_COOLING, 35) == NORMAL);
  REQUIRE(classifyTemperatureBreach(HI_ACTIVE_COOLING, 50) == TOO_HIGH); 
}  */

TEST_CASE("Testing Check and Alert Function") 
{
   REQUIRE(checkAndAlert(TO_CONTROLLER, PASSIVE_COOLING, -1) == TOO_LOW);
   REQUIRE(checkAndAlert(TO_CONTROLLER, PASSIVE_COOLING,  0) == NORMAL);
   REQUIRE(checkAndAlert(TO_CONTROLLER, PASSIVE_COOLING,  35) == NORMAL);
   REQUIRE(checkAndAlert(TO_CONTROLLER, PASSIVE_COOLING,   30) == NORMAL);
   REQUIRE(checkAndAlert(TO_CONTROLLER, PASSIVE_COOLING,  45)  == TOO_HIGH);
  
   REQUIRE(checkAndAlert(TO_EMAIL, HI_ACTIVE_COOLING,  -2)  == TOO_LOW);
   REQUIRE(checkAndAlert(TO_EMAIL, HI_ACTIVE_COOLING,   0)  == NORMAL);
   REQUIRE(checkAndAlert(TO_EMAIL, HI_ACTIVE_COOLING,  45)  == NORMAL);
   REQUIRE(checkAndAlert(TO_EMAIL, HI_ACTIVE_COOLING,  35)  == NORMAL);
   REQUIRE(checkAndAlert(TO_EMAIL, HI_ACTIVE_COOLING,  50)  == TOO_HIGH);
   
   REQUIRE(checkAndAlert(TO_EMAIL, MED_ACTIVE_COOLING,  -6)  == TOO_LOW);
   REQUIRE(checkAndAlert(TO_EMAIL, MED_ACTIVE_COOLING,   0)  == NORMAL);
   REQUIRE(checkAndAlert(TO_EMAIL, MED_ACTIVE_COOLING,   40)  == NORMAL);
   REQUIRE(checkAndAlert(TO_EMAIL, MED_ACTIVE_COOLING,   10)  == NORMAL);
   REQUIRE(checkAndAlert(TO_EMAIL, MED_ACTIVE_COOLING,   63)  == TOO_HIGH);  
}
