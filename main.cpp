
#include <iostream>
#include <stdexcept>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;


// read input data from file
void read_data_from_txt(ifstream& inputf, vector<vector<int>>& vecIn)
{
    int numRows = vecIn.size();
    for (int row = 0; row < numRows; ++row){
        for (int col = 0; col < 5; ++col){
            inputf >> vecIn[row][col];
        }
    }
}

// print input data just to see its content
void print_them(vector<vector<int>>& vecIn)
{
	int numRows = vecIn.size();
    for (int i = 0; i < numRows; ++i){
		for (vector<int>::iterator it = vecIn[i].begin() ; it != vecIn[i].end(); ++it)
		    cout << " " << *it;
		cout << endl;
    }
}

// find frequencies of each pair number from 1 to 45
void find_freqs( vector<vector<int>>& vecIn, vector<vector<int>>& vecFreqs){
	
	for(int j=1; j<46; j++){
		// to optimize the code do not search for numbers where i>=j because if i==j no quintuple contains 2 same numbers
		// and if i>j then it is the same as searching for j>i. If i>=j was not excluded vecFreqs would be a symmetric matrix
		for(int i=1; i<j; ++i){
			// check every quintuple
			for(int z=0; z<vecIn.size(); ++z){
				// check if both i and j are contained in the current quintuple
				if((find(vecIn[z].begin(), vecIn[z].end(), i) != vecIn[z].end()) && (find(vecIn[z].begin(), vecIn[z].end(), j) != vecIn[z].end())){
					vecFreqs[j-1][i-1] += 1;
					// for (vector<int>::iterator it = vecIn[z].begin() ; it != vecIn[z].end(); ++it)
					//     cout << " " << *it;
					// cout << endl;
				}
			}
		}
	}
}

// save frequencies of each numbers pair to a txt file 
void freq_to_txt(vector<vector<int>>& vecOut){

    string txt_output_file = "tzoker_2021_pair_frequencies_output.txt";
    ofstream outFile(txt_output_file, ofstream::out);

    if (outFile.is_open()){
    	for(int j=0; j<vecOut.size(); ++j){
	    	for(int i=0; i<j; ++i)
	    		// write each number pair frequency in the form of f(number1,number2) = frequency
    			outFile << "f(" << to_string(j+1) << "," << to_string(i+1) << ") = " << vecOut[j][i] << endl; 	
    	}
    	outFile.close();
	}
	else cout << "Unable to open file";

}


int main(){

	// 2d vector to contain rows and columns of txt data
	// 156 tzoker results of 2021 and 5 numbers drawn each time
    int num_rows = 156;
    int num_cols = 5;
    vector<vector<int>> data_in(num_rows, vector<int>(num_cols));
    
    // read data from txt file
    string txt_input_file = "tzoker_2021_drawn_results_quintuples.txt";
	ifstream inputFile(txt_input_file);        
    read_data_from_txt( inputFile, data_in);

    // print input data
    print_them( data_in);

    // 2d vector to store frequencies of each pair among 1-45
    vector<vector<int>> freqs(45, vector<int>(45));

    // find frequencies of each pair
    find_freqs(data_in,freqs);

    // write to txt
    freq_to_txt(freqs);


	return 0;

}

