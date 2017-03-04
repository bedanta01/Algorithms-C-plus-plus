#include <iostream>
using namespace std;


int current_max,maximum_sum;
int curr_up,curr_down;
int max_up,max_down,max_left,max_right;
int array[100];

int kaden_algo(int n){
    int start=0;
    int end=0;
    int curr_max=0;
    int max_sum=0;
    int i=0;
    while(i<n){
        if((curr_max+array[i])<0){
            curr_max=0;
            i++;
            start=i;
        }
        else{
            curr_max=curr_max+array[i];
            i++;
            
        }
        if(max_sum<curr_max){
            max_sum=curr_max;
            end=i-1;
        }
    }
    curr_up=start;
    curr_down=end;
    //cout<<start<<' '<<end<<endl;
    return max_sum;
    
}

void max_rectangle(int arr[][5],int row,int col){
    int l=0;
    while(l<col){
        for(int p=0;p<row;p++){
            array[p]=0;
        }
        for(int i=0;i<row;i++){
            array[i]=arr[i][l];
        }
        int r=l;
        while(r<col){
            
            current_max = kaden_algo(row);
            
            if(maximum_sum<current_max){
                maximum_sum=current_max;
                max_up = curr_up;
                max_down = curr_down;
                max_left=l;
                max_right=r;
            }
            
            r++;
            
            for(int j=0;j<row;j++){
                array[j] = array[j]+arr[j][r];
            }
            
        }
        
        l++;
    }
}



int main() {
	int input[4][5] = {{ 2,  1, -3, -4,  5},
                       { 0,  6,  3,  4,  1},
                       { 3, -2, -1,  4, -5},
                       {-3,  3,  1,  0,  3}};
                       
    max_rectangle(input,4,5);
    cout<<maximum_sum<<endl;
    cout<<max_up<<" "<<max_down<<" "<<max_left<<" "<<max_right;
	return 0;
}