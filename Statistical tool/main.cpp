// FCI – Programming 1 – 2018 - Assignment 3
// Program Name: statisticcalTools.cpp
// Last Modification Date:  5/4/2018
// Author1 and ID and Group:hussein hossam idris, 20170352, G13
// Author1 and ID and Group:omar ashraf labib,    20170363, G14
// Author1 and ID and Group:nada samir salama,    20170355, G13
// Purpose: the user enters data and then the program does statistical analysis and calculations on them.
#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>
#include <string>
#include <valarray>

using namespace std;
    float quar1=0;
    float quar2=0;
    float quar3=0;
    float mean_value = 0;
    float undersquar = 0;
    vector<float>x_pair;
    vector<float>y_pair;
    int arraysize = 0;
    float b1 = 0;
    float b0 = 0;
float enterData(vector<float> arr,string fileName,int x){

    fstream file(fileName.c_str(),ios::out);
    if(!file){
        cout<<"error file didn't open"<<endl;
    }else{
        for(int i=0;i<=arr.capacity()-1;i++){
            file<<arr[i]<<" ";
        }
    }
    file.close();
    }


//used to get a arrays from a file!!
float loadData(string str1,vector<float>& arr2){
    ifstream filein(str1.c_str());
    float x;
    if(filein.is_open()){
            while(filein>>x){
                arr2.push_back(x);
            }
            filein.close();
    }
    return 0;
}


//for displaying data
void displayData(string fileName){
    float getContent;
    fstream filein(fileName.c_str(),ios::in);
    if(filein.is_open()){
        cout<<"your content is  :  "<<endl;
        if(filein.is_open()){
            while(filein>>getContent){
                cout<<getContent<<endl;}
        }
    }

}

void quartiles(string str1,float& quar1,float& quar2,float& quar3){
    vector<float>array2;
    float z;
    fstream pls(str1.c_str(),ios::in);
    while(pls>>z){
        array2.push_back(z);
    }
    int eodF = 0;
    int eodS = 0;
    sort(array2.begin(),array2.end());
    vector<float>firstHalf;
    vector<float>secondHalf;
    int evenOROdd = 0;
    for(int i = 0;i<array2.size();i++){evenOROdd++;}
    if(evenOROdd%2==0){
        float n1,n2;
        n1=(array2.size()/2)-1;
        n2=((array2.size()+2)/2)-1;
        quar2=(array2[n1]+array2[n2])/2;
        for(int i =0 ;i<array2.size()/2;i++){
            firstHalf.push_back(array2[i]);
            eodF++;
        }
        for(int i =0 ;i<array2.size();i++){
            if(i>=(array2.size()/2)-1){
                secondHalf.push_back(array2[i]);
                eodS++;
            }
        }
        if(eodF%2==0){
            float n3,n4,n5,n6;
            n3=(firstHalf.size()/2)-1;
            n4=((firstHalf.size()+2)/2)-1;
            quar1=(firstHalf[n3]+firstHalf[n4])/2;
            n5=(secondHalf.size()/2)-1;
            n6=((secondHalf.size()+2)/2)-1;
            quar3=(secondHalf[n5]+secondHalf[n6])/2;
            cout<<"Q1 is :  "<<quar1<<endl;
            cout<<"Q2 is :  "<<quar2<<endl;
            cout<<"Q3 is :  "<<quar3<<endl;
        }
        else{
            quar1=firstHalf[((firstHalf.size()+1)/2)-1];
            quar3=secondHalf[((secondHalf.size()+1)/2)];
            cout<<"Q1 is :  "<<quar1<<endl;
            cout<<"Q2 is :  "<<quar2<<endl;
            cout<<"Q3 is :  "<<quar3<<endl;
        }


    }
    else{
            quar2=array2[((array2.size()+1)/2)-1];
            for(int i = 0 ;i<(array2.size()+1)/2;i++){
                firstHalf.push_back(array2[i]);
            }
            for(int i =0; i<array2.size();i++){
                if(i>(array2.size())/2){
                    secondHalf.push_back(array2[i]);
                }
            }
            int n7,n8,n9,n10;
            n7=(firstHalf.size()/2)-1;
            n8=(((firstHalf.size()+2)/2)-1);
            quar1=(firstHalf[n7]+firstHalf[n8])/2;
            n9=(secondHalf.size()/2)-1;
            n10=((secondHalf.size()+2)/2)-1;
            quar3=(secondHalf[n9]+secondHalf[n10])/2;
            cout<<"Q1 is :  "<<quar1<<endl;
            cout<<"Q2 is :  "<<quar2<<endl;
            cout<<"Q3 is :  "<<quar3<<endl;

    }


}
float IQR(float quar1,float quar2,float quar3){
    float IQR ;
    IQR = quar3-quar1;
    return IQR;
}
void CorrelationCoefficient(){
    float r;
    float arraySize,enterNumber;
    float sumX=0;
    float sumY=0;
    float sumXY=0;
    float sumXP2=0;
    float sumYP2=0;
    vector<float>X;
    vector<float>Y;
    cout<<"enter the size of the 2 arrays of values : "<<endl;
    cin>>arraySize;
    cout<<"enter the elements of the first array : "<<endl;
    for(int i=0;i<arraySize;i++){
        cin>>enterNumber;
        X.push_back(enterNumber);
    }
    cout<<"enter elements of the second array : "<<endl;
    for(int i=0;i<arraySize;i++){
        cin>>enterNumber;
        Y.push_back(enterNumber);
    }
    for(int i = 0;i<arraySize;i++){
        sumXP2=sumXP2+(pow(X[i],2));
        sumX+=X[i];
    }//cout<<"Sum of x =  "<<sumX<<endl;
     //cout<<"Sum of x^2 = "<<sumXP2<<endl;
    for(int i =0;i<arraySize;i++){
        sumYP2=sumYP2+(pow(Y[i],2));
        sumY+=Y[i];
    }//cout<<"Sum of y = "<<sumY<<endl;
     //cout<<"Sum of y^2 = "<<sumXP2<<endl;
    for(int i = 0;i<arraySize;i++){
        sumXY=sumXY+(Y[i]*X[i]);
    }//cout<<"Sum of xy = "<<sumXY<<endl;
    float lowerside = ((arraySize*sumXP2)-(pow(sumX,2)))*((arraySize*sumYP2)-(pow(sumY,2)));
    r =(((arraySize*sumXY)-(sumX*sumY))/sqrt(lowerside));
    cout<<"the Correlation Coefficient is :  "<<r<<endl;
}

