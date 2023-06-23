#include <iostream>
 
// chatGPT's stupid function.
double log(int x)
{
    double result = 0;
    while (x > 1) 
    {
        result += log(x / 2);
        x /= 2;
    }
    return result;
}

// ln.c
//
// simple, fast, accurate natural log approximation
// when without <math.h>

// featuring * floating point bit level hacking,
//           * x=m*2^p => ln(x)=ln(m)+ln(2)p,
//           * Remez algorithm

// by Lingdong Huang, 2020. Public domain.

// ============================================

float ln(float x) {
  unsigned int bx = * (unsigned int *) (&x);
  unsigned int ex = bx >> 23;
  signed int t = (signed int)ex-(signed int)127;
  unsigned int s = (t < 0) ? (-t) : t;
  bx = 1065353216 | (bx & 8388607);
  x = * (float *) (&bx);
  return -1.49278+(2.11263+(-0.729104+0.10969*x)*x)*x+0.6931471806*t;
}
// done.

int main()
{
    float num;
    std::cout << "Enter a number: ";
    std::cin >> num;
    
    double result = ln(num);
    std::cout << "The natural log of " << num << " is " << result << std::endl;
    
    return 0;
}