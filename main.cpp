#include <map>
#include "TwitterData.hpp"

using namespace std;

int main(int argc, char* argv[])
{
    // Schema: UserName,Last,First,Email,NumTweets,MostViewedCategory
    string raw_data[5][6] = {{"rangerPower","Smit","Rick","smitRick@gmail.com","1117","power lifting"},
                             {"kittyKat72","Smith","Kathryn","kat@gmail.com","56","health"},
                             {"lexi5","Anderson","Alexis","lexi5@gmail.com","900","education"},
                             {"savage1","Savage","Ken","ksavage@gmail.com","17","president"},
                             {"smithMan","Smith","Rick","rick@hotmail.com","77","olympics"}};
    TwitterData *twitter_data = new TwitterData[5];
    for (int i = 0; i < 5; ++i) {
        twitter_data[i].setUserName(raw_data[i][0]);
        twitter_data[i].setActualName(raw_data[i][2] + " " + raw_data[i][1]);
        twitter_data[i].setEmail(raw_data[i][3]);
        twitter_data[i].setNumTweets(stoi(raw_data[i][4]));
        twitter_data[i].setCategory(raw_data[i][5]);
    }

    map <int, TwitterData> m1;
    for (int i =0; i < 5;i++) {
            m1.insert(pair<int, TwitterData>(i , twitter_data[i]));
    }

    map<int, TwitterData>::iterator itr;
    for(itr = m1.begin();itr != m1.end();itr++){
        cout << itr->first << '\t' << itr->second.getUserName() << '\n';
        cout << itr->first << '\t' << itr->second.getActualName() << '\n';
        cout << itr->first << '\t' << itr->second.getEmail() << '\n';
        cout << itr->first << '\t' << itr->second.getNumTweets() << '\n';
        cout << itr->first << '\t' << itr->second.getCategory() << '\n';
    }

    cout << "Searching for Name...\n";
    for(itr = m1.begin();itr != m1.end();itr++)
        if(itr->second.getUserName() == "savage1")
            cout << "Found: " << itr->second.print() << endl;

    return 0;
}