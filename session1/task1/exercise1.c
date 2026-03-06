#include <stdio.h>
#include <stdlib.h>


int getLimit(int speed_limit, char input[]) {
  // Get user input for speed limit
  printf("Enter the speed limit: ");
  if (fgets(input, sizeof(input), stdin)) {
    sscanf(input, "%d", &speed_limit);

    return speed_limit;
  }
}
  
  
  int getSpeed(int driver_speed, char input[]) {
  // Get user input for driver's speed
  printf("Enter the driver's speed: ");
  if (fgets(input, sizeof(input), stdin)) {
    sscanf(input, "%d", &driver_speed);

    return driver_speed;
  }
}


  int calcFine(int speed_limit, int driver_speed, int fine) {
  // Determine if the driver is speeding
  if (driver_speed > speed_limit) {
    int excess_speed = driver_speed - speed_limit;

    // Calculate fine based on how much over the limit
    if (excess_speed <= 10) {
      fine = 50;
    } else if (excess_speed <= 20) {
      fine = 100;
    } else {
      fine = 200;
    }

   
  return fine;
  }
}


int main() {
  int speed_limit, driver_speed, fine = 0;
  char input[20];
  speed_limit = getLimit(speed_limit, input);
  driver_speed = getSpeed(driver_speed, input);
  fine = calcFine(driver_speed, speed_limit, fine);

  printf("Your fine is £%d\n", fine);

  return 0;
}
