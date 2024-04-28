//resolve the error ?

//find error form this code
#include<iostream>
using namespace std;

#include<iostream>
#include<fstream>

using namespace std;

class shopping 
{
    private:
    int pcode ;
    float price;
    float dis;
    string pname;

    public:
    void menu();
    void administration();
    void  buyer();
    void add();
    void edit();
    void rem();
    void list();
    void receipt();

};

void shopping :: menu()
{
    m:
    int choice;
    string email;
    string pass;

    cout<<"\t\t\t__________________________________\n";
    cout<<"                                        \n";
    cout<<"                                       "<<endl
    cout<<"       Supermarket Main Menu           "<<endl;
    cout<<"                                       "<<endl;
    cout<<"                                       "<<endl;
    cout<<"_______________________________________"<<endl;
    cout<<"     1) Adminsitrator                  "<<endl;
    cout<<"                                       "<<endl;
    cout<<"     2) Buyer                          "<<endl;
    cout<<"                                       "<<endl;
    cout<<"     3) Exit                           "<<endl;
    cout<<"                                       "<<endl;
    cout<<"     plese select!";
    cin>>choice;
    switch(choice)
    {
        case 1 :
        {
        cout<<"   please login "<<endl;
        cout<<"   enter emai"   <<endl;
        cin>>email;
        cout<<"   enter password"<<endl;
        cin>>pass;

        if(email=="saurabhwanjari10@gmail.com" && pass=="12345")
        {
            administration();
        }
        else
        {
            cout<<"Invalid email/password";
        }
        break;
        }

    case 2 :
    {
        buyer();
    }
    case 3 :
    {
        exit(0);
    }
    default :
    {
        cout<<"please select from the given option";
    }
    }
    goto m;
}

void shopping :: administration()
{  
    m:
    int choice;
    cout<<"      Administrator menu    ";
    cout<<"      1)  Add the product    ";
    cout<<"                              ";
    cout<<"      2) modify the product    ";
    cout<<"                                ";
    cout<<"      3) delete the product     ";
    cout<<"                                ";
    cout<<"      4) back to main menu      ";

    cout<<"                                ";
    

    cout<<"   plese enter your choice   ";
    cin>>choice ;

    switch (choice)
    {
    case 1 :
    {
        add();
        break;
    }
    case 2 :
    {
        edit();
        break;
    }
    case 3 :
    {
        rem();
        break;
    }
    case 4 :
    {
        menu();
        break;
    }
default :
    cout<<"invalid choice";
    cout<<"                                ";


}
goto m;


}

void shopping :: buyer()
{
m:
    int choice;
    cout<<"         buyer                  ";
    cout<<"                                ";
    cout<<"___________________________________";
    cout<<"                                ";
    cout<<"         1) buy product           ";
    cout<<"                                ";
    cout<<"         2) go back               ";
    cout<<"                                ";
    cout<<"                                ";
    cout<<"enter your choice : ";
    cin>>choice;    


switch (choice)
{
case 1 :
    {
        receipt();
        break;
    }
    case 2 :
    {
        menu();
        break;
    }
    default :
    cout<<"invalid choice";
    cout<<"                                ";


}
goto m;


}

void shopping :: add()
{
    m :

    fstream data;
    int c;
    int token = 0;
    float p;
    float d;
    string n;

    cout<<"                                ";
    cout<<"    Add new produc"  ;
    cout<<"  product code of the product ";
    cin>>pcode;
    cout<<"      Name of produc ";
    cin>>pname;

    cout<<"      price of the product ";
    cin>>price;
    cout<<"      discount on the product ";
    cin>>dis;

    data.open("database.txt",ios::in);
    if(!data)
    
    {
        data.open("database.txt",ios::app|ios::out);
        data<<" "<<pcode<<" "<<pname<<" "<<price<<" "<<dis<<"\n";
        data.close();

        }
        else {
            data>>c>>n>>p>>d;

            while(!data.eof())
            {
                if(c==pcode)
                {
                    token++;
                }
                data>>c>>n>>p>>d;
            }
            data.close();
        }
}

if(tokan == 1)utou
goto m;
else{
    data.open("database.txt" , ios :: app | ios :: out );
    data<<" "<<pcode<<" "<<pname<<" "<<price<<" "<<dis<<"\n";
    data.close();
}

}
cout<< "       recode inserted      ";

}

