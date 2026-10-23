// =====================================================================
//  C++ WARM-UP  ·  African Olympiad Academy
//
//  The question descriptions are in README.md. Read them there.
//  This file holds the data, one worked example, and your answers.
//
//  BUILD AND RUN:   g++ -std=c++17 -Wall -o run warmup.cpp && ./run
//            or:    ./run.sh
//
//  Work on ONE question at a time. Write it, run it, check the output
//  against the README, commit it, move on.
// =====================================================================

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

/**
 * THE RECORD
 * One delivery: who brought it, how much, and what grade it was given.
 */
struct Delivery {
    string farmer;
    double kg;
    char   grade;
};

/**
 * THE DATA
 * Do not change these. Every expected answer in the README comes from exactly this data.
 */

// Q1 — one morning's weights, in the order they were weighed
vector<double> morningWeights = {
    45.5, 80.0, 12.0, -3.0, 66.5, 20.0, 31.0, 95.0, 50.0, 18.5, 0.0, 72.0
};


// Q2, Q3, Q4, Q7, Q8 — the day's logbook
vector<Delivery> logbook = {
    {"Keza",    45.5, 'A'},
    {"Bonu",    80.0, 'B'},
    {"Isanda",  20.0, 'A'},
    {"Keza",    12.0, 'C'},
    {"Onyinye", 66.5, 'B'},
    {"Karimi",  31.0, 'A'},
    {"Karimi",  31.0, 'A'},
    {"Keza",    18.5, 'B'},
    {"Bonu",    50.0, 'C'},
    {"Isanda",  20.0, 'A'},
    {"Onyinye", 72.0, 'A'}
};   // yes, one of these rows is in here twice. Q8 is about that.

// Q5 — records as the volunteers typed them, before any checking. Several of these are wrong. That is the point.
struct RawRecord {
    string id;
    string kg;        // text, because a volunteer can type anything
    char   grade;
};

vector<RawRecord> rawRecords = {
    {"F012", "45.5",  'A'},
    {"F7",   "20",    'A'},
    {"F033", "heavy", 'B'},
    {"F021", "0",     'C'},
    {"F044", "80",    'b'},
    {"F055", "",      'A'},
    {"F066", "31.5",  'D'},
    {"F077", "92",    'B'}
};

// Q6 — an Igisoro board. 16 pits, in sowing order.
//      Position 0 is unused so that board[1] really is pit 1.
vector<int> board = {0, 0, 0, 1, 0, 0, 4, 1, 0, 0, 2, 2, 0, 1, 5, 0, 0};


// ---------------------------------------------------------------------
//  A HELPER YOU MAY FIND USEFUL
// ---------------------------------------------------------------------
void printBoard(const vector<int> &b) {
    for (int i = 1; i <= 16; i++) cout << b[i] << " ";
    cout << "\n";
}

int findFarmer(const vector<Delivery> &log, string name);
double payment(double kg, char grade);


