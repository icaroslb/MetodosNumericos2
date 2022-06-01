#include <iostream>
#include <cmath>

#define N  3

using namespace std;

double dot(double *a, double *b)
{
    double dp = 0.0;
    
    for (int i =0; i < N; i++)
    {
        dp = dp + a[i]*b[i];
    }
    return dp;
}

double norm(double *a)
{
    return (sqrt(dot(a,a)));
}

void normalize(double *a, double *an)
{
    double l = norm(a);
    for (int i =0; i < N; i++)
    {
        an[i] = a[i]/l;
    }
    
}

void matrixVec(double m[][N], double *a, double *b)
{
    double s;
    
    for(int i=0; i <N; i++)
    {
        s = 0.0;
        for(int k=0; k < N; k++)
        {
            s = s + m[i][k]*a[k];
        }
        b[i] = s;
    }
}

void regularPowerMethod (double M[][N], double vNonNormalized[], double tolerance, double vNormalized[], double *eigenValue)
{
    double  lambdaOld, lambdaNew, error;
    
    lambdaNew = 0.0;
    
    do
    {
        lambdaOld = lambdaNew;
        
        normalize(vNonNormalized,vNormalized);
    
        matrixVec(M, vNormalized, vNonNormalized);
        
        lambdaNew = dot(vNormalized, vNonNormalized);
        
        error     = abs((lambdaNew - lambdaOld)/lambdaNew);
        
    } while (error > tolerance);
    
    normalize(vNonNormalized,vNormalized);
    
    *eigenValue = lambdaNew;

}
    

void printVec(double *a)
{
    double s;
    
    for(int i=0; i <N; i++)
    {
        cout << a[i] << " " ;
    }
    cout << endl;
}


int main()
{
    double M[N][N] ={{4,2,1}, {2, 5, 3}, {1, 3, 3}};
    double v0[N]   = {1,1,1}, eigenVector[N], eigenValue;
    
    double tolerance = 0.000001;
 
    regularPowerMethod(M,v0, tolerance, eigenVector, &eigenValue);
     
    cout << "Dominant eigenvalue = " << eigenValue << endl;
    cout << "Dominant eigenvector = {" << endl;
    cout << "   ";
    printVec (eigenVector);
    cout << "}" << endl;

    return 0;
}
