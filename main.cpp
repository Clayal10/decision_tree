#include<iostream>
#include<fstream>
#include<vector>
#include<map>
#include<sstream>
#include<string>

using namespace std;
/*1. Create 2d Vector for the input data, key is first column, data is a vector of strings of all the other columns*/
void init_data_set(string file_name, vector<vector<string>> *data_set);

int main(){
	vector<vector<string>> training_data;
    	init_data_set("TrainingData.csv", &training_data);
  	

   	return 0;
}

void init_data_set(string file_name, vector<vector<string>> *data_set) {
    ifstream fp;
    fp.open(file_name);
    if(!fp){
        cout << "Error opening file!\n\n";
        exit(-1);
    }
    //we are just saving everything as a string, if needed to be changed do that down the road
    string buffer;
    string char_buffer;
    getline(fp, buffer);//first line is garbage
    /*ID starts at 1, first character is T for training, E for testing. going to remove*/
    string id;
    vector<string> row;
    while(getline(fp, buffer, '\n')){
        buffer.erase(buffer.end()-1, buffer.end());//erases \n
        stringstream s(buffer);
	getline(s, id, ',');
	id.erase(id.begin());
	row.push_back(id);
        while(getline(s, char_buffer, ',')){
            //now at each 'word' after id
            row.push_back(char_buffer);
        }
        data_set->push_back(row);
        row.clear();
    }
}
