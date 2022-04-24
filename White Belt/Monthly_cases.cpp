#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <sstream>



std::vector<std::string> Split(std::string line) {

    std::string word;
    std::istringstream iss(line, std::istringstream::in);
    std::vector<std::string> wordsVector;
    while (iss >> word)
    {
        wordsVector.push_back(word);
    }

    return wordsVector;
}



void ADD(std::vector<std::string>& q, int day, std::string plans) {
    // std::cout << q.size() << std::endl;
    if (plans != "0") {

        if (q[day] == "0") {
            q[day] = plans;
        }
        else {
            int i = 0;
            for (auto c : Split(q[day])) {
                if (c == plans) {
                    i++;
                }
            }
            if (i == 0) {
                q[day] += ' ';
                q[day] += plans;
            }
        }
    }
    //std::cout << q[day] << std::endl;
}


void DUMP(const std::vector<std::string>& q, int day) {
    if (q[day] == "0") {
        std::cout << q[day] << std::endl;
    }
    else {
        int i = 1;
        for (auto a : q[day]) {
            if (a == ' ')
                i++;
        }
        std::cout << i << ' ' << q[day] << std::endl;
    }
}

void NEXT(std::vector<std::string>& q, const std::vector<int>& month, int& count) {
    if (count == 11) {

        count = 0;

    }
    else {
        if (month[count] < month[count + 1]) {

            q.resize(month[count + 1] + 1, "0");
            //std::cout << q.size();
        }
        else if (month[count] > month[count + 1]) {

            int a = month[count] - month[count + 1];
            int i = 0;
            while (i != a) {
                ADD(q, month[count + 1], q[month[count] - i]);
                i++;
            }

            q.resize(month[count + 1] + 1);
            //std::cout << q.size();
        }
        count++;
    }
}

int main() {

    int n;
    std::cin >> n;
    std::vector<std::string> q(32, "0");
    std::vector<int> month = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
    int count = 0;
    for (int i = 0; i < n; ++i) {

        std::string word;
        std::cin >> word;
        if (word == "NEXT") {

            NEXT(q, month, count);
        }
        else {

            if (word == "DUMP") {
                int day;
                std::cin >> day;
                DUMP(q, day);
            }
            else {

                if (word == "ADD") {

                    int day;
                    std::string plans;
                    std::cin >> day >> plans;
                    ADD(q, day, plans);

                }
            }
        }
    }
