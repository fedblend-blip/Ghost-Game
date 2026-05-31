#include <iostream>
#include <thread>
#include <chrono>
using namespace std;
template <typename T>
void print(T format, bool isEndl = true) {
    if (isEndl) {
        cout << format << endl;
    }
    else if (!isEndl) {
        cout << format;
    }
}
void endl() {
    cout << endl;
}

int main() {
    print("===Добро пожалывать в игру Ghosts-Doors===");
    print("Сыграем? yes/no: ", false);
    string command;
    int score = 0;
    cin >> command;
    if (command != "yes" && command == "no") {
        print("Выход", false);
        for (int i = 0; i <= 10; i++) {
            this_thread::sleep_for(chrono::seconds(1));
            print(".", false);
        }
        endl();
        return 0;
    }
    bool isLoop = true;
    while (isLoop) {
        srand(time(NULL));
        int randDoor = 1 + rand() % 3;
        print("Вы пришли в старый дом в силе.\nВы по какойто причине захотели зайти в него.\nВы зашли и перед вами три старых двери.");
        print("Выберете дверь и если там приведение...");
        int door;
        print("Ваш выбор: ", false);
        cin >> door;
        print("Проверяем -[", false);
        for (int i = 1; i <= 3; i++) {
            this_thread::sleep_for(chrono::seconds(2));
            print("#", false);
        }
        print("]-");
        this_thread::sleep_for(chrono::seconds(2));
        if (door == randDoor) {
            print("Ой-Преведение беги пожалуйста");
            score -= 10;
            print("ваши очки: ", false);
            print(score);
            if (score < 0) {
                break;
            }
        }
        else {
            print("Вау вы везуньчик вот вам 10 очков");
            endl();
            score += 10;
            print("Ваши очки: ", false);
            print(score);

        }
    }
    print("Ой очки это ваши жизни вы их потеряли!  :(");

    return 0;
}
