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

    cout<<"______________________________________"<<endl;
    cout<<"                                      "<<endl;
    cout<<"                                      "<<endl;
    cout<<"                                      "<<endl;
    cout<<"     :Supermarket Main Menu           "<<endl;
    cout<<"                                      "<<endl;
    cout<<"                                      "<<endl;
    cout<<"______________________________________"<<endl;
    cout<<"     1) Adminsitrator                 "<<endl;
    cout<<"                                      "<<endl;
    cout<<"     2) Buyer                         "<<endl;
    cout<<"                                      "<<endl;
    cout<<"     3) Exit                          "<<endl;
    cout<<"                                      "<<endl;
    cout<<"     plese select!"<<endl;
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
            cout<<"Invalid email/password"<<endl;
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
        cout<<"please select from the given option"<<endl;
    }
    }
    goto m;
}

void shopping :: administration()
{  
    m:
    int choice;
    cout<<"      Administrator menu    "<<endl;
    cout<<"                             "<<endl;
    cout<<"      1)  Add the product    "<<endl;
    cout<<"                              "<<endl;
    cout<<"      2) modify the product    "<<endl;
    cout<<"                                "<<endl;
    cout<<"      3) delete the product     "<<endl;
    cout<<"                                "<<endl;
    cout<<"      4) back to main menu      "<<endl;

    cout<<"                                "<<endl;
    

    cout<<"   plese enter your choice   "<<endl;
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
    cout<<"           invalid choice        "<<endl;
    cout<<"                                "<<endl;


}
goto m;


}

void shopping :: buyer()
{
m:
    int choice;
    cout<<"         buyer                  "<<endl;
    cout<<"                                "<<endl;
    cout<<"___________________________________"<<endl;
    cout<<"                                "<<endl;
    cout<<"         1) buy product           "<<endl;
    cout<<"                                "<<endl;
    cout<<"         2) go back               "<<endl;
    cout<<"                                "<<endl;
    cout<<"                                "<<endl;
    cout<<"enter your choice : "<<endl;
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
    cout<<"          invalid choice         "<<endl;
    cout<<"                                "<<endl;


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

    cout<<"                                "<<endl;
    cout<<"    Add new produc"  <<endl;
    cout<<"  product code of the product "<<endl;
    cin>>pcode;
    cout<<"      Name of produc "<<endl;
    cin>>pname;

    cout<<"      price of the product "<<endl;
    cin>>price;
    cout<<"      discount on the product "<<endl;
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
        
        if(token == 1)
        goto m;
        
        else{
    data.open("database.txt" , ios :: app | ios :: out );
    data<<" "<<pcode<<" "<<pname<<" "<<price<<" "<<dis<<"\n";
    data.close();
    }

}
cout<< "       recode inserted  !    "<<endl;

}
void shopping :: edit()
{
    fstream data,data1;
    int pkey;
    int token =0 ;
    int c;
    float p;
    float d ;
    string n;

    cout<<"   modify the recode  "<<endl;
    cout<<"   enter the product code : "<<endl;
    cin>>pkey;

    data.open("database.txt",ios::in);
    if(!data)
    {
        cout<<  "    file  does't exist! "<<endl;

    }
    else {
        data1.open ("database1.txt",ios::app | ios::out);
        data>>pcode>>pname>>price>>dis;
        while(!data.eof())
        {
            if(pkey == pcode){
                cout<<" product  new code : " <<endl;
                cin>>c;
                cout<<" name of the product : "<<endl;
                cin >>p;
                cout<<" discode :" <<endl;
                cin>>d ;
                data1<< " "<<c<<" "<<n<<" "<<p<<"  "<<d<<endl;
                cout<<"   recode modified  "<<endl;
                token++;
            }
            else {
                data1<<" "<<pcode<<" "<<pname<<" "<<price<<" "<<dis<<endl;
            }
            data>>pcode>>pname>>price>>dis;

            }

            data.close();
            data1.close();
            remove("database.txt");
            rename("database1.txt","database.txt");

            if(token ==0)
            {
                cout<<" record not found ! "<<endl;
            }   
            }
}

void shopping ::rem()
{
    fstream data,data1;
    int pkey;
    int token =0;
    cout<<" delete product "<<endl;
    cout<<"     product  code :"<<endl;
    cin>>pkey;
    data.open("database.txt",ios::in); 
    if(!data)
    {
        cout<<" file does not exist "<<endl;

        }
        else {
            data1.open("database1.txt",ios::app|ios::out);
            data>>pcode>>pname>>price>>dis;
            while(!data.eof())
            {
                if(pcode== pkey ){
                    cout<<"  product deleted succesfully "<<endl;
                    token++;

                }

                else 
                {
                    data<<"  "<<pcode<<"  " <<pname<<"  "<<price<<"  "<<dis<<endl;
                }
                data>>pcode>>pname>>price>>dis;
            }
            data.close();
            data1.close();

            remove("database.txt");
            rename("database1.txt","database.txt"); 

            if(token==0)
            {
                cout<<" product with this code does not exist "<<endl;
            }


    }
    
}

void shopping :: list()
{
    fstream data;
    data.open("database.txt",ios::in);
    cout<<"________________________________________________________________"<<endl;
    cout<<"prno\t\tname\t\tprice\t\tdiscount\n";
    cout<<"\n\n|___________________________________________________________"<<endl;
    data>>pcode>>pname>>price>>dis;
while(!data.eof()){
    cout<<pcode<<"   "<<pname<< "  "<<price <<endl;
    data>>pcode>>pname>>price >>dis;

}
data.close();

}

void shopping :: receipt(){
    
    fstream data;

    int arrc[100];
    int arrq[100];
    char choice ;
    int c =0 ;
    float amount = 0;
    float dis =0;
    float total = 0;

    cout<<"   RECEIPT   "<<endl;
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
            cout<<  "Enter product code :"<<endl;
            cin>>arrc[c];
            cout<<"Enter the product quantity :"<<endl;
            cin>>arrq[c];
            for(int i = 0 ; i<c;i++){
                if(arrc[c] == arrc[i]){
                    cout<<"   Duplicate product code. Please try again!"<<endl;
                    goto m;
                }
            }
            c++;
            cout<<"Do you want to buy another product? if yes then press y else no"<<endl;
            cin>>choice;
            }
            while(choice == 'y');
            cout<<"                                         "<<endl;
            cout<<"__________________________________________"<<endl;
            cout<<"                                         "<<endl;
            cout<<"                RECEIPT                  "<<endl;
            cout<<"_________________________________________"<<endl;

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
cout<<"                                                        "<<endl;
cout<<"             Total Amount                   "<<endl;
}

int main()
{
    shopping s;
    s.menu();
    
return 0;
}
