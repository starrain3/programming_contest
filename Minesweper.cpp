#include <iostream>
//#include <cstdlib>
#include <vector>
#include <sstream>

using namespace std;
int main()
{	
//	int * output;
	vector <int> output;
	int output_size=0;
	int pre_size = 0;
	int counter =1;

//	output = (int*) malloc(sizeof(int)*1);
	while(true){
		int input1, input2; 
		cin>>input1>>input2;
		if(input1==0){
			break;	
		}
		char map[input1][input2];
		int map_answer[input1][input2];
		for(int i=0; i<input1; ++i){
			for(int j=0; j<input2; ++j){
				cin>>map[i][j];
				map_answer[i][j]=0;
			}
		}
		
		
		for(int i=0; i<input1; ++i){
			for(int j=0; j<input2; ++j){
				if(map[i][j]=='*'){
					for(int k=i-1; k<=i+1; ++k){
						for(int l = j-1; l<=j+1; ++l){
							if(0<=k&&k<input1&&0<=l&&l<input2){
								map_answer[k][l]++;
							}
						}
					}
				}	
			}
		}
		
		pre_size = output_size;
		output_size += input1*input2+2;
//		output = (int*) realloc(output, sizeof(int)*output_size);
		
//		output[pre_size] = input1;
//		output[pre_size+1] = input2;
		output.push_back(input1);
		output.push_back(input2);
		
//		int counter_1 = 0;
		for(int i=0; i<input1; ++i){
			for(int j=0; j<input2; ++j){
				if(map[i][j]!='*'){
					output.push_back(map_answer[i][j]);
//					output[pre_size+2+counter_1] = map_answer[i][j];
				}
				else{
					output.push_back(-1);
//					output[pre_size+2+counter_1] = -1;
				}
//				counter_1++;
			}
		}
		counter++;
	}

	pre_size =0;
	for(int i=1; i<counter; ++i){
		cout<<"Field #"<<i<<":"<<"\n";
		int col = output[pre_size], row =output[pre_size+1];
		int pos =0;
		for(int j=0; j<col; ++j){
			for(int k=0; k<row; ++k){
				if(output[pre_size+2+pos]==-1){
					cout<<"*";
				}
				else{
					cout<<output[pre_size+2+pos];
				}
				pos++;
			}
			cout<<"\n";
		}
		cout<<"\n";
		pre_size = pre_size+col*row+2;
	}
	
	

return 0;
}
