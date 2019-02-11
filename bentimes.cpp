#include <iostream>
#include <string>
#include <ctime>

#define SRAND srand(static_cast<unsigned int>(time(nullptr)));
using std::cout, std::string;
int hours, minutes;
bool pm;

string ones[] = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
string tens[] = {"zero", "ten", "twenty", "thirty", "forty", "fifty", "sixty"};
string specialCases[] = {"ten", "eleven", "twelve", "thirteen", "fourteen", "fifteen", "sixteen", "seventeen",
                         "eighteen", "nineteen"};


enum class Relative {
    TO = 0, PAST,

    END
};

enum class Interval {
    FIVE = 0, TEN, QUARTER, TWENTY, TWENTY_FIVE, HALF,

    END
};


void getTime(int &hours_o, int &minutes_o, bool &pm_o) {
    std::time_t t = std::time(0);   // get time now
    std::tm* now = std::localtime(&t);
    hours_o = now->tm_hour;
    minutes_o = now->tm_min;
    if (hours_o > 12) {
        hours_o -= 12;
        pm_o = true;
    }
    return;
}

Interval getInterval() {
    SRAND
    auto interval = (Interval) (rand() % (int) Interval::END);
    return interval;
}

Relative getRel() {
    SRAND
    auto rel = (Relative) (rand() % (int) Relative::END);
    return rel;
}


string getWords(int num) {
    int dig1{num % 10};
    int dig10{((num - dig1) % 100) / 10};
    string out{""};
    switch (num) {
        case 10:
            return specialCases[0];
        case 11 :
            return specialCases[1];
        case 12 :
            return specialCases[2];
        case 13 :
            return specialCases[3];
        case 14 :
            return specialCases[4];
        case 15 :
            return specialCases[5];
        case 16 :
            return specialCases[6];
        case 17 :
            return specialCases[7];
        case 18 :
            return specialCases[8];
        case 19 :
            return specialCases[9];
        default:
            break;
    }
    switch (dig10) {
        case 0:
            return ones[dig1];
        case 2:
            out = tens[2];
            break;
        case 3:
            out = tens[3];
            break;
        case 4:
            out = tens[4];
            break;
        case 5:
            out = tens[5];
            break;
        case 6:
            out = tens[6];
            break;

        default:
            break;
    }
    if (dig1 == 0) {
        return out;
    } else {
        return out + "-" + ones[dig1];
    }
}

string getTimeWords() {
    switch (minutes) {
        case 1:
            return ones[1] + " past " + getWords(hours);
        case 2:
            return ones[2] + " past " + getWords(hours);
        case 3:
            return ones[3] + " past " + getWords(hours);
        case 4:
            return ones[4] + " past " + getWords(hours);
        case 5:
            return ones[5] + " past " + getWords(hours);
        case 6:
            return ones[6] + " past " + getWords(hours);
        case 7:
            return ones[7] + " past " + getWords(hours);
        case 8:
            return ones[8] + " past " + getWords(hours);
        case 9:
            return ones[9] + " past " + getWords(hours);
        case 10:
            return "ten past " + getWords(hours);
        default:
            break;
    }
    return getWords(hours) + " " + getWords(minutes);
}


string to(Interval interval) {
    string o{"It is "};
    switch (interval) {
        case Interval::FIVE:
            if (minutes + 5 >= 60) {
                hours++;
                minutes -= 60;
            }
            minutes += 5;
            return o + getWords(5) + " to " + getTimeWords();
        case Interval::TEN:
            if (minutes + 10 >= 60) {
                hours++;
                minutes -= 60;
            }
            minutes += 10;
            return o + getWords(10) + " to " + getTimeWords();
        case Interval::QUARTER:
            if (minutes + 15 >= 60) {
                hours++;
                minutes -= 60;
            }
            minutes += 15;
            return o + "quarter to " + getTimeWords();

        case Interval::TWENTY:
            if (minutes + 20 >= 60) {
                hours++;
                minutes -= 60;
            }
            minutes += 20;
            return o + getWords(20) + " to " + getTimeWords();
        case Interval::TWENTY_FIVE:
            if (minutes + 25 >= 60) {
                hours++;
                minutes -= 60;
            }
            minutes += 25;
            return o + getWords(25) + " to " + getTimeWords();
        case Interval::HALF:
            if (minutes + 30 >= 60) {
                hours++;
                minutes -= 60;
            }
            minutes += 30;
            return o + "half to " + getTimeWords();
        default:
            return "Well done you broke it";
    }
}


string past(Interval interval) {
    string o{"It is "};
    switch (interval) {
        case Interval::FIVE:
            if (minutes - 5 < 0) {
                hours--;
                minutes += 60;
            }
            minutes -= 5;
            return o + getWords(5) + " past " + getTimeWords();
        case Interval::TEN:
            if (minutes - 10 < 0) {
                hours--;
                minutes += 60;
            }
            minutes -= 10;
            return o + getWords(10) + " past " + getTimeWords();
        case Interval::QUARTER:
            if (minutes - 15 <= 60) {
                hours--;
                minutes += 60;
            }
            minutes -= 15;
            return o + "quarter past " + getTimeWords();

        case Interval::TWENTY:
            if (minutes - 20 < 0) {
                hours--;
                minutes += 60;
            }
            minutes -= 20;
            return o + getWords(20) + " past " + getTimeWords();
        case Interval::TWENTY_FIVE:
            if (minutes - 25 < 0) {
                hours--;
                minutes += 60;
            }
            minutes -= 25;
            return o + getWords(25) + " past " + getTimeWords();
        case Interval::HALF:
            if (minutes - 30 < 0) {
                hours--;
                minutes += 60;
            }
            minutes -= 30;
            return o + "half past " + getTimeWords();
        default:
            return "Well done you broke it";
    }

}

int main() {
    Relative r{getRel()};
    Interval interval{getInterval()};
    string out{""};
    getTime(hours, minutes, pm);

    switch (r) {
        case Relative::TO :
            out = to(interval);
            break;
        case Relative::PAST :
            out = past(interval);
            break;
        default:
            break;
    }
    cout << out << std::endl;
}