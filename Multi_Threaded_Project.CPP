#include<iostream>
#include <bits/stdc++.h>
#include<pthread.h>
#include<stdio.h>
#include<cmath>
using namespace std;
 /*AS = Array Summation, AM = Array Multiplication, AB = Array Subtraction */
int A1[10],A2[10],AS[10],AM[10],AB[10],Mn=0,Mx=0;
void* Multi(void*arg) {

   for(int i=0; i<10; i++){
    AM[i]=A1[i]*A2[i];
   }
   return NULL;
}
void* Summation(void*arg) {

   for(int i=0; i<10; i++){
    AS[i]=A1[i]+A2[i];
   }
   return NULL;
}
void* Subtraction(void*arg) {

   for(int i=0; i<10; i++){
    AB[i]=A1[i]-A2[i];
   }
   return NULL;
}
void* Min(void* arg) {
    int min1= A1[0],min2 = A2[0];
    for(int r=0; r<10; r++) {
    if(A1[r]<min1)
    min1 = A1[r];
    }
    for(int r=0; r<10; r++) {
    if(A2[r]<min2)
    min2 = A2[r];
    }
    if(min1<min2)
    Mn=min1;
    else
    Mn = min2;
    return NULL;
}
void* Max(void* arg) {
    int max1= A1[0],max2 = A2[0];
    for(int r=0; r<10; r++) {
    if(A1[r]>max1)
    max1 = A1[r];
    }
    for(int r=0; r<10; r++) {
    if(A2[r]>max2)
    max2 = A2[r];
    }
    if(max1>max2)
    Mx=max1;
    else
    Mx = max2;
    return NULL;
}
void* Print(void* arg) {

   cout << endl
         << " Multiplication of 1 and 2 : " << endl;
         for(int q =0; q<10; q++)
         cout << AM[q] << " ";
         cout <<endl;
     cout << endl
         << " Summation of 1 and 2 : " << endl;
         for(int d =0; d<10; d++)
         cout << AS[d] << " ";
         cout <<endl;

           cout << endl
         << " Subtraction of 1 and 2 : " << endl;
         for(int k =0; k<10; k++)
         cout << AB[k] << " ";
         cout <<endl;
         cout << endl
         << "The minimun number : " << endl;
         cout << Mn << endl;
          cout << endl
         << "The maximum number : " << endl;
         cout << Mx << endl;

         return NULL;
}
int main() {
    cout << " Enter Array 1 : " << endl;
    for (int i = 0; i < 10; i++) {
           cin>> A1[i];
        }
    cout << " Enter Array 2 : " << endl;
    for (int i = 0; i < 10; i++) {
           cin>> A2[i];
        }
        cout << endl;
   cout << " Array 1 : " << endl;
   for(int y=0; y<10; y++) 
       cout << A1[y] << " ";
   cout << endl;
cout << endl;

 cout << " Array 2 : " << endl;
for(int y=0; y<10; y++) 
       cout << A2[y] << " ";
   cout << endl;

    pthread_t T1,T2,T3,T4,T5, T6;
    pthread_create(&T1, NULL, Multi, NULL);
    pthread_create(&T2, NULL, Summation, NULL);
    pthread_create(&T3, NULL, Subtraction, NULL);
    pthread_create(&T4, NULL, Min, NULL);
    pthread_create(&T5, NULL, Max, NULL);
    pthread_create(&T6, NULL, Print, NULL);
    pthread_join(T3,NULL);
    pthread_join(T2,NULL); 
    pthread_join(T1,NULL);
    pthread_join(T5,NULL);
    pthread_join(T4,NULL);
    pthread_join(T6,NULL);

   

    return 0;
} 
