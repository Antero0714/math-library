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
    if ((b > 0 && a + b > INT_MAX) || (b < 0 && a + b < INT_MIN))
    {
        return OVERFLOW;
    }

    result = a + b;
    return SUCCESS;
}

inline int substract(int a, int b, int &result)
{
    if ((b > 0 && a - b < INT_MAX) || (b < 0 && a - b > INT_MAX))
    {
        return OVERFLOW;
    }

    result = a - b;
    return SUCCESS;
}

inline int multiply(int a, int b, int &result)
{
    if (a > 0 && b > 0 && a * b > INT_MAX)
    {
        return OVERFLOW;
    }

    if (a < 0 && b < 0 && a * b > INT_MAX)
    {
        return OVERFLOW;
    }

    if (a > 0 && b < 0 && a * b > INT_MIN)
    {
        return OVERFLOW;
    }

    if (a < 0 && b > 0 && a * b > INT_MIN)
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
        int status = multiply(number, number, value);

        if (status != SUCCESS)
        {
            return status;
        }
    }

    result = value;
    return SUCCESS;
}

inline int factorial(int number, int &result)
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
    int status = factorial(number - 1, previous);

    if (status != SUCCESS)
    {
        return status;
    }

    return multiply(number, previous, result);
}
} // namespace calc_math

#endif
