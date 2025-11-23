#include <stdio.h>
#include <stdlib.h>

// Question 07: Hualien Travel Weather Advisor

typedef struct {
  double min_temp;
  const char *message;
} TempRange;

static const TempRange weather_feedback[] = {
    {28.0, "It's hot! A great day for the beach at Qixingtan or river tracing "
           "at Mugumuyu!"},
    {22.0, "The weather is comfortable. Perfect for cycling at Liyu Lake or "
           "strolling through Taroko Gorge!"},
    {18.0,
     "It's a bit cool. A good time to visit the Ruisui or Antong hot springs."},
    {-273.0, "It's cold. We recommend indoor activities, like visiting the "
             "Pine Garden."},
};

int main() {
  double in_temp = 0;
  scanf("%lf", &in_temp);

  int tmp_range_size = sizeof(weather_feedback) / sizeof(TempRange);
  for (int i = 0; i < tmp_range_size; ++i) {
    if (in_temp >= weather_feedback[i].min_temp) {
      printf("%s\n", weather_feedback[i].message);
      break;
    }
  }

  return 0;
}
