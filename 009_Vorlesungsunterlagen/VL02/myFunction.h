#ifndef MYFUNCTION_H_
#define MYFUNCTION_H_
/** 
    \FUNCTION: myPolyGrad3
 
    \AUTHOR: jannik wiessler

    \DATE: 2020-05-14

    \DESCRIPTION: implementation of f(x) = x^2 
 
    \param[in]  double x: value x to eval function at    

    \param[out] square of input x
*/
double myPolyGrad3(double);

/** 
    \FUNCTION: numDiffGrad1
 
    \AUTHOR: jannik wiessler

    \DATE: 2020-05-14

    \DESCRIPTION: First-order implementation of numerical apporximation of the derivative for any given function
 
    \param[in]  double(*FCN)(double): pointer to function to calculate the derivative  
                
                double x: value x to eval derivative at    

    \param[out] square of input x
*/
double numDiffGrad1(double(*)(double),double);
#endif MYFUNCTION_H_
