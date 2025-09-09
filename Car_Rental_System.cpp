#include<iostream>
#include<mysql.h>
#include<mysqld_error.h>
#include<windows.h>
#include<sstream>
using namespace std;

const char* HOST = "localhost";
const char* USER = "root";
const char* PW = " ";
const char* DB = "mydb";

class Car{
    private:
        string Brand, Model;
        int Serial, Rent;
        bool Available;
    public:
        Car(int serial, string brand, string model, int rent, bool avail){
        Serial = serial;
        Brand = brand;
        Model = model;
        Rent = rent;
        Availabe = avail;
        }

    int getSerial(){
        return Serial;
    }
    int getRent(){
        return Rent;
    }
    string getBrand(){
        return Brand;
    }
    string getModel(){
        return Model;
    }
    bool getAvailable(){
        return Available;
    }
};

bool isAvailabe(MYSQL* conn, string toS){
    string com = "SELECT AVAILABLE FROM cars WHERE = '"+toS+"'";
    if(mysql_query(conn, comp.c_str())){
        cout<<"Error: "<<mysql_erro(conn)<<endl;
        return false;
    }
    MYSQL_RES* result = mysql_store_result(conn);
    if(result){
        MSQL_ROW row= mysql_fetch_row(result);
        if(row){
            int availability = atoi(row[0]);
            mysql_fre_result(result);
            return(availability==1);
        }
        mysql_free_result(result);
    }
    return false;
}

