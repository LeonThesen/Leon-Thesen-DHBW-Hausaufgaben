#ifndef HA05_RHSLIB_H_
#define HA05_RHSLIB_H_
/** 
    \FUNCTION: RHS_MSD
 
    \AUTHOR: jannik wiessler

    \DATE: 2020-06-06

    \DESCRIPTION: calcs the right-hand-side (RHS) of mass-spring-damper (MSD) sytsem
 
    \param[in]  current state vector
                stroage for resulting rhs [out]             
*/
void RHS_MSD(double*, double*);

/** 
    \FUNCTION: myRHS_Ball
 
    \AUTHOR: jannik wiessler

    \DATE: 2020-06-06

    \DESCRIPTION: calcs the right-hand-side (RHS) of bouncing ball
 
    \param[in]  current state vector
                stroage for resulting rhs [out]             
*/
void myRHS_Ball(double*, double*);
#endif