void shopping :: edit()
{
    fsteam data , data1;
    int pkey;
    int token =0 ;
    int c;
    float p;
    float d ;
    string n;

    cout<<"   modify the recode  ";
    cout<<"   enter the product code : ";
    cin>>pkey;

    data.open("database.txt",ios::in);
    if(!data)
    {
        cout<<  "    file  does't exist! ";

    }
    else {
        data1.open ("database1.txt",ios::app | ios::out);
        data>>pcode>>pname>>price>>dis;
        while(!data.eof())
        {
            if(pkey == pcode){
                cout<<" product  new code : " ;
                cin>>c;
                cout<<" name of the product : ";
                cin >>p;
                cout<<" discode :";
                cin>>d ;
                data1<< " "<<c<<" "<<n<<" "<<p<<"  "<<d<<endl;
                cout<<"   recode modified  ";
                token++;
            }
            else {
                data1<<" "<<pcode<<" "<<pname<<" "<<price<<" "<<dis<<endl;
            }
            data>>pcode>>pname>>price>>disc;

            }

            data.close();
            data1.clode();
            remove("database.txt");
            rename("database1.txt","database.txt");

            if(token ==0)
            {
                cout<<" record not found ! ";
            }   
            }
}

void shopping ::rem()
{
    fstream data,data1;
    int pkey;
    int token =0;
    cout<<" delete product ";
    cout<<"     product  code :";
    cin>>pkey;
    data.open("database.txt",ios::in); 
    if(!data)
    {
        cout<<" file does not exist ";

        }
        else {
            data1.open("database1.txt",ios::app|ios::out);
            data>>pcode>>pname>>price>>disc;
            while(!data.eof())
            {
                if(pcode== pkey ){
                    cout<<"  product deleted succesfully ";
                    token++;

                }

                else 
                {
                    data<<"  "<<pcode<<"  " <<pname<<"  "<<price<<"  "<<dis<<end;
                }
                data>>pcode>>pname>>price>>dis;
            }
            data.close();
            data1.close();

            remove("database.txt");
            rename("database1.txt","database.txt"); 

            if(token==0)
            {
                cout<<" product with this code does not exist ";
            }


    }
    
}

void shopping :: list()
{
    fstream data;
    data.open("database.txt",ios::in);
    cout<<"________________________________________________________________";
    cout<<"prno\t\tname\t\tprice\t\tdiscount\n";
    cout<<"\n\n|___________________________________________________________";
    data>>pcode>>pname>>price>>dis;
while(!data.eod()){
    cout<<pcode<<"   "<<pname<< "  "<<price <<endl;
    data>>pcode>>pname>>price >>dis;

}
data.close();

}

void shopping receipt(){
    
    fstream data;
    int arrc[100];
    int arrq[100];
    char choice ;
    int c =0 ;
    float amount = 0
    float dis =0; 
    float total = 0;

    cout<<"   RECEIPT   ";
    data.open("database.txt",ios::in);
    if(!data){
        cout<< "   empty database";

    }

    else{
        data.close();
        list();
        cout<<"_________________________________________"<<endl;
        cout<<"                                         "<<endl;
        cout<<"         Please place the order         "<<endl;
        cout<<"                                         "<<endl;
        cout<<"__________________________________________"<<endl;

        do
         {
            m:
            cout<<  "Enter product code :";
            cin>>arrc[c];
            cout<<"Enter the product quantity :";
            cin>>arrq[c];
            for(int i = 0 ; i<c;i++){
                if(arrc[c] == arrc[i]){
                    cout<<"   Duplicate product code. Please try again!";
                    goto m;
                }
            }
            c++;
            cout<<"Do you want to buy another product? if yes then press y else no";
            cin>>choice;
            }
            while(choice == 'y');
            cout<<"                                         "<<endl;
            cout<<"__________________________________________"<<endl;
            cout<<"                                         "<<endl;
            cout<<"                RECEIPT                  "<<endl;
            cout<<"                                         "<<endl;

            for(int i = 0; i<c;i++){

                data.open ("database.txt",ios::in);
                data>>pcode>>pname>>price>>dis;
                while(!data.eof()){
                    if(pcode == arrc[i]){
                        amount = (price * arrq[i]);
                        dis = amount - (amount * dis/ 100);
                        total = total +dis;
                        cout<< "   "<< pcode << "   " << pname<<"   " <<arrq[i]<<"   "<<price<<"   "<<amount<<"  " <<dis<<endl;
                    }
                    data>>pcode>>pname>>price>>dis;   
        }
    }

    data.close();
}
cout<<"                                                     ";
cout<<"                          total amount : "<<total<<endl;
cout<<"                                                     "<<endl;

}

int main()
{
    shopping s;
    s.menu();
    
}





////////////////////////////////////////////////////////////////////////////////////////



#include <iostream>
#include <fstream>
using namespace std;

