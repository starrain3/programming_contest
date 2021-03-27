#include <iostream>
#include <vector>
using namespace std;

int main(){
	int counter = -1;
	vector<string> output;
	cin>>counter;
	while(counter!=0){
		int x, y;
		cin>>x>>y;

		for(int i=0; i<counter; ++i){
			int x1, y1;
			cin>>x1>>y1;

			if(x1 - x>0 && y1 - y>0){
				//division 1
				output.push_back("NE");
			}
			else if(x1 - x<0 && y1 - y>0){
				output.push_back("NO");
			}
			else if(x1 - x<0 && y1 - y<0){
				output.push_back("SO");
			}
			else if(x1 - x>0 && y1 - y<0){
				output.push_back("SE");
			}
			else{
				output.push_back("divisa");
			}
		}
		cin>>counter;
	}
	for(int i=0; i<output.size(); ++i){
		cout<<output[i]<<"\n";
	}
	return 0;
} 
