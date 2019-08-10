
/////////////////////////////////////
// Input should be in this format: //
//   6:00 am or 12:30 pm etc       //
/////////////////////////////////////
#include <iostream>
#include <string>
using namespace std;
string time[3]; //stores the hrs mins am/pm
//hrs to mins
int hrstomins(int val) { 
    return val * 60;
}
void readtime(string s) { //extracting hrs mins from the input
    string a;
    for (int i = 0; i <= 2; i++) 
        for (int j = 0; j < s.length(); j++) {
            if (s[j] == ':' || s[j] == ' ') {
                a = "";
                i++;
            }
            else {
                if ((s[j] >= '0' && s[j] <= '9') || (s[j] >= 'a' && s[j] <= 'z')) {
                    a += s[j];
                    time[i] = a;
                }
            }
        }
}
 //checks the next meal
void timeleft(int val, int mtime, string s, int h) {
    int diffinmins=0,mealtime=0, j = 0, k = 0;
    int fornight = 19; // 19 bcoz 12(starting point) + 7(next meal)

    if (s == "pm" && h < 12 && h > 7)
        mealtime = hrstomins(fornight);
    else
        mealtime = hrstomins(mtime); 

    if (val > mealtime)
        diffinmins = val - mealtime;
    else
        diffinmins = mealtime - val;

    j = diffinmins / 60;
    k = diffinmins % 60;
    
    cout << j << " hr(s) " << k << " min(s) until next meal.\n\nHave patience ;)";
}
//tells us the time of the next meal
void time_to_eat(string s) { 
    string t = time[0], t1 = time[1], t2 = time[2];
    int hour = stoi(t), mins = stoi(t1);

    int hrsinMins = hrstomins(hour) + mins;
    if (hour == 7 && mins == 0) 
        cout << 12-hour << " hrs until next meal.";
    else if (hour == 12 && mins == 0)
        cout <<hour-5<< " hrs until next meal.";
    else {
        if (t2 == "am") {
            if (hour == 7)
                timeleft(hrsinMins, 12, "am", 0); // 12 bcoz 7(starting point) + 5(next meal i.e at 12)
            else if (hour == 12)
                timeleft(hrsinMins, 19, "am", 0); // 19 bcoz 12(starting point) + 7(next meal)
            if (hour < 7)
                timeleft(hrsinMins,7, "am", 0);
            else if (hour > 7 && hour < 12)
                timeleft(hrsinMins,12, "am", 0);
        }
        else if (t2 == "pm") {
            if (hour == 7)
                timeleft(hrsinMins,12, "pm", 0);
            else if (hour == 12)
                timeleft(hrsinMins,19, "pm", 0);
            if (hour < 7)
                timeleft(hrsinMins,7, "pm", 0);
            else if (hour > 7 && hour < 12)
                timeleft(hrsinMins, 12, "pm", hour);
        }
    }
}
int main(void) {
    string str;
    getline(cin, str);
    readtime(str);
    cout << "Current time: " << str << endl;
    time_to_eat(str);
}
