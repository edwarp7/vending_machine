// vendingMachine.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <ctime>
using namespace std;

time_t timer = time(NULL);
struct tm* t = localtime(&timer);

class MoneyFileModifier {
public:
    MoneyFileModifier(const string& filename) : filename(filename) {}

    bool appendText() {
        ifstream file(filename);
        if (!file.is_open()) {
            cout << "error" << endl;
            return false;
        }
        while (getline(file, str)) {
            stringstream ss(str);
            string s;
            int i = 0;
            while (ss>>s) {
                token[i] = stoi(s);
                i++;
            }
            
        }
        cout << token[0] << token[1] << token[2] << token[3] << endl;
        file.close();
    }

    int getToken(int i) {
        return token[i];
    }

    bool clearText() {
        std::ofstream file(filename, std::ios::trunc);
        if (!file.is_open()) {
            cout << "error" << endl;
            return false;
        }
        file.close();
        return true;
    }

    bool putText(int i[4]) {
        ofstream file(filename);
        if (!file.is_open()) {
            cout << "error" << endl;
            return false;
        }
        file << to_string(i[0]) << "\t" << to_string(i[1]) << "\t" << to_string(i[2]) << "\t" << to_string(i[3]) << "\t";
    }
private:
    int token[4] = {};
    string filename;
    string line;
    string str;
};

class salesFileModifier {
public:
    salesFileModifier(const string& filename) : filename(filename) {}

    bool month(int i) {
        ifstream file(filename);
        if (!file.is_open()) {
            cout << "error" << endl;
            return false;
        }
        while (getline(file, str)) {
            stringstream ss(str);
            string s;
            int j = 0;
            while (ss >> s) {
                token[j] = stoi(s);
                j++;
            }
            if (token[0] == i) {
                if (token[2] == 1) {
                    cout << "coke" << endl;
                }
                else if (token[2] == 2) {
                    cout << "cider" << endl;
                }
                else if (token[2] == 3) {
                    cout << "milk" << endl;
                }
                else
                    cout << "energydrink" << endl;
            }

        }
        file.close();
    }

    bool putText(int i) {
        ofstream file(filename);
        if (!file.is_open()) {
            cout << "error" << endl;
            return false;
        }
        file << t->tm_mon + 1 << "\t" << t->tm_mday << "\t" << to_string(i) << "\t";
        file.close();
    }

    int getToken(int i) {
        return token[i];
    }
private:
    int sale[3] = {0,0,0};
    int token[3] = {};
    string filename;
    string line;
    string str;
};


class manage {
protected:
    int coke = 1700;
    int milk = 1300;
    int cider = 1600;
    int energydrink = 2300;

    int cokeP = 0;
    int milkP = 0;
    int ciderP = 0;
    int energydrinkP = 0;

public:

    int getPrice(int p) {
        if (p == 1) {
            return 1700;
        }
        else if (p == 2) {
            return 1300;
        }
        else if (p == 3) {
            return 1600;
        }
        else if (p == 4) {
            return 2300;
        }
        else {
            cout << "해당 음료는 없습니다." << endl;
        }
    }

    void setPrice(int p) {
        int i;
        cout << getPrice(p) << "의 값을 다시 정하세요." << endl;
        cin >> i;
        if (p == 1) {
            coke = i;
        }
        else if (p == 2) {
            milk = i;
        }
        else if (p == 3) {
            cider = i;
        }
        else if (p == 4) {
            energydrink = i;
        }
        else {
            cout << "해당 음료는 없습니다." << endl;
        }
    }



    void count(int p) {
        if (p == 1) {
            cokeP = cokeP + 1;
        }
        else if (p == 2) {
            milkP = milkP + 1;
        }
        else if (p == 3) {
            ciderP = ciderP + 1;
        }
        else if (p == 4) {
            energydrinkP = energydrinkP + 1;
        }
    }

    void getCount() {
        cout << "coke 판매량 : " << cokeP << endl;
        cout << "milk 판매량 : " << milkP << endl;
        cout << "cider 판매량 : " << ciderP << endl;
        cout << "energydrink 판매량 : " << energydrinkP << endl;
    }
};


//machine클래스는 자판기 안의 돈을 관리하고, drink클래스를 상속한다.
class machine : manage {
private:
    int money[4] = { 0,0,0,0 }; //각각 처음부터 500, 100, 50, 10원에 해당하는 배열
    bool canBuy = true;
    
public:
    machine() {
        manage m;

        cout << "자판기 운영을 시작합니다." << endl;
    }
    void month() {

    }


