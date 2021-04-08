#include "GradientDescent.h"
#include <time.h>

GradientDescent::GradientDescent(int ite){
    srand(time(NULL));
    m_curr = (double (rand()%100)) / 100.0;
    b_curr = (double (rand()%100)) / 100.0;
    rss = 0.0;
    tss = 0.0;
    learning_rate = 0.0001;
    iterations = ite;
}

void GradientDescent::fit(vector<double> x, vector<double> y){
    int tam_x = x.size();
    int tam_y = y.size();

    if (tam_x != tam_y){
        cout<<"Vectors X and Y has different size"<<endl;
        exit(0);
    }

    n = tam_x;

    this->x = &x[0];
    this->y = &y[0];

    train();
}

double GradientDescent::sumatory(double *a){
    double sum = 0.0;
    for(int i=0; i<n; i++)
        sum += a[i];
    return sum;
}

double* GradientDescent::multiply(double* a, double* b){
    double *mul = new double[n];
    for(int i=0; i<n; i++)
        mul[i] = a[i] * b[i];
    return mul;
}

double* GradientDescent::multiply(double* a, double b){
    double *mul = new double[n];
    for(int i=0; i<n; i++)
        mul[i] = a[i] * b;
    return mul;
}

double* GradientDescent::add(double* a, double* b){
    double *add = new double[n];
    for(int i=0; i<n; i++)
        add[i] = a[i] + b[i];
    return add;
}

double* GradientDescent::add(double* a, double b){
    double *add = new double[n];
    for(int i=0; i<n; i++)
        add[i] = a[i] + b;
    return add;
}

double* GradientDescent::computed_y_pred(){
    double *y_pred = new double[n];
    for(int i=0; i<n; i++)
        y_pred[i] = (m_curr * x[i]) + b_curr;
    return y_pred;
}

double* GradientDescent::compute_residual(double* y_hat){
    double* res = new double[n];
    for(int i=0; i<n; i++)
        res[i] = y[i] - y_hat[i];
    return res;
}

void GradientDescent::train(){
    double md = 0.0, bd = 0.0;
    for(int i=0; i<iterations; i++){
        double *y_pred = computed_y_pred();
        double *resi = compute_residual(y_pred);
        md = -(2.0 / (double) n) * sumatory(multiply(x, resi));
        bd = -(2.0 / (double) n) * sumatory(resi);

        m_curr = m_curr - learning_rate * md;
        b_curr = b_curr - learning_rate * bd;

        // printf("Iteration: %5d;  m = %lf;  b = %lf\n", i+1, m_curr, b_curr);
    }
}

void GradientDescent::predict(double x){
    printf("[%lf]\n", m_curr * x + b_curr);
}

void GradientDescent::predict(vector<double> x){
    cout<<"[";
    for(double xc : x){
        printf("%lf, ", m_curr * xc + b_curr);
    }
    cout<<"]"<<endl;
}