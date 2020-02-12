#include <iostream>
#include <string>
#include <cctype>
#include <iomanip>
#include <map>
using namespace std;

int main()
{
	map<char, int> charMap; 
        map<char, int>::iterator charIter; 
        
	map<string, int> wordMap; 
        map<string, int>::iterator wordIter; 
        
	map<string, int> numMap; 
	map<string, int>::iterator numIter; 
		
	map<string, int> word_insertion_order; 
        map<string, int>::iterator word_tracker; 
        
	map<string, int> num_insertion_order; 	
	map<string, int>::iterator num_tracker; 

	// the top 10 used types;
        const int num_of_top = 10;	
	string s, s1;
	       
	int track_word = 0;
	int track_num = 0;
	
	char c = cin.peek(); // take a look but not read in the next char;
	while( !cin.eof() )
	{
		if( isalpha( c ) )
		{
			s = "";	// initialize string s to be blank;
			while( isalpha( c ) )
			{
				cin.get( c ); // get this char in;
				++charMap[c];
				// increment counter if 'c' exists, or a create new pair if not;
				char temp = tolower( c );
			
				s = s + temp;
				// add/attach lower-case 'c' to string s as long as reading in char;
				c = cin.peek();
				// continue or stop reading, depending on 'c';
			}
			word_tracker = wordMap.find( s );	//searching for the word s in mapWord;
			if( word_tracker == wordMap.end() )
			// only if this word does not exist, then do increment int track_word;
				word_insertion_order[s] = track_word++;

			++wordMap[s];
                        // increment counter or create new pair;				
		}
		// end of alphabetic case;
		else if( isdigit( c ) )
		{
			s1 = ""; // initialize number string s1 to be blank;
			while( isdigit( c ) )
			{
				cin.get( c ); // get this number in;
				++charMap[c];
				// even a digit is still a char;
				s1 = s1 + c;
				c = cin.peek();
			}
			num_tracker = numMap.find( s1 );       //searching for the number s1 in mapNum;
                        if( num_tracker == numMap.end() )
                        // only if this word does not exist, then do increment int track_num;
                                num_insertion_order[s1] = track_num++;

			++numMap[s1];
		}
		// end of digit case;
		else
		// this case includes all chars that are neither digit nor alphabet;
		{
			cin.get( c );
			++charMap[c];
			c = cin.peek();
		}
		// end of other char case;
	}
	// end of while loop that was designed for filling info in the 'map' container;

	
        // This section prints the 'Char' counts
		
	int char_size = charMap.size();	// the size of char container;
	int c_loopsize = ( num_of_top <= char_size ? num_of_top : char_size );
	cout << "Total " << char_size << " different characters, " << c_loopsize << " most used characters:\n";
	for( int i = 1; i < c_loopsize + 1; i++ )
	{
		if( charMap.empty() )
		// in case that all elements in map were eased;
			break;

		char most_char = 0; // tracks the currently most-used char;
        	int c_times = 0; // stores the times of being used;
		for( charIter = charMap.begin(); charIter != charMap.end(); ++charIter )
		{
			if( ( charIter->second > c_times ) || ( ( charIter->second == c_times ) && ( static_cast<int>(charIter->first) < static_cast<int>(most_char) ) ) )
			{
				most_char = charIter->first;
				c_times = charIter->second;
			}
			
		}

		charMap.erase( most_char );
		// exclude the current most used char;
		cout << "No. " << i - 1 << ": ";
		if( most_char == '\t' )
			cout << setw(17) << left << "\\t" << c_times << endl;
		else if( most_char == '\n' )
			cout << setw(17) << left << "\\n"<< c_times << endl;
		else
			cout << setw(17) << left << most_char << c_times << endl;
	}

        // This section prints the 'Word' counts
        
	int word_size = wordMap.size(); // the size of words container;
	int w_loopsize = ( num_of_top <= word_size ? num_of_top : word_size );
        cout << "\nTotal " << word_size << " different words, " << w_loopsize << " most used words:\n";
        for( int i = 1; i < w_loopsize + 1; i++ )
        {
                if( wordMap.empty() )
			break;

		string most_word = ""; // tracks the currently most-used string;
                int w_times = 0; // stores the times of being used;
                for( wordIter = wordMap.begin(); wordIter != wordMap.end(); ++wordIter )
                {
			if( ( wordIter->second > w_times ) || ( ( wordIter->second == w_times ) && ( word_insertion_order[wordIter->first] < word_insertion_order[most_word] ) ) )
			// the rule is, only if the latter one occurs more times, or, the latter one occurs the same times but earlier, can the latter one replace most_word;
                        {
                                most_word = wordIter->first;
                                w_times = wordIter->second;
                        }
		}

		wordMap.erase( most_word );
		// exclude the current most used word;
		cout << "No. " << i - 1 << ": " << setw(17) << left << most_word << w_times << endl;
	}

        // This section prints the 'Num' counts
        
	int num_size = numMap.size(); // the size of numbers container;
        int n_loopsize = ( num_of_top <= num_size ? num_of_top : num_size );
        cout << "\nTotal " << num_size << " different numbers, " << n_loopsize << " most used numbers:\n";
        for( int i = 1; i < n_loopsize + 1; i++ )
        {
                if( numMap.empty() )
                        break;

                string most_num = ""; // tracks the currently most-used number;
                int n_times = 0; // stores the times of being used;
                for( numIter = numMap.begin(); numIter != numMap.end(); ++numIter )
                {
                        if( ( numIter->second > n_times ) || ( ( numIter->second == n_times ) && ( num_insertion_order[numIter->first] < num_insertion_order[most_num] ) ) )
			// same rule happens here;
                        {
                                most_num = numIter->first;
                                n_times = numIter->second;
                        }
                }

                numMap.erase( most_num );
                // exclude the current most used number;
                cout << "No. " << i - 1 << ": " << setw(17) << left << most_num << n_times << endl;
        }

	return 0;
}