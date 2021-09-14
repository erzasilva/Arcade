#ifndef UTILS_H
#define UTILS_H
//eliminates the Float Comparison Issue

static const float EPSILON = 0.0001f;
bool IsEqual(float x, float y);
bool IsGreaterThanOrEqual(float x, float y);
bool IsLesserThanOrEqual(float x, float y);

#endif

