#include <stdio.h>
#include <stdlib.h>

/* Question 11: Tribal Hunting Report System
 *
 * Automatically calculate:
 * - total number of animals
 * - total weight
 * - cumulative conservation points
 */

static const int MAX_SIZE = 1000;

static const int WILD_BOAR_BONUS = 50;
static const int WILD_BOAR_BONUS_WEIGHT = 100;
static const int MAX_MUNTJAC = 5;

enum AnimalCodes { BOAR = 1, MUNTJAC, DEER };

typedef struct Input {
  int animal_code;
  int weight;
} Input;

typedef struct Report {
  int total_animals;
  int total_weight;
  int total_conservation_points;
} Report;

int read_inputs(Input record[]) {
  Input in;
  int i = 0;

  while (scanf("%d %d", &in.animal_code, &in.weight) == 2 &&
         in.animal_code != 0) {
    record[i++] = in;
  }

  return i;
};

void get_report(Input record[], Report *report) {
  int count_muntjac = 0;

  for (int i = 0; i < report->total_animals; ++i) {
    report->total_weight += record[i].weight;

    if (record[i].animal_code == MUNTJAC) {
      ++count_muntjac;
      if (count_muntjac <= MAX_MUNTJAC) {
        report->total_conservation_points += MUNTJAC * record[i].weight;
      }

    } else {
      report->total_conservation_points +=
          record[i].animal_code * record[i].weight;

      if (record[i].animal_code == BOAR &&
          record[i].weight > WILD_BOAR_BONUS_WEIGHT)
        report->total_conservation_points += WILD_BOAR_BONUS;
    }
  }
}

void print_report(Report *report) {
  printf("Total Animals Reported: %d\nTotal Weight Reported: %d kg\nTotal "
         "Conservation Points: %d\n",
         report->total_animals, report->total_weight,
         report->total_conservation_points);
}

int main() {
  Input record[MAX_SIZE];
  Report report = {0, 0, 0};

  report.total_animals = read_inputs(record);
  get_report(record, &report);
  print_report(&report);

  return EXIT_SUCCESS;
}