int main(){
    MYSQL* conn;
    conn = mysql_int(NULL);
    if(!mysql_real_connect(conn, HOST, USER, PW, DB, 3306, NULL, 0)){
        cout<<"Error: "<<mysql_erroe(conn)<<endl;
    }
    else{
        cout<<"Logged In!! "<<endl;
    }
    Car car1(123, "Honda", "Civic", 60, true);
    Car car2(223, "Maruti", "Swift", 50, true);
    Car car3(323, "Honda", "Amaze", 80, true);
    Car car4(423, "Hyundai", "I20", 60, true);
    Car car5(523, "Tata", "Nexon", 60, true);
    Car car6(623, "Toyota", "Yaris", 50, true);

    string save1="INSERT INTO cars (Serial, Brand, Model, Rent, Availabe) VALUES(123, "Honda", "Civic", 60, true)";
    string save2="INSERT INTO cars (Serial, Brand, Model, Rent, Availabe) VALUES(223, "Maruti", "Swift", 50, true)";
    string save3="INSERT INTO cars (Serial, Brand, Model, Rent, Availabe) VALUES(323, "Honda", "Amaze", 80, true)";
    string save4="INSERT INTO cars (Serial, Brand, Model, Rent, Availabe) VALUES(423, "Hyundai", "I20", 60, true)";
    string save5="INSERT INTO cars (Serial, Brand, Model, Rent, Availabe) VALUES(523, "Tata", "Nexon", 60, true)";
    string save6="INSERT INTO cars (Serial, Brand, Model, Rent, Availabe) VALUES(623, "Toyota", "Yaris", 50, true)";
    if(mysql_query(conn, save1.c_str()) || mysql_query(conn, save2.c_str()) || mysql_query(conn, save3.c_str()) || mysql_query(conn, save4.c_str()) || mysql_query(conn, save5.c_str()) || mysql_query(conn, save6.c_str())){
        cout<<"Error: "<<mysql_error(conn)<<endl;
    }
    else{
        cout<<"Data Saved For Cars"<<endl;
    }
    Sleep(5000);

    bool exit = false;
    while(!exit){
        system("cls");
        cout<<"Welcome To Car Rental System "<<endl;
        cout<<"*****************************"<<endl<<endl;
        string get = "SELECT * FROM cars";
        if(mysql_query(conn, get.c_str())){
            cout<<"Erros: "<<mysql_error(conn)<<endl;
        }
        else{
            MYSQL_RES* result = mysql_stroe_result(conn);
            if(result){
                int num = mysql_num_field(result);
                MYSQL_ROW row;
                while(row=mysql_detch_row(result)){
                    for(int i=0; i<num; i++){
                        cout<<" "<<row[i];
                    }
                    cout<<endl;
                }
                mysql_free_result(result);
            }
        }
        int val;
        cout<<endl;
        cout<<"1. Selecct Car. ",,endl;
        cout<<"0. Exit. "<<endl<<endl;
        cin>>val;

        if(val==1){
            int ser;
            cout<<"Enter Serial No: ";cin>>ser;
            stringstream ss;
            ss<<ser;
            string toS = ss.str();

            if(car1.getSerial()==ser){
                if(isAvailabe(conn, toS)){
                    string upd = "UPDATE cars Set Available = '0' WHERE Serial = '"+toS+"'";
                    if(mysql_query(conn, upd.c_str())){
                        cout<<"Error: "<<mysql_error(conn);
                    }
                    else{
                        cout<<"You Have Selected Following Car: "<<endl;
                        cout<<" "<<car1.getBrand()<<" "<<car1.getModel()<<" $"<<car1.getRent()<<endl;
                    }
                }
                else{
                        cout<<"Sorry This Car Is Already Booked. "<<endl;
                }
            }
            if(car2.getSerial()==ser){
                if(isAvailabe(conn, toS)){
                    string upd = "UPDATE cars Set Available = '0' WHERE Serial = '"+toS+"'";
                    if(mysql_query(conn, upd.c_str())){
                        cout<<"Error: "<<mysql_error(conn);
                    }
                    else{
                        cout<<"You Have Selected Following Car: "<<endl;
                        cout<<" "<<car2.getBrand()<<" "<<car2.getModel()<<" $"<<car2.getRent()<<endl;
                    }
                }
                else{
                        cout<<"Sorry This Car Is Already Booked. "<<endl;
                }
            }
            if(car3.getSerial()==ser){
                if(isAvailabe(conn, toS)){
                    string upd = "UPDATE cars Set Available = '0' WHERE Serial = '"+toS+"'";
                    if(mysql_query(conn, upd.c_str())){
                        cout<<"Error: "<<mysql_error(conn);
                    }
                    else{
                        cout<<"You Have Selected Following Car: "<<endl;
                        cout<<" "<<car3.getBrand()<<" "<<car3.getModel()<<" $"<<car3.getRent()<<endl;
                    }
                }
                else{
                        cout<<"Sorry This Car Is Already Booked. "<<endl;
                }
            }
            if(car4.getSerial()==ser){
                if(isAvailabe(conn, toS)){
                    string upd = "UPDATE cars Set Available = '0' WHERE Serial = '"+toS+"'";
                    if(mysql_query(conn, upd.c_str())){
                        cout<<"Error: "<<mysql_error(conn);
                    }
                    else{
                        cout<<"You Have Selected Following Car: "<<endl;
                        cout<<" "<<car4.getBrand()<<" "<<car4.getModel()<<" $"<<car4.getRent()<<endl;
                    }
                }
                else{
                        cout<<"Sorry This Car Is Already Booked. "<<endl;
                }
            }
            if(car5.getSerial()==ser){
                if(isAvailabe(conn, toS)){
                    string upd = "UPDATE cars Set Available = '0' WHERE Serial = '"+toS+"'";
                    if(mysql_query(conn, upd.c_str())){
                        cout<<"Error: "<<mysql_error(conn);
                    }
                    else{
                        cout<<"You Have Selected Following Car: "<<endl;
                        cout<<" "<<car5.getBrand()<<" "<<car5.getModel()<<" $"<<car5.getRent()<<endl;
                    }
                }
                else{
                        cout<<"Sorry This Car Is Already Booked. "<<endl;
                }
            }
            if(car6.getSerial()==ser){
                if(isAvailabe(conn, toS)){
                    string upd = "UPDATE cars Set Available = '0' WHERE Serial = '"+toS+"'";
                    if(mysql_query(conn, upd.c_str())){
                        cout<<"Error: "<<mysql_error(conn);
                    }
                    else{
                        cout<<"You Have Selected Following Car: "<<endl;
                        cout<<" "<<car6.getBrand()<<" "<<car6.getModel()<<" $"<<car6.getRent()<<endl;
                    }
                }
                else{
                        cout<<"Sorry This Car Is Already Booked. "<<endl;
                }
            }
        }
        Sleep(8000);
        else if(val==0){
            exit=true;
            cout<<" Thank You For Your Service. BYE!! "<<endl;
            Sleep(2000);
        }
    }
    mysql_close(conn);

    return 0;
}