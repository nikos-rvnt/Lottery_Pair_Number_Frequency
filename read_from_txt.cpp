
#include <iostream>
#include <stdexcept>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>

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


void find_freqs( vector<vector<int>>& vecIn, vector<vector<int>>& vecFreqs){

	for(int j=1; j<46; j++){
		for(int i=1; i<46; i++){
			for(int z=0; z<vecIn.size(); z++){
			//for(int z=0; z<vecIn.size(); z++){
				if((find(vecIn[z].begin(), vecIn[z].end(), i) != vecIn[z].end()) && (find(vecIn[z].begin(), vecIn[z].end(), j) != vecIn[z].end())){
					vecFreqs[j-1][i-1] += 1;
				}
			}
		}
	}
}


void freq_to_txt(vector<vector<int>>& vecOut){

    string txt_output_file = "tzoker_pair_frequencies_output.txt";
    ofstream outFile(txt_output_file, ofstream::out);

    if (outFile.is_open()){
    	for(int j=0; j<vecOut.size(); ++j){
	    	for(int i=0; i<vecOut[j].size(); ++i){
    			outFile << "f(" << to_string(j+1) << "," << to_string(i+1) << ") = " << vecOut[j][i] << endl; 
    		}
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

    // 2d vector to store frequencies of each pair among 1-45
    vector<vector<int>> freqs(45, vector<int>(45));

    // find frequencies of each pair
    find_freqs(data_in,freqs);

    // write to txt
    freq_to_txt(freqs);


	return 0;

}