int main() {

    // =================================================================
    //  WORKED EXAMPLE  ·  not a question
    //
    //  This is the house style: walk the data once, keep what you need
    //  as you go, print at the end. Read it before you start Q1.
    //
    //  It answers: how many deliveries were grade A, and what was the
    //  heaviest single delivery in the whole logbook?
    // =================================================================

    int gradeACount = 0;
    Delivery heaviest = logbook[0];        // start from a REAL entry,
                                           // never from a made-up 0
    for (Delivery d : logbook) {
        if (d.grade == 'A') {
            gradeACount++;
        }
        if (d.kg > heaviest.kg) {
            heaviest = d;                  // keep the WHOLE record,
        }                                  // not just the number
    }

    cout << "=== Worked example ===\n";
    cout << "Grade A deliveries: " << gradeACount << "\n";
    cout << "Heaviest: " << heaviest.farmer << " with "
         << heaviest.kg << " kg\n\n";


    // =================================================================
    //  Q1  ·  THE WEIGHING SESSION          (see README)
    //  Uses: morningWeights
    // =================================================================

    cout << "=== Q1 ===\n";

double total=0;
    for(int i=0;i<12;i++){
    total=total+morningWeights[i];
}
cout<<"Total: "<<total<<endl;
double valid=0;
for(int a=0;a<12;a++){
    if(morningWeights[a]>0 && morningWeights[a]<81){
        valid=valid+1;
    }
}
cout<<"Valid: "<<valid<< " of 12 "<<endl;
double heaviestt=morningWeights[0];
int index=1;
for(int z=0;z<12;z++){
    if(morningWeights[z]>heaviestt){
        heaviestt=morningWeights[z];
        index=z;
    }
}
cout<<"Heaviest: "<< heaviestt<<" at position "<<index<<endl;

double finale=0;
double longest=0;
for(int s=0;s<12;s++){
    
    if(morningWeights[s]>0 && morningWeights[s]<81){
        longest=longest+1;
    }
    else {if(longest>finale){
        finale=longest;
    }
    longest=0;
    }
}
if(longest > finale) { 
    finale = longest; 
}
    cout<<"Longest valid run: "<<finale<<endl;



    cout << "\n";


    // =================================================================
    //  Q2  ·  GRADE SUMMARY                 (see README)
    //  Uses: logbook
    // =================================================================

    cout << "=== Q2 ===\n";



double manyA = 0, manyB = 0, manyC = 0;
double totalA = 0, totalB = 0, totalC = 0;

for (int i = 0; i < 11; i++) {
    if (logbook[i].grade == 'A') {
        manyA = manyA + 1;
        totalA = totalA + logbook[i].kg;
    } else if (logbook[i].grade == 'B') {
        manyB = manyB + 1;
        totalB = totalB + logbook[i].kg; 
    } else if (logbook[i].grade == 'C') { 
        manyC = manyC + 1;
        totalC = totalC + logbook[i].kg; 
    }
}



double averageA = (manyA > 0) ? totalA / manyA : 0;
double averageB = (manyB > 0) ? totalB / manyB : 0;
double averageC = (manyC > 0) ? totalC / manyC : 0;

cout << "Grade A: " << manyA << " deliveries" <<","<< totalA<< " total" <<","<< averageA << "kg Average" << endl;
cout << "Grade B: " << manyB << " deliveries" <<","<< totalB<< " total" <<","<< averageB << "kg Average" << endl;
cout << "Grade C: " << manyC << " deliveries" <<","<< totalC<< " total" <<","<< averageC << "kg Average" << endl;


double best = averageA;
char bestGrade = 'A';

if (averageB > best) {
    best = averageB;
    bestGrade = 'B';
}
if (averageC > best) {
    best = averageC;
    bestGrade = 'C';
}

cout << "Best average: grade " << bestGrade << endl;



    cout << "\n";


    // =================================================================
    //  Q3  ·  WHO IS WHO                    (see README)
    //  Uses: logbook, and the findFarmer function you write below main
    // =================================================================

    cout << "=== Q3 ===\n";

   

    cout << "findFarmer(Isanda) = " << findFarmer(logbook, "Isanda") << endl;
    cout << "findFarmer(Mukamana) = " << findFarmer(logbook, "Mukamana") << endl;

    string maxCountFarmer = "";
    int maxCount = 0;

    string maxWeightFarmer = "";
    double maxWeight = 0.0;

    for (int i = 0; i < 11; i++) {
        string currentFarmer = logbook[i].farmer;

        int currentCount = 0;
        double currentTotalWeight = 0.0;


        for (int j = 0; j < 11; j++) {
            if (logbook[j].farmer == currentFarmer) {
                currentCount = currentCount + 1;
                currentTotalWeight = currentTotalWeight + logbook[j].kg;
            }
        }

        if (currentCount > maxCount) {
            maxCount = currentCount;
            maxCountFarmer = currentFarmer;
        }

        if (currentTotalWeight > maxWeight) {
            maxWeight = currentTotalWeight;
            maxWeightFarmer = currentFarmer;
        }
    }

    cout << "Most deliveries: " << maxCountFarmer << " (" << maxCount << ")" << endl;
    cout << "Most kg: " << maxWeightFarmer << " (" << maxWeight << " kg)" << endl;

    cout << "\n";

  

    // =================================================================
    //  Q4  ·  PAYMENT RUN WITH A DAILY CAP  (see README)
    //  Uses: logbook, and the payment function you write below main
    // =================================================================

    cout << "=== Q4 ===\n";


    double totalPaidOut = 0.0;

    for (int i = 0; i < 11; i++) {
        string farmerName = logbook[i].farmer;
        double weight = logbook[i].kg;
        char grade = logbook[i].grade;

        
        double currentPayment = payment(weight, grade);

        
        bool isHalved = false;
        if (totalPaidOut > 100000.0) {
            currentPayment = currentPayment / 2.0;
            isHalved = true;
        }

    
        totalPaidOut = totalPaidOut + currentPayment;

    
        cout << farmerName << " " << weight << " kg grade " << grade << " -> " << currentPayment;
        if (isHalved) {
            cout << " (halved)";
        }
        cout << endl;
    }

    cout << "Total paid: " << totalPaidOut << endl;


    cout << "\n";


    // =================================================================
    //  Q5  ·  THE VALIDATION REPORT         (see README)
    //  Uses: rawRecords
    // =================================================================

    cout << "=== Q5 ===\n";



    int acceptedCount = 0;
    int rejectedCount = 0;

    for (int i = 0; i < 8; i++) {
        string id = rawRecords[i].id;
        string kgStr = rawRecords[i].kg;
        char grade = rawRecords[i].grade;

        bool isValid = true;
        string rejectReason = "";

    
        if (id.length() != 4 || id[0] != 'F') {
            isValid = false;
            rejectReason = "bad id";
        } else {
        
            if (!isdigit(id[1]) || !isdigit(id[2]) || !isdigit(id[3])) {
                isValid = false;
                rejectReason = "bad id";
            }
        }

  
        if (isValid) {
            if (kgStr == "") {
                isValid = false;
                rejectReason = "weight missing";
            } else {
            
                bool isNumeric = true;
                int dotCount = 0;
                for (size_t j = 0; j < kgStr.length(); j++) {
                    if (kgStr[j] == '.') {
                        dotCount++;
                    } else if (!isdigit(kgStr[j])) {
                        isNumeric = false;
                    }
                }

                if (!isNumeric || dotCount > 1) {
                    isValid = false;
                    rejectReason = "weight not a number";
                } else {
                    
                    double weightVal = stod(kgStr);
                    if (weightVal <= 0.0 || weightVal > 80.0) {
                        isValid = false;
                        rejectReason = "weight out of range";
                    }
                }
            }
        }

      
        if (isValid) {
            char upperGrade = toupper(grade);
            if (upperGrade != 'A' && upperGrade != 'B' && upperGrade != 'C') {
                isValid = false;
                rejectReason = "unknown grade";
            }
        }

     
        if (isValid) {
            cout << id << " ACCEPT" << endl;
            acceptedCount++;
        } else {
            cout << id << " REJECT - " << rejectReason << endl;
            rejectedCount++;
        }
    }

    cout << acceptedCount << " accepted, " << rejectedCount << " rejected" << endl;

    cout << "\n";


    cout << "=== Q6 ===\n";

   
       // =================================================================
    //  Q6  ·  IGISORO: A FULL TURN          (see README)
    //  Uses: board
    // =================================================================


        int currentPit = 6;
    int lapCount = 0;

    while (board[currentPit] > 0) {
        int seedsInHand = board[currentPit];
        board[currentPit] = 0;
        lapCount++;

        while (seedsInHand > 0) {
            currentPit = (currentPit % 16) + 1;
            board[currentPit] = board[currentPit] + 1;
            seedsInHand = seedsInHand - 1;
        }

        if (board[currentPit] == 1) {
            break;
        }
    }

    cout << "Final board: ";
    printBoard(board);
    cout << "Landed in pit " << currentPit << " after " << lapCount << " laps" << endl;

    cout << "\n";



    
    // =================================================================
    //  STRETCH  ·  optional
    // =================================================================

    // =================================================================
    //  Q7  ·  SORT THE LOGBOOK              (see README)
    //  Uses: logbook
    // =================================================================

    // cout << "=== Q7 ===\n";





    // =================================================================
    //  Q8  ·  SPOTTING DOUBLE-ENTRIES       (see README)
    //  Uses: logbook
    // =================================================================

    // cout << "=== Q8 ===\n";





    return 0;

}