void meanAndStandardDeviation(string filename,float& undersquar, float&mean_value){
    float sumP2 = 0;
    float sum   = 0;
    float size  = 0;
    vector<float>mean;
    float read;
    ifstream file(filename.c_str());
    while(file>>read){
        mean.push_back(read);
    }
    for(int i =0;i<mean.size();i++){
        sum=sum+mean[i];
    }
    for (int i = 0;i<mean.size();i++){
        sumP2 = sumP2 + pow(mean[i], 2);
        size++;
    }
    mean_value=sum/mean.size();
    cout<<"the mean value is :  "<<mean_value<<endl;
    undersquar =sqrt((1/(size-1))*(sumP2-(pow(sum,2)/size)));
    cout<<"standard deviation is :  "<<undersquar<<endl;
}
void RelativeStandard(float undersquar,float mean_value){
    float relative= 100*(undersquar/mean_value);
    cout<<"the relative standard deviation is :  "<<relative<<"%"<<endl;
}
void mode(string filename){
    ifstream file(filename.c_str());
    vector<float>mode;
    float nadawyasmen;
    while(file>>nadawyasmen){
        mode.push_back(nadawyasmen);
    }
    sort(mode.begin(),mode.end());
    float number1 = 0;
    float counter = 0;
    float mode_value1;
    for(int i=0;i<mode.size();i++){
        if(mode[i]==mode[i+1]){
            counter++;
            if(counter>number1){
               number1=counter;
               mode_value1=mode[i];
               }
        }else{
            counter=0;
        }
    }
    cout<<"mode is : "<<mode_value1<<endl;
}
void regression_coefficients(vector<float>&x,vector<float>&y,int&arraysize,float& b1,float& b0){


//     float arraysize;
     float put_content;
     float sum_x = 0;
     float sum_y = 0;
     float sum_xy = 0;
     float sum_xP2 = 0;
     float upper_b1;
     float lower_b1;
     //float b1;
     float left_b0;
     float right_b0;
    // float b0;

//     vector<float>x;
  //   vector<float>y;

     cout << "Please, Enter the size of the two arrays: ";
     cin >> arraysize;
     cout << endl;

     cout << "Please, Enter the contents of the two arrays: " << endl;

     for(int i = 0; i < arraysize; i++){
        cin >> put_content;
        x_pair.push_back(put_content);
     }
     cout << "The values of x is: "<<endl;
     for (int i=0;i<x_pair.size();i++){
        cout << x_pair[i] << " ";
        }
    cout<<endl;
    cout<<"Enter the values of y"<<endl;
     for (int i = 0; i < arraysize; i++){
        cin >> put_content;
        y_pair.push_back(put_content);
     }
    cout << "The values of y is: ";
     for (int i = 0;i<y_pair.size();i++){
        cout << y[i] << " ";

        }

     for (int i = 0; i < arraysize; i++){
        sum_x = sum_x + x[i];
     }

     for (int i = 0; i < arraysize; i++){
        sum_y = sum_y + y_pair[i];
     }

     for (int i = 0; i < arraysize; i++){
        sum_xy = sum_xy + (x_pair[i] * y_pair[i]);
     }

     for (int i = 0; i < arraysize; i++){
        sum_xP2 = sum_xP2 + pow(x_pair[i], 2);
     }

     upper_b1 = ((arraysize * sum_xy) - (sum_x * sum_y));
     lower_b1 = ((arraysize * sum_xP2) - pow(sum_x, 2));


     b1 = (upper_b1 / lower_b1);
     cout << endl;
     cout << endl;

     cout << "The value of b1 is: " << b1 << endl;


     left_b0 = (sum_y / arraysize);
     right_b0 = (sum_x / arraysize);


     b0 = (left_b0) - (b1 * right_b0);

     cout << "The value of b0 is: " << b0 << endl;


     cout << "The equation of linear regression coefficients is: " << "\n" << "y = "<< b0 << "+" << b1 << "x" << endl;
     cout << endl;



     cout << endl;





}
double CalculateMedian (string strl){
    vector<float>array2;
    float o;
    fstream omar (strl.c_str(),ios::in);
    while (omar>>o){
        array2.push_back(o);
    }
    cout<<"The Value of median is :  "<<endl;
    size_t Size = array2.size();
    if (Size == 0){
        return 0;
    }else if (Size == 1){;
        return array2[0];
    }else {
        sort(array2.begin(),array2.end());
        if (Size % 2 == 0){
        return (array2[(Size / 2) - 1] + array2[((Size + 2) / 2)-1]) / 2;
        }else{
        return array2[((Size + 1) / 2)-1];

        }

    }




}

