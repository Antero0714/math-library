#ifndef CALC_MATH_H
#define CALC_MATH_H

#include <limits.h>

namespace calc_math
{
const int SUCCESS = 0;
const int OVERFLOW = 1;
const int DIVISION_BY_ZERO = 2;
const int NEGATIVE_ARGUMENT = 3;

inline int add(int a, int b, int &result)
{
    if ((b > 0 && a > INT_MAX - b) || (b < 0 && a < INT_MIN - b))
    {
        return OVERFLOW;
    }

    result = a + b;
    return SUCCESS;
}

inline int substract(int a, int b, int &result)
{
    if ((b > 0 && a < INT_MIN + b) || (b < 0 && a > INT_MAX + b))
    {
        return OVERFLOW;
    }

    result = a - b;
    return SUCCESS;
}

inline int multiply(int a, int b, int &result)
{
    if (a > 0 && b > 0 && a > INT_MAX / b)
    {
        return OVERFLOW;
    }

    if (a < 0 && b < 0 && a < INT_MAX / b)
    {
        return OVERFLOW;
    }

    if (a > 0 && b < 0 && b < INT_MAX / a)
    {
        return OVERFLOW;
    }

    if (a < 0 && b > 0 && a < INT_MIN / b)
    {
        return OVERFLOW;
    }

    result = a * b;
    return SUCCESS;
}

inline int divide(int a, int b, int &result)
{
    if (b == 0)
    {
        return DIVISION_BY_ZERO;
    }
    if (a == INT_MIN && b == -1)
    {
        return OVERFLOW;
    }

    result = a / b;
    return SUCCESS;
}

inline int power(int number, int exponent, int &result)
{
    if (exponent < 0)
    {
        return NEGATIVE_ARGUMENT;
    }

    if (number == 1 || exponent == 0)
    {
        result = 1;
        return SUCCESS;
    }
    if (number == 0)
    {
        result = 0;
        return SUCCESS;
    }

    int value = 1;

    for (int i = 0; i < exponent; ++i)
    {
        int status = multiply(value, number, value);

        if (status != SUCCESS)
        {
            return status;
        }
    }

    result = value;
    return SUCCESS;
}

inline int factorial(int number, int number_2, int &result)
{
    if (number < 0)
    {
        return NEGATIVE_ARGUMENT;
    }

    if (number <= 1)
    {
        result = 1;
        return SUCCESS;
    }

    int previous = 0;
    int status = factorial(number - 1, 0, previous);

    if (status != SUCCESS)
    {
        return status;
    }

    return multiply(number, previous, result);
}

} // namespace calc_math

#endif
