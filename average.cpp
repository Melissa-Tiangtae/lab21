#include<iostream>
#include<cstdlib>

using namespace std;

int main(int argc, char *argv[]){
    
    double sum = 0.0;
    double ans;
   

    if(argc == 1){
        cout << "Please input numbers to find average.";
    }else{

      for(int i =1; i<argc; i++){
        sum += atof(argv[i]);
      }

      ans = (sum/(argc-1.0));

    cout << "---------------------------------" << "\n";
    cout << "Average of "<< argc-1 <<" numbers = " << ans << "\n";
    cout << "---------------------------------";
    
    }


    return 0;
}
