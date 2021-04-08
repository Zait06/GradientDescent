#include <vector>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include "GradientDescent/GradientDescent.h"

using namespace std;

int main(int argc, char *argv[]){

    if(argc != 2){
        cout<<"Te faltan las iteraciones"<<endl;
        cout<<argv[0]<<" ite"<<endl;
        exit(0);
    }

    double a[] = {1.0, 2.0, 3.0, 4.0, 5.0};
    double b[] = {6.0, 7.0, 8.0, 9.0, 10.0};

    vector<double> va(a, a + sizeof(a) / sizeof(double));
    vector<double> vb(b, b + sizeof(b) / sizeof(double));

    GradientDescent gd(atoi(argv[1]));
    gd.fit(va,vb);


    cout<<"Prediccion 1:"<<endl;
    gd.predict(1.5);

    cout<<"\nPrediccion 2:"<<endl;
    double c[] = {0.5, 1.5, 1.7};
    vector<double> vc(c, c + sizeof(c) / sizeof(double));
    gd.predict(vc);

    cout<<"Fin del programa"<<endl;
    return 0;
}
