#ifndef RIEMANN_H_
#define RIEMANN_H_
#include <vector>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>

using namespace std;

class GradientDescent{
    private:
        int n, iterations;
        double *x, *y;
        double m_curr, b_curr;
        double rss, tss;
        double learning_rate;
        double* multiply(double*, double*);
        double* multiply(double*, double);
        double* add(double*, double*);
        double* add(double*, double);
        double* compute_residual(double*);
        double compute_rss();
        double compute_tss();
        double* computed_y_pred();
        double sumatory(double*);
        void train();
    public:
        GradientDescent(int);
        void fit(vector<double>, vector<double>);
        double predict(double x[]);
        void print_array();
        double getIntercept();
        double getCoeficient();
        double getR2();
};

#endif