double myPolyGrad3(double x){

    double a0 = 0;
    double a1 = 0;
    double a2 = 1;
    double a3 = 0;

    return a3*x*x*x+a2*x*x+a1*x+a0;

}

double numDiffGrad1(double(*FCN)(double),double x){

    double dx = 1e-8;

    return (FCN(x+dx)-FCN(x))/dx;


}