    void supplyMoney() {
        
        cout << "돈을 넣으세요." << endl;

        for (int i = 0; i < 4; i++) {

            if (i == 0) {
                cout << "500원을 보충하세요" << endl;
            }
            else if (i == 1) {
                cout << "100원을 보충하세요" << endl;
            }
            else if (i == 2) {
                cout << "50원을 보충하세요" << endl;
            }
            else {
                cout << "10원을 보충하세요" << endl;
            }

            int num;
            cin >> num;
            money[i] = money[i] + num;
            cout << "보충되었습니다." << endl;
        }
    }

    int* getMoney() {
        return money;
    }
    

    int custMoney() {
        int mon;
        int m50, m10, m5, m1;
        
        cout << "지폐는 얼마치 투입하시겠습니까?" << endl;
        cin >> mon;

        cout << "500원 몇개 투입하시겠습니까?" << endl;
        cin >> m50;
        this->money[0] = this->money[0] + m50;

        cout << "100원 몇개 투입하시겠습니까?" << endl;
        cin >> m10;
        this->money[1] = this->money[1] + m10;

        cout << "50원 몇개 투입하시겠습니까?" << endl;
        cin >> m5;
        this->money[2] = this->money[2] + m5;

        cout << "10원 몇개 투입하시겠습니까?" << endl;
        cin >> m1;
        this->money[3] = this->money[3] + m1;

        mon = mon + (m50 * 500) + (m10 * 100) + (m5 * 50) + (m1 * 10);

        cout << mon << "원 투입했습니다." << endl;

        int vev = calc(getMoney(), mon);
        if (canBuy == false) {
            this->money[0] = this->money[0] - m50;
            this->money[1] = this->money[1] - m10;
            this->money[2] = this->money[2] - m5;
            this->money[3] = this->money[3] - m1;
        }
        return vev;
    }

    void printMoney() {
        cout << "기계에 남은 돈" << endl;
        cout << "500원 : " << money[0] << "개" << endl;
        cout << "100원 : " << money[1] << "개" << endl;
        cout << "50원 : " << money[2] << "개" << endl;
        cout << "10원 : " << money[3] << "개" << endl;
    }

    int calc(int arr[4], int pay) {
        int i;
        cout << "1. coke : " << getPrice(1) << "원11" << endl;
        cout << "2. milk : " << getPrice(2) << "원" << endl;
        cout << "3. cider : " << getPrice(3) << "원" << endl;
        cout << "4. energydrink : " << getPrice(4) << "원" << endl;
        cout << "음료를 고르세요." << endl;
        cin >> i;

        int price = getPrice(i);


        if (pay - price < 0) {
            cout << "돈이 부족합니다." << endl;
            canBuy = false;
        }
        else if (pay - price == 0) {
            cout << "거스름돈은 0 원입니다." << endl;
            canBuy = true;
        }
        else {
            int charge = pay - price;

            cout << "거스름돈은 " << charge << " 원입니다." << endl;

            //500원 계산
            int m50 = charge / 500;
            int p50 = 0;

            if (m50 == 0) {
                p50 = 2;
            }
            else {
                if (m50 > arr[0]) {
                    charge = charge - (500 * arr[0]);
                }
                else {
                    charge = charge - (500 * m50);
                    p50 = 1;
                }
            }

            //100원 계산
            int m10 = charge / 100;
            int p10 = 0;

            if (m10 == 0) {
                p10 = 2;
            }
            else {
                if (m10 > arr[1]) {
                    charge = charge - (100 * arr[1]);
                }
                else {
                    charge = charge - (100 * m10);
                    p10 = 1;
                }
            }

            //50원 계산
            int m5 = charge / 50;
            int p5 = 0;

            if (m5 == 0) {
                p5 = 2;
            }
            else {
                if (m5 > arr[2]) {
                    charge = charge - (50 * arr[2]);
                }
                else {
                    charge = charge - (50 * m5);
                    p5 = 1;
                }
            }

            //10원 계산
            int m1 = charge / 10;
            int p1 = 0;

            if (m1 == 0) {
                p1 = 2;
            }
            else {
                if (m1 > arr[3]) {
                    charge = charge - (10 * arr[3]);
                }
                else {
                    charge = charge - (10 * m1);
                    p1 = 1;
                }
            }

            if (charge > 0) {
                cout << "죄송합니다. 기계에 돈이 부족합니다." << endl;
                canBuy = false;
            }
            else {
                if (p50 == 0) {
                    cout << "500원 : " << arr[0] << "개" << endl;
                    this->money[0] = this->money[0] - arr[0];
                }
                else if (p50 == 2) {

                }
                else {
                    cout << "500원 : " << m50 << "개" << endl;
                    this->money[0] = this->money[0] - m50;
                }

                if (p10 == 0) {
                    cout << "100원 : " << arr[1] << "개" << endl;
                    this->money[1] = this->money[1] - arr[1];
                }
                else if(p10 == 2){

                }
                else {
                    cout << "100원 : " << m10 << "개" << endl;
                    this->money[1] = this->money[1] - m10;
                }

                if (p5 == 0) {
                    cout << "50원 : " << arr[2] << "개" << endl;
                    this->money[2] = this->money[2] - arr[2];
                }
                else if (p5 == 2) {

                }
                else {
                    cout << "50원 : " << m5 << "개" << endl;
                    this->money[2] = this->money[2] - m5;
                }

                if (p1 == 0) {
                    cout << "10원 : " << arr[3] << "개" << endl;
                    this->money[3] = this->money[3] - arr[3];
                }
                else if (p1 == 2) {

                }
                else {
                    cout << "10원 : " << m1 << "개" << endl;
                    this->money[3] = this->money[3] - m1;
                }

                count(i);
                canBuy = true;
            }

        }
        getCount();
        return i;
    }
};