class shopping 
{
private:
    int pcode;
    float price;
    float dis;
    string pname;

public:
    void menu();
    void administration();
    void buyer();
    void add();
    void edit();
    void rem();
    void list();
    void receipt();

};

void shopping :: menu()
{
m:
    int choice;
    string email;
    string pass;

    cout<<"\t\t\t_________________________________"<<endl;
    cout<<"                                       "<<endl;
    cout<<"                                       "<<endl;
    cout<<"       Supermarket Main Menu           "<<endl;
    cout<<"                                       "<<endl;
    cout<<"                                       "<<endl;
    cout<<"_______________________________________"<<endl;
    cout<<"     1) Administrator                  "<<endl;
    cout<<"                                       "<<endl;
    cout<<"     2) Buyer                          "<<endl;
    cout<<"                                       "<<endl;
    cout<<"     3) Exit                           "<<endl;
    cout<<"                                       "<<endl;
    cout<<"     Please select an option: ";
    cin>>choice;

    switch(choice)
    {
    case 1 :
        {
            cout<<"   Please login "<<endl;
            cout<<"   Enter email: ";
            cin>>email;
            cout<<"   Enter password: ";
            cin>>pass;

            if(email == "saurabhwanjari10@gmail.com" && pass == "12345")
            {
                administration();
            }
            else
            {
                cout<<"Invalid email/password";
            }
            break;
        }

    case 2 :
        {
            buyer();
            break;
        }
    case 3 :
        {
            exit(0);
            break;
        }
    default :
        {
            cout<<"Please select from the given options";
            break;
        }
    }
    goto m;
}

void shopping :: administration()
{  
m:
    int choice;
    cout<<"      Administrator menu    "<<endl;
    cout<<"      1) Add the product    "<<endl;
    cout<<"      2) Modify the product "<<endl;
    cout<<"      3) Delete the product "<<endl;
    cout<<"      4) Back to main menu  "<<endl;
    cout<<"   Please enter your choice: ";
    cin>>choice;

    switch (choice)
    {
    case 1 :
        {
            add();
            break;
        }
    case 2 :
        {
            edit();
            break;
        }
    case 3 :
        {
            rem();
            break;
        }
    case 4 :
        {
            menu();
            break;
        }
    default :
        {
            cout<<"Invalid choice";
            break;
        }
    }
    goto m;
}

void shopping :: buyer()
{
m:
    int choice;
    cout<<"         Buyer                  "<<endl;
    cout<<"________________________________"<<endl;
    cout<<"         1) Buy product         "<<endl;
    cout<<"         2) Go back             "<<endl;
    cout<<"________________________________"<<endl;
    cout<<"Enter your choice: ";
    cin>>choice;    

    switch (choice)
    {
    case 1 :
        {
            receipt();
            break;
        }
    case 2 :
        {
            menu();
            break;
        }
    default :
        {
            cout<<"Invalid choice";
            break;
        }
    }
    goto m;
}

void shopping :: add()
{
m:
    fstream data;
    int token = 0;
    float p;
    float d;
    string n;

    cout<<"Add new product"<<endl;
    cout<<"Product code of the product: ";
    cin>>pcode;
    cout<<"Name of product: ";
    cin>>pname;
    cout<<"Price of the product: ";
    cin>>price;
    cout<<"Discount on the product: ";
    cin>>dis;

    data.open("database.txt", ios::in);
    if(!data)
    {
        data.open("database.txt", ios::app | ios::out);
        data<<pcode<<" "<<pname<<" "<<price<<" "<<dis<<"\n";
        data.close();
    }
    else
    {
        data.close();
    }

    cout<<"Record inserted"<<endl;
}

void shopping :: edit()
{
    fstream data, data1;
    int pkey;
    int token = 0;
    int c;
    float p;
    float d ;
    string n;

    cout<<"Modify the record"<<endl;
    cout<<"Enter the product code: ";
    cin>>pkey;

    data.open("database.txt", ios::in);
    if(!data)
    {
        cout<<"File does not exist!"<<endl;
    }
    else
    {
        data1.open ("database1.txt", ios::app | ios::out);
        while(!data.eof())
        {
            data>>pcode>>pname>>price>>dis;
            if(pkey == pcode)
            {
                cout<<"Enter new product code: ";
                cin>>c;
                cout<<"Enter name of the product: ";
                cin>>n;
                cout<<"Enter discount: ";
                cin>>d;
                data1<<c<<" "<<n<<" "<<price<<" "<<d<<endl;
                token++;
            }
            else
            {
                data1<<pcode<<" "<<pname<<" "<<price<<" "<<dis<<endl;
            }
        }

        data.close();
        data1.close();
       
