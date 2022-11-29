
#include <iostream>
#include <stdexcept>
#include <fstream>
#include <vector>
#include <string>

using namespace std;


auto read_stream( istream& inf, vector<vector<int>>& data){   

	bool ended = false;
	int num1, num2, num3, num4, num5;
	vector<int> row(5,0);
	while(!ended){

	    for (int i = 0; ended && i < 5; i++){
	        ended = !(inf >> row[i]);
	    }
		data.push_back(row);
	}

}


void read_data_from_txt(ifstream& inf, vector<vector<int>>& vecIn)
{
    int numRows = vecIn.size();
    for (int row = 0; row < numRows; ++row){
        for (int col = 0; col < 5; ++col){
            inf >> vecIn[row][col];
        }
    }
}

void print_them(vector<vector<int>>& vecIn)
{
	int numRows = vecIn.size();
    for (int i = 0; i < numRows; ++i){
        for (int j = 0; j < 5; ++j){
            cout << "  " << vecIn[i][j];
        }
        cout << endl;
    }
}

void freq_to_txt(vector<vector<int>>& vecOut){

    string txt_output_file = "tzoker_pair_frequencies_output.txt";
    ofstream outFile(txt_output_file, ofstream::out);

    if (outFile.is_open()){
    	for(int i=0; i<vecOut.size(); ++i){
    		outFile << "f(1,2)=" << vecOut[i][0] << endl; 
    	}
    	outFile.close();
	}
	else cout << "Unable to open file";

}

int main(){

	// 2d vector to contain rows and columns of txt
    int num_rows = 150;
    int num_cols = 5;
    vector<vector<int>> data_in(num_rows, vector<int>(num_cols));
    
    // read data from txt file
    string txt_input_file = "tzoker_data_quintuples.txt";
	ifstream inputFile(txt_input_file);        
    read_data_from_txt( inputFile, data_in);

    // print data
    print_them( data_in);

    // write to txt
    freq_to_txt(data_in);


	return 0;

}

