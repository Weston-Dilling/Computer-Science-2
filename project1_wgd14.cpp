#include <iostream>
#include <string>

using namespace std;

bool string_pals(string, string);

// don't touch
int main ()
{
    string A;
    string B;
    char user_input = 'n';
    do
    {
        cout << "input string A: ";
        cin >> A;
        cout << "input string B: ";
        cin >> B;

        string outcome = string_pals(A, B) ? "pals":"not pals";
        cout << "A and B are " << outcome << endl;

        cout << "continue?(y/n): ";
        cin >> user_input;
    } while (user_input == 'y' || user_input == 'Y');

    cout << "\n\nGoodbye!";
}

// finish me
bool string_pals(string A, string B)
{
    string original_A = A;
    for ( int i = 0; i < A.length(); ++i )
        for ( int j = 0; j < A.length(); ++j )
            if (j != i)
            {
                swap(A[i], A[j]);
                if ( A == B )
                    return true;
                A = original_A;
            }
    return false;
}
