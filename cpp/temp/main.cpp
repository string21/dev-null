#include <iostream>
#include <limits>

void error(std::string e);
void expect(bool acceptable, std::string e);
void get_day_value_pair(std::vector<std::string>& days,  std::vector<int>& values);

// since pair, struct or class have not been covered yet
// ill try to solve this using pass by reference (technically, also has not been covered yet but i kind of understand it)

std::vector<int> processDay(int& error_count, std::vector<std::string> days,  std::vector<int> values, std::vector<std::string> mon_strings) {
    std::vector<int> vals {};
    for (int i = 0; i < days.size(); ++i) {
        bool isFound = false;
        for (int j = 0; j < mon_strings.size(); ++j) {
            if (days[i] == mon_strings[j]) {
                vals.push_back(values[i]);
                isFound = true;
                break;
            }
        }
        if (!isFound) {
            ++error_count;
        }
    }

    std::cout << "vals size before return is " << vals.size() << "\n";
    std::cout << "error count is " << error_count << "\n";

    return vals;
}

int main() {

    int error_count {};
    std::vector<std::string> days {};
    std::vector<int> values {};
    get_day_value_pair(days, values); // pass by reference for now instead of "returning a pair" methods!!!

    std::vector<int> mondays {};
    std::vector<std::string> mon_strings { "Monday", "monday", "mon", "Mon"};

    std::vector<int> tuesdays {};
    std::vector<std::string> tue_strings { "Tuesday", "tuesday", "tue", "Tue" };

    std::vector<int> wednesdays {};
    std::vector<std::string> wed_strings { "Wednesday", "wednesday", "wed", "Wed" };

    std::vector<int> thursdays {};
    std::vector<std::string> thu_strings { "Thursday", "thursday", "thu", "Thu" };

    std::vector<int> fridays {};
    std::vector<std::string> fri_strings { "Friday", "friday", "fri", "Fri" };

    std::vector<int> saturdays {};
    std::vector<std::string> sat_strings { "Saturday", "saturday", "sat", "Sat" };

    std::vector<int> sundays {};
    std::vector<std::string> sun_strings { "Sunday", "sunday", "sun", "Sun" };

    std::vector<std::vector<std::string>> day_vectors {};
    day_vectors.push_back(mon_strings);
    day_vectors.push_back(tue_strings);
    day_vectors.push_back(wed_strings);
    day_vectors.push_back(thu_strings);
    day_vectors.push_back(fri_strings);
    day_vectors.push_back(sat_strings);
    day_vectors.push_back(sun_strings);

    for (int i = 0; i < days.size(); ++i) {
        bool isFound = false;
        for (int j = 0; j < day_vectors.size(); ++j) {
            for (int k = 0; k < day_vectors[j].size(); ++k) {
                if (j == 0 && days[i] == day_vectors[j][k]) { // monday
                    mondays.push_back(values[i]);
                    isFound = true;
                    break;
                }
                if (j == 1 && days[i] == day_vectors[j][k]) { // tuesday
                    tuesdays.push_back(values[i]);
                    isFound = true;
                    break;
                }
                if (j == 2 && days[i] == day_vectors[j][k]) {
                    wednesdays.push_back(values[i]);
                    isFound = true;
                    break;
                }
                if (j == 3 && days[i] == day_vectors[j][k]) {
                    thursdays.push_back(values[i]);
                    isFound = true;
                    break;
                }
                if (j == 4 && days[i] == day_vectors[j][k]) {
                    fridays.push_back(values[i]);
                    isFound = true;
                    break;
                }
                if (j == 5 && days[i] == day_vectors[j][k]) {
                    saturdays.push_back(values[i]);
                    isFound = true;
                    break;
                }
                if (j == 6 && days[i] == day_vectors[j][k]) {
                    sundays.push_back(values[i]);
                    isFound = true;
                    break;
                }
            }
            if (isFound) break;
        }
        if (!isFound) ++error_count;
    }

    std::cout << "monday values:  ";
    if (mondays.size() > 0) {
        int sum {};
        for (int x : mondays) {
            std::cout << x << "  ";
            sum+=x;
        }
        std::cout << "\nTotal is:  " << sum << "\n";
    }
    std::cout << "tuesday values:  ";
    if (tuesdays.size() > 0) {
        int sum {};
        for (int x : tuesdays) {
            std::cout << x << "  ";
            sum+=x;
        }
        std::cout << "\nTotal is:  " << sum << "\n";
    }
    std::cout << "wednesday values:  ";
    if (wednesdays.size() > 0) {
        int sum {};
        for (int x : wednesdays) {
            std::cout << x << "  ";
            sum+=x;
        }
        std::cout << "\nTotal is:  " << sum << "\n";
    }
    std::cout << "thursday values:  ";
    if (thursdays.size() > 0) {
        int sum {};
        for (int x : thursdays) {
            std::cout << x << "  ";
            sum+=x;
        }
        std::cout << "\nTotal is:  " << sum << "\n";
    }
    std::cout << "friday values:  ";
    if (fridays.size() > 0) {
        int sum {};
        for (int x : fridays) {
            std::cout << x << "  ";
            sum+=x;
        }
        std::cout << "\nTotal is:  " << sum << "\n";
    }
    std::cout << "saturday values:  ";
    if (saturdays.size() > 0) {
        int sum {};
        for (int x : saturdays) {
            std::cout << x << "  ";
            sum+=x;
        }
        std::cout << "\nTotal is:  " << sum << "\n";
    }
    std::cout << "sunday values:  ";
    if (sundays.size() > 0) {
        int sum {};
        for (int x : sundays) {
            std::cout << x << "  ";
            sum+=x;
        }
        std::cout << "\nTotal is:  " << sum << "\n";
    }



    std::cout << "total error count is " << error_count;

}

void get_day_value_pair(std::vector<std::string>& days,  std::vector<int>& values) {
    while (true) {
        try {
            std::cout << "Enter day-value pair (e.g. Monday 32) or 'stop 0' to stop:  ";
            std::string temp_day {};
            int temp_value {};
            std::cin >> temp_day >> temp_value;
            expect(std::cin.good(), "failed cin operation, enter day-value pair");
            if (temp_day == "stop" && temp_value == 0) {
                break;
            } else {
                days.push_back(temp_day);
                values.push_back(temp_value);
            }
        } catch (std::runtime_error& e) {
            std::cout << "------------->> ERROR: " << e.what() << "\n";
            // resolve failed cin buffer for the next iteration's cin operation:
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
    }
}

void error(std::string e) {
    throw std::runtime_error {e};
}

void expect(bool acceptable, std::string e) {
    if (!acceptable) error(e);
}