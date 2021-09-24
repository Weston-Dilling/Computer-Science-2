#include <iostream>
#include <string>
#include <fstream>
#include <vector>
using namespace std;


struct pal_canidate
{
    string word_A;
    string word_B;
    int swaps;
};

vector<pal_canidate> read_file(ifstream &);
pal_canidate process_words(string, string);
void sort_vect(vector<pal_canidate>&);

int main (int argc, char *argv[])
{
    if (argc != 2)
    {
        cout << "incorrect number of arguments" << endl;
        cout << "example use ./program pals.txt" << endl;

        return 1;
    }

    ifstream fin;
    // parse args to load file with fin
    fin.open( argv[1] );
    if ( !fin )
    { 
        cout << "File failed to open." << endl;
    }

    // don't touch any further
    vector<pal_canidate> canidate_list = read_file(fin);
    sort_vect(canidate_list);

    //display top 5 pals
    for (int i = 0; i < 5; i++)
    {
        cout << canidate_list[i].word_A;
        cout << " and " << canidate_list[i].word_B;
        cout << " can be made pals from " << canidate_list[i].swaps;
        cout << " swaps" << endl << endl;
    }

    return 0;
}

// takes in canidate words and returns pal_canidate struct
// should count # of ways word_A and word_B are "pals" 
// from deff of project 1
pal_canidate process_words(string word_A, string word_B) 
{
    pal_canidate return_canidate;

    return_canidate.swaps = 0; 
    
    string original_A = word_A;
    for ( int i = 0; i < word_A.length(); ++i )
    {
        for ( int j = i; j < word_A.length(); ++j )
        {
            if (j != i)
            {
                swap(word_A[i], word_A[j]);
                if ( word_A == word_B )  
                    return_canidate.swaps++; 
                word_A = original_A;
            }
        }    
    } 
    return_canidate.word_A = word_A; 
    return_canidate.word_B = word_B;
    return return_canidate;  
}

// read in pairs and find matches return vector 
// should call "process_words" to build vector
// vectors can be added to with method .push_back 
vector<pal_canidate> read_file(ifstream &fin)
{
    vector<pal_canidate> return_list;
    string word_A, word_B;
    pal_canidate dummy_struct; 

    // idea 3 Cody: "You may want or need to create struct instances as you read in the file to add to the vector"
    while ( fin >> word_A >> word_B )
    {   
        dummy_struct = process_words( word_A, word_B );
        return_list.push_back( dummy_struct ); 
    }

    return return_list; //return_list is a vector that contains pal_canidate structs (that contain word_A, word_B, and swaps)
}

// implement selection sort (not bubble sort) to sort canidate list
// should sort the list from most matches to fewest
void sort_vect(vector<pal_canidate> &canidate_list)
{   
    int startScan, minIndex;
    pal_canidate maxValue;
    
    for ( int startScan = 0; startScan < ( canidate_list.size() - 1 ) ; ++startScan )
    {
        minIndex = startScan;
        maxValue = canidate_list[startScan];
        for ( int index = startScan + 1; index < canidate_list.size(); ++index )
        {
            if ( canidate_list[index].swaps > maxValue.swaps )
            { 
                maxValue = canidate_list[index];
                minIndex = index;
            }
        } 
        canidate_list[minIndex] = canidate_list[startScan];
        canidate_list[startScan] = maxValue; 
    } 
} //remember I need to compare the int swaps number that's in each struct in this vector