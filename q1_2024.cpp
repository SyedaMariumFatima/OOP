#include <iostream>
#include<cmath>
using namespace std;
class financialStatistics{
    public:
    static double calculateMean(double arr[], int n){
        if(n==0) return 0;
        double mean=0;
        for(int i=0; i<n; i++){
            mean+=arr[i];
        }
        mean/=n;
        return mean;
    }
    static double getVariance(double arr[], int n){
        if(n<=1) return 0;
        double m=calculateMean(arr, n);
        double v=0;
        for(int i=0; i<n; i++){
            v+=pow(arr[i]-m,2);
        }
        v/=(n-1);
        return v;
    }
};
int main() {
  double arr[]={2.54, 6.50, 2.00, 97.08, 6.50, 3.20};
  int n=sizeof(arr)/sizeof(arr[0]);
  double v=financialStatistics::getVariance(arr, n);
  cout<<v;

    return 0;
}
