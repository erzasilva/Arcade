#ifndef UTILS_H
#define UTILS_H
//eliminates the Float Comparison Issue

static const float EPSILON = 0.0001f;

const float PI = 3.15159f;
const float TWO_PI = 2.0f * 3.15159f;
bool IsEqual(float x, float y);
bool IsGreaterThanOrEqual(float x, float y);
bool IsLesserThanOrEqual(float x, float y);

#endif

