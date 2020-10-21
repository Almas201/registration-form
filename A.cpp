#include <bits/stdc++.h>
#include <string>
#include <vector>
#include <map>
#include <math.h>
#include <algorithm>

#define ll long long
#define lld long double
#define mp make_pair
#define endl "\n"
#define pb push_back
#define mod 1000000007
#define Kazakhstan ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

vector<string> usernames(50LL);
vector<string> passwords(50LL);
vector<string> questions(50LL);
vector<string> answers(50LL);
vector<ll> counts(50LL);
bool ok = 1;
ll curr = 0;

ll check(string s){
    if(s=="1") return 1;
    if(s=="2") return 2;
    return 0;
}

ll search(string user){
    for(int i = 0; i < 50; i++){
        if(usernames[i]==user) return i;
    }
    return -1;
}

ll recover(ll user_id){
    printf("Question to recover username\n");
    cout<<questions[user_id]<<endl;
    string answer="";
    printf("Answer: ");
    cin>>answer;
    if(answers[user_id]==answer){
        counts[user_id]=0;
        printf("Username is unblocked! Try to SignIn");
    }else{
        printf("Error! Try it next time!!!");
    }

}

void signup(){
    string username="", password="", question="", answer="";
    printf("Enter username: ");
    cin>>username;
    printf("Enter password: ");
    cin>>password;
    printf("Enter question: ");
    cin>>question;
    printf("Enter answer: ");
    cin>>answer;

    usernames[curr]=username;
    passwords[curr]=password;
    questions[curr]=question;
    answers[curr]=answer;
    curr++;
}

void signin(){
    string username="", password="";
    printf("Enter username: ");
    cin>>username;
    ll user_id=search(username);
    if(user_id!=-1LL){
        if(counts[user_id]>=2){
            printf("The user is blocked!\nDo u recover it? If u wanna enter Y or N: ");
            string s="";
            cin>>s;
            if(s=="y"||s=="Y") recover(user_id);
            if(s=="n"||s=="N") return;
        }else{
            printf("Enter password: ");
            cin>>password;
            if(passwords[user_id]==password){cout << usernames[user_id]; printf(" are Joined!!!");}
            else{printf("Wrong password!!!"); counts[user_id]++;}
        }
    }else{
        printf("No such a user");
    }
}

void menu(){
    string choice="";
    while(ok){
        printf("Welcome to MENU!!!\n1. SignIn\n2. SignUp\nIf u wanna to SignIn enter 1 or 2 to SignUp");
        printf("\nUr choice: ");
        cin>>choice;
        int num = check(choice);
        switch(num){
            case 1:
                signin();
                break;
            case 2:
                signup();
                break;
            default:
                printf("Nothing!!!");
                break;
        }
        printf("\nIf u wanna continue enter 1 or 0 to finish: ");
        cin>>ok;
        choice="";
    }
}

int main(){
    ll t = 1;
    //cin >> t;
    while(t--){
        menu();
    }
}
