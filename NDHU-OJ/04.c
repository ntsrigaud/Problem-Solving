#include <stdio.h>
#include <stdlib.h>

// Question 04: Cinema Ticketing System

void print_ticket_price(const int age) {
  if (age < 0) {
    printf("Invalid age");
  } else if (age <= 5) {
    printf("Free");
  } else if (age <= 12) {
    printf("Child Ticket: $150");
  } else if (age <= 18) {
    printf("Student Ticket: $180");
  } else if (age <= 64) {
    printf("Adult Ticket: $250");
  } else {
    printf("Senior Ticket: $125");
  }
}

int main() {
  int customer_age = 0;
  scanf("%d", &customer_age);

  print_ticket_price(customer_age);

  return EXIT_SUCCESS;
}
