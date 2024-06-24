#include <iostream>
#include <vector>
#include <string>
#include <fstream>

using namespace std;

vector<string> tokenise(string csvLine, char seperator)
{
    vector<string> tokens;

    signed int start, end;
    string token = "";

    start = csvLine.find_first_not_of(seperator, 0);

    do
    {
        end = csvLine.find_first_of(seperator, start);
        if (start == csvLine.length() || start == end)
        {
            break;
        }
        else if (end >= 0)
        {
            token = csvLine.substr(start, end - start);
        }
        else
        {
            token = csvLine.substr(start, csvLine.length() - start);
        }
        tokens.push_back(token);
        start = end + 1;
    } while (end > 0);

    return tokens;
}

int main()
{
    ifstream csvFile{"test.csv"};
    string line;
    vector<string> tokens;

    if (csvFile.is_open())
    {
        cout << "File opened" << endl;

        while (getline(csvFile, line))
        {
            cout << "Read Line: " << line << "\t\tTokenised: ";
            tokens = tokenise(line, ',');
            if (tokens.size() != 5)
            {
                cout << "Bad Line" << endl;
                continue;
            }

            try
            {
                double price = stod(tokens[3]);
                double amount = stod(tokens[4]);

                cout << price << " : " << amount << endl;
            }
            catch (const std::exception &e)
            {
                cout << e.what() << endl;
                cout << "Bad Line" << endl;
                break;
            }
        }

        csvFile.close();
    }
    else
    {
        cout << "File not opened" << endl;
        return 1;
    }

    return 0;
}