int findFarmer(const vector<Delivery> &log, string name) {
    for (int i = 0; i < 11; i++) {
        if (log[i].farmer == name) {
            return i; 
        }
    }
    return -1; 
}


// =====================================================================
//  FUNCTIONS YOU WRITE
//
//  C++ reads a file top to bottom, so a function must be DECLARED above
//  the place that calls it. These two are declared here at the bottom,
//  which main() cannot see — so move them ABOVE main(), or leave a
//  one-line declaration up there. Working that out is part of Q3.
// =====================================================================

// Q3:  return the position of the first delivery by this farmer,
//      or -1 if the farmer is not in the log at all.
//
// int findFarmer(const vector<Delivery> &log, string name) {
//
// }

// The real code for the Q4 payment rule goes here at the bottom of the file
double payment(double kg, char grade) {
    double baseRate = 450.0;
    double amount = kg * baseRate;

    if (grade == 'A') {
        amount = amount * 1.10; // 10% bonus
    } 
    else if (grade == 'B') {
        // Stays standard rate
    } 
    else {
        amount = amount * 0.80; // 20% penalty for anything else (like C)
    }

    return amount;
}


// Q4:  what one delivery earns, before any cap is applied.
//      Grade A pays 10% above the rate, B pays the rate,
//      anything else pays 20% below it. The rate is 450.
//
// double payment(double kg, char grade) {
//
// }
