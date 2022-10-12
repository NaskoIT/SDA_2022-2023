#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct DateTime {
    int identifier;
    int year;
    int month;
    int day;
    int hour;
    int minutes;
    int seconds;
};

vector<string> splitString(string &str, string &delimiter) {
    int position = 0;
    vector<string> tokens;
    while (position != string::npos) {
        position = str.find(delimiter);
        string part = str.substr(0, position);
        tokens.push_back(part);
        str.erase(0, position + delimiter.length());
    }

    return tokens;
}

vector<int> parseToNumbers(vector<string> &tokens) {
    vector<int> numbers;
    for (string &token : tokens) {
        numbers.push_back(stoi(token));
    }

    return numbers;
}

//22:44:05 11.04.2021
DateTime parseDateTime(string &date, string &time, int identifier) {
    string timeDelimiter = ":";
    vector<string> timeParts = splitString(time, timeDelimiter);
    vector<int> parsedTimeParts = parseToNumbers(timeParts);

    string dateDelimiter = ".";
    vector<string> dateParts = splitString(date, dateDelimiter);
    vector<int> parsedDateParts = parseToNumbers(dateParts);

    DateTime parsedDateTime;
    parsedDateTime.day = parsedDateParts[0];
    parsedDateTime.month = parsedDateParts[1];
    parsedDateTime.year = parsedDateParts[2];
    parsedDateTime.hour = parsedTimeParts[0];
    parsedDateTime.minutes = parsedTimeParts[1];
    parsedDateTime.seconds = parsedTimeParts[2];
    parsedDateTime.identifier = identifier;

    return parsedDateTime;
}

bool comparator(const DateTime &first, const DateTime &second) {
    if (first.year == second.year) {
        if (first.month == second.month) {
            if (first.day == second.day) {
                if (first.hour == second.hour) {
                    if (first.minutes == second.minutes) {
                        if (first.seconds == second.seconds) {
                            return first.identifier < second.identifier;
                        }

                        return first.seconds < second.seconds;
                    }

                    return first.minutes < second.minutes;
                }

                return first.hour < second.hour;
            }

            return first.day < second.day;
        }

        return first.month < second.month;
    }

    return first.year < second.year;
}

int main() {
    int n;
    cin >> n;

    vector<DateTime> dates;
    for (int i = 0; i < n; ++i) {
        string time;
        cin >> time;
        string date;
        cin >> date;
        DateTime currentDate = parseDateTime(date, time, i + 1);
        dates.push_back(currentDate);
    }

    sort(dates.begin(), dates.end(), comparator);

    for (DateTime &dateTime : dates) {
        cout << dateTime.identifier << endl;
    }
}