int main()
{
    machine machine;
    int menu;
    MoneyFileModifier file ("C:/Users/redhe/source/repos/vending_machine/money.txt");
    file.appendText();
    machine.getMoney()[0] = file.getToken(0);
    machine.getMoney()[1] = file.getToken(1);
    machine.getMoney()[2] = file.getToken(2);
    machine.getMoney()[3] = file.getToken(3);

    salesFileModifier file1("C:/Users/redhe/source/repos/vending_machine/sales.txt");
    
    time_t timer = time(NULL);
    struct tm* t = localtime(&timer);
    cout << "현재 달 : " << t->tm_mon + 1 << endl;
        
    while (1) {
        cout << "1 - 동전 보급" << endl;
        cout << "2 - 음료구매" << endl;
        cout << "3 - 기계돈관리" << endl;
        cout << "4 - 일별보고서" << endl;
        cout << "5 - 월별보고서" << endl;
        cout << "6 - 종료" << endl;
        cout << "번호를 선택하세요 : ";
        cin >> menu;
        switch (menu)
        {
        case 1:
            machine.supplyMoney();
            break;
        case 2:
            file1.putText(machine.custMoney());
            break;
        case 3:
            machine.printMoney();
            break;
        case 4:
            
            break;
        case 5:
            int mon;
            cout << "몇월달 보고서를 출력하시겠습니까?" << endl;
            cin >> mon;
            file1.month(mon);
            break;
        case 6:
            file.clearText();
            file.putText(machine.getMoney());
            cout << "종료합니다." << endl;
            break;
        default:
            cout << "다시 입력하세요" << endl;
            break;
        }
        if (menu == 6) {
            break;
        }
    }
}

// 프로그램 실행: <Ctrl+F5> 또는 [디버그] > [디버깅하지 않고 시작] 메뉴
// 프로그램 디버그: <F5> 키 또는 [디버그] > [디버깅 시작] 메뉴

// 시작을 위한 팁: 
//   1. [솔루션 탐색기] 창을 사용하여 파일을 추가/관리합니다.
//   2. [팀 탐색기] 창을 사용하여 소스 제어에 연결합니다.
//   3. [출력] 창을 사용하여 빌드 출력 및 기타 메시지를 확인합니다.
//   4. [오류 목록] 창을 사용하여 오류를 봅니다.
//   5. [프로젝트] > [새 항목 추가]로 이동하여 새 코드 파일을 만들거나, [프로젝트] > [기존 항목 추가]로 이동하여 기존 코드 파일을 프로젝트에 추가합니다.
//   6. 나중에 이 프로젝트를 다시 열려면 [파일] > [열기] > [프로젝트]로 이동하고 .sln 파일을 선택합니다.