void meanSquareError(vector<float>x_pair, vector<float>y_pair, int arraysize){
     float y_prime;
     float y_subtract;
     float Esquare;
     float Add_errors;
     float MSE;


     vector<float>y_estimated;
     vector<float>y_subtracted;
     vector<float>Error_square;
      for (int i = 0; i < x_pair.size(); i++){
        y_prime = (x_pair[i] * b1) + b0;
        y_estimated.push_back(y_prime);

     }
     cout << "The values of estimated y is: " << endl;
     for (float item : y_estimated)
        cout << item << " ";
        cout << endl;
        cout << endl;
    for (int i = 0; i < y_pair.size(); i++){
        y_subtract = y_pair[i] - y_estimated[i];
        y_subtracted.push_back(y_subtract);
    }
    cout << "The values of y subtracted is: " << endl;

    for (float item : y_subtracted)
        cout << item << " ";
        cout << endl;
        cout << endl;
    for (int i = 0; i < y_subtracted.size(); i++){
        Esquare = pow(y_subtracted[i], 2);
        Error_square.push_back(Esquare);
    }
    cout << "The values of errors after squaring is: " << endl;

     for (float item : Error_square)
        cout << item << " ";
        cout << endl;
        cout << endl;
    for (int i = 0; i < Error_square.size(); i++){
        Add_errors += Error_square[i];
    }
     cout << "The sum of errors after squaring is: " << Add_errors << endl;


     MSE = Add_errors / arraysize;

     cout << "The mean square error of the linear regression is: " << MSE << endl;

     cout << "AND WE ARE FINISH" << endl;
     cout << "AND WE ARE TRUE" << endl;
}


//main function
int main()
{
    string filename;
    while(true){
    int x;
    vector<float>array2;
    int choice;
    cout<<"press 1 to enter data \n";
    cout<<"press 2 to load data to a file \n";
    cout<<"press 3 to display loaded data \n";
    cout<<"press 4 to get the quartiles   \n";
    cout<<"press 5 to get the inter quartile range \n";
    cout<<"press 6 to find the Correlation Coefficient \n";
    cout<<"press 7 to get the median of the data \n";
    cout<<"press 8 to get the linear regression coefficient \n";
    cout<<"press 9 to get the MSE \n";
    cout<<"press 10 to find mean and standard deviation \n";
    cout<<"press 11 to get relative standard deviation \n";
    cout<<"press 12 to get the mode of the data \n";
    cout<<"press 13 to close the program \n";

    cin>>choice;
    //Put data in a file.
    if(choice == 1){
        float y;
        cout<<"enter size of array"<<endl;
        cin>>x;
        cout<<"enter elements of array"<<endl;
        vector<float>array1;
        for(int i =0; i<x;i++){
            cin>>y;
            array1.push_back(y);
        }
        //string fileName;
        cout<<"enter file name"<<endl;
        cin>>filename;
        enterData(array1,filename,x);
    }
    else if(choice==2){
        //string fileName2;
        cout<<"Please enter the name of the file"<<endl;
        cin>>filename;
        loadData(filename,array2);
        //for(int i=0;i<array2.size();i++){cout<<array2[i]<<endl;}
    }
    else if(choice == 3){
        cout<<"enter name of file : "<<endl;
        displayData(filename);
    }
    else if(choice==4){
        quartiles(filename,quar1,quar2,quar3);
    }
    else if(choice==5){

        cout<<"the value of IQR :"<<IQR(quar1,quar2,quar3)<<endl;

    }
    else if(choice==6){
        CorrelationCoefficient();
    }
    else if(choice==7){
        cout<<CalculateMedian(filename)<<endl;

    }
    else if (choice==8){
        regression_coefficients(x_pair,y_pair,arraysize,b1,b0);
    }
    else if(choice==9){
        meanSquareError(x_pair, y_pair,arraysize);

    }
    else if(choice==10){
        meanAndStandardDeviation(filename,undersquar,mean_value);
    }
    else if (choice == 11){
        RelativeStandard(undersquar,mean_value);
    }
    else if (choice==12){
        mode(filename);
    }else if (choice==13){
        cout << "Shokrn,,,T3ala kol youm" << endl;
        return 0;
    }
    }
}


//used for entering data!!!

