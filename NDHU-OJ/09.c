#include <stdio.h>
#include <stdlib.h>

/*
 * Question 09: Hualien County Smart Agriculture Subsidy Calculation System
 *
 * ---- Subsidy Calculation System ----
 *
 * Inputs:
 * ------
 * crop_type    -> 1 (Rice), 2 (Pomelo), 3 (Watermelon)
 * farmer_age   -> int
 * is_organic   -> boolean
 * area         -> Area in ha (float)
 *
 *
 * Computation Rules:
 * ------------------
 * 1) Determine the base_rate
 *      Rice        -> $10,000 / ha
 *      Pomelo      -> $8,000 / ha
 *      Watermelon  -> $6,000 / ha
 *
 * 2) Compute bonus_multipliers (Multipliers can stack)
 *      organic_bonus = (is_organic) ? 1.5 : 1
 *      young_farmer_bonus = (farmer_age <= 40 ) ? 1.2 : 1
 *
 * 3) Apply Special Exception Rules
 *      A) Pomelo Organic Special Clause:
 *          is_pomelo && is_organic => organic_bonus = 1.8
 *      B) Watermelon Small-Scale Clause
 *          is_watermelon && (area < 0.5 ha) => young_farmer_bonus = 1
 *      C) Rice Large-Holder Clause
 *          if is_crop_rice AND (area > 5 ha):
 *            exceeding_area = area - 5
 *            subsidy = compute_subsidy(5, 1) + compute_subsidy(exceeding_area,
 * 0.8)
 *
 * 4) Final Cap
 *      return (total_subsidy > 200,000) ? 200,000 : total_subsidy
 * */

static const int MAX_SUBSIDY = 200000;
static const int YOUNG_FARMER_MIN_AGE = 40;
static const double ORGANIC_BONUS_MULTIPLIER = 1.5;
static const double YOUNG_FARMER_BONUS_MULTIPLIER = 1.2;
static const double POMELO_ORGANIC_MULTIPLIER = 1.2;
static const double WATERMELON_CLAUSE_MAX_AREA = 0.5;
static const double WATERMELON_CLAUSE_RATE_REDUCE = 1.2;
static const double RICE_CLAUSE_MIN_AREA = 5;
static const double RICE_CLAUSE_BONUS_MULTIPLIER = 0.8;

static const int BASE_RATES[] = {0, 10000, 8000, 6000};

enum CropType { INVALID, RICE, POMELO, WATERMELON };

typedef struct Input {
  int crop_type;
  int farmer_age;
  int is_organic;
  float area;
} Input;

typedef struct TestCase {
  Input value;
  int answer;
} TestCase;

int get_subsidy(const Input *info) {
  // Determine base rate
  int rate = (info->crop_type > INVALID && info->crop_type <= WATERMELON)
                 ? BASE_RATES[info->crop_type]
                 : BASE_RATES[INVALID];

  // ---- Bonus Multipliers ----
  // Organic Bonus
  rate = (info->is_organic) ? rate * ORGANIC_BONUS_MULTIPLIER : rate;

  // Young Farmer Bonus
  rate = (info->farmer_age <= YOUNG_FARMER_MIN_AGE)
             ? rate * YOUNG_FARMER_BONUS_MULTIPLIER
             : rate;

  // ---- Special exception rules ----
  // Pomelo Organic Special Clause
  rate = (info->crop_type == POMELO && info->is_organic)
             ? rate * POMELO_ORGANIC_MULTIPLIER
             : rate;

  // Watermelon Small-Scale Clause
  rate = (info->crop_type == WATERMELON &&
          info->area < WATERMELON_CLAUSE_MAX_AREA &&
          info->farmer_age <= YOUNG_FARMER_MIN_AGE)
             ? rate / WATERMELON_CLAUSE_RATE_REDUCE
             : rate;

  // Rice Large-Holder Clause
  int subsidy = (info->crop_type == RICE && info->area > RICE_CLAUSE_MIN_AREA)
                    ? rate * RICE_CLAUSE_MIN_AREA +
                          (info->area - RICE_CLAUSE_MIN_AREA) *
                              RICE_CLAUSE_BONUS_MULTIPLIER * rate
                    : rate * info->area;

  return subsidy > MAX_SUBSIDY ? MAX_SUBSIDY : subsidy;
}

void take_info(Input *info);

#ifdef UNIT_TEST

// Use `gcc -DUNIT_TEST -o app_test 09.c` for testing

void test(void);

void test(void) {
  TestCase test_cases[] = {
      {{1, 55, 0, 4.0}, 40000},   {{1, 30, 1, 3.0}, 54000},
      {{2, 60, 1, 5.0}, 72000},   {{1, 50, 0, 10.0}, 90000},
      {{2, 35, 1, 12.0}, 200000},
  };

  int test_case_len = sizeof(test_cases) / sizeof(TestCase);
  int total_subsidy = 0;
  int test_success = 0;

  for (int i = 0; i < test_case_len; ++i) {
    total_subsidy = get_subsidy(&test_cases[i].value);
    if (total_subsidy != test_cases[i].answer) {
      printf("Test case %d: ", i);
      printf("Expected %d, got %d\n", test_cases[i].answer, total_subsidy);
    } else {
      ++test_success;
    }
  }
};

int main() {
  test();
  return EXIT_SUCCESS;
}

#else

int main() {
  Input in;

  take_info(&in);
  int subsidy = get_subsidy(&in);
  printf("Final Subsidy: %d\n", subsidy);

  return EXIT_SUCCESS;
}

#endif

void take_info(Input *info) {
  scanf("%d", &(info->crop_type));
  scanf("%d", &(info->farmer_age));
  scanf("%d", &(info->is_organic));
  scanf("%f", &(info->area));
}
