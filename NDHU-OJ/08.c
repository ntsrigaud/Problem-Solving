#include <stdio.h>
#include <stdlib.h>

/* Question 08: Taiwan Tourist Shuttle (Taroko Route) Fare Calculator
 *
 * Facts
 * -----
 *  - The final fare depends on:
 *    - the day of travel
 *    - the passenger type
 *    - the ticket type
 *  - Objective:
 *    - Calculate the final fare based on the previously defined input values.
 *
 * Procedure
 * ---------
 * 1) Base fare computation:
 *      - Day Pass -> $250
 *      - One-way ticket -> $150
 * 2) Apply Identity Discount
 *      - Child ( age < 12) && Senior (age >= 65) --> base_fare * 0.50
 *      - Adult --> base_fare
 * 3) Add Holiday Surcharge
 *      - Weekend / Holiday --> price_after_any_discount =
 * price_after_any_discount * 1.20
 *      - Weekday --> No surcharge
 *
 * COMPUTATION ORDER MATTERS.
 * */

enum DayType { WEEKDAY = 1, HOLIDAY };
enum PassengerType { ADULT = 1, CHILD, SENIOR };
enum TicketType { ONE_WAY = 1, DAY_PASS };

typedef struct TravelInfo {
  int day_type;
  int passenger_type;
  int ticket_type;
} TravelInfo;

void take_input(TravelInfo *info) {
  scanf("%d", &info->day_type);
  scanf("%d", &info->passenger_type);
  scanf("%d", &info->ticket_type);
}

int compute_fare(TravelInfo *info) {
  // Base fare computation
  int fare = (info->ticket_type == ONE_WAY) ? 150 : 250;

  // Identity discount
  fare = (info->passenger_type == ADULT) ? fare : fare / 2;

  // Holiday surcharge
  fare = (info->day_type == HOLIDAY) ? (fare * 6) / 12 : fare;

  return fare;
};

int main() {

  TravelInfo info;
  take_input(&info);
  int fare = compute_fare(&info);
  printf("Final Fare: %d", fare);

  return EXIT_SUCCESS;